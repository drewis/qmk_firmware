/*
Copyright 2019 Andrew Sutherland (dr3wsuth3rland@gmail.com)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdbool.h>
#include "util.h"
#include "matrix.h"
#include "config.h"
#include "quantum.h"
#include "i2c_master.h"
#include "tca9555.h"

/*
 * Things that would have been nice to know when i started.
 * - Cannot chain commands, all commands must be followed by stop bit before
 *   sending next command.
 * - Register read/writes alternate between Port 0 and Port 1, e.g when reading
 *   with command CMD_IN_P0, fist byte read is Port0 second byte is Port1.
 *   This also applies to write-then-read operations, if you write CMD_OUT_P0 then
 *   try to read without stop+new command, the byte you get back will be Port 1 status.
 */

/*
 * Warning: driver requires rows on Port0 and cols on Port1, port pins do not need
 * 	    to match col/row order.
 */

//shifted per i2c_master.c
#define I2C_ADDR (0x27 << 1)
//no clue what the units are on this
#define TCA_TIMEOUT 10

typedef uint8_t tca_pin;

#define ARRAY_SIZE(array) \
    (sizeof(array) / sizeof(array[0]))
//No clue if this helps but tight loop so why not.
#define unlikely(x)     __builtin_expect((x),0)

//TODO define in config.h
#define MATRIX_ROW_SLAVE_PINS { P00, P01, P02, P03 }
#define MATRIX_COL_SLAVE_PINS { P16, P15, P14, P13, P12, P11, P10 }
//#define MATRIX_COL_SLAVE_PINS { P10, P11, P12, P13, P14, P15, P16 }

//#define TCA_DEBUG

static tca_pin row_pins[ROWS_PER_HAND] = MATRIX_ROW_SLAVE_PINS;
static tca_pin col_pins[MATRIX_COLS] = MATRIX_COL_SLAVE_PINS;

static i2c_status_t read_cols(uint8_t *state) {
	const uint8_t data[] = {
		CMD_IN_P1,
	};
	i2c_status_t ret = i2c_transmit(I2C_ADDR, data, ARRAY_SIZE(data), TCA_TIMEOUT);
	ret |= i2c_receive(I2C_ADDR, state, 1, TCA_TIMEOUT);
	i2c_stop();
#ifdef TCA_DEBUG
	printf("read_cols(): 0x%02x\n", *state);
#endif
	return ret;
}

static i2c_status_t select_row(uint8_t row) {
	tca_pin port = 0xFF & ~(ROW_SHIFTER << row_pins[row]);
	const uint8_t data[] = {
		CMD_CFG_P0,
		port, //set output
	};
	const uint8_t data2[] = {
		CMD_OUT_P0,
		port, //pull low
	};

	i2c_status_t ret = i2c_transmit(I2C_ADDR, data, ARRAY_SIZE(data), TCA_TIMEOUT);
	//i2c_receive (I2C_ADDR, data, ARRAY_SIZE(data), TCA_TIMEOUT);
	i2c_stop();
	//printf("select_row(1): set=0x%02x rec=0x%02x,0x%02x\n", port, data[0], data[1]);

	ret |= i2c_transmit(I2C_ADDR, data2, ARRAY_SIZE(data2), TCA_TIMEOUT);
	//i2c_receive (I2C_ADDR, data2, ARRAY_SIZE(data2), TCA_TIMEOUT);
	i2c_stop();
	//printf("select_row(2): set=0x%02x rec=0x%02x,0x%02x\n", port, data2[0], data2[1]);

	return ret;
}

static i2c_status_t unselect_row(uint8_t _unused) {
	const uint8_t data[] = {
		CMD_CFG_P0,
		0xFF, //set input
	};
	i2c_status_t ret = i2c_transmit(I2C_ADDR, data, ARRAY_SIZE(data), TCA_TIMEOUT);
	i2c_stop();
	return ret;
}

volatile static bool is_disconnected = false;

void tca9555_init(void) {
#ifdef TCA_DEBUG
	print("TCA9555: i2c_init()\n");
#endif
	const uint8_t data[] = {
		CMD_CFG_P0,
		0xFF, //port0 input
		0xFF, //port1 input
	};
	is_disconnected = false;

	i2c_init();
	i2c_status_t ret = i2c_transmit(I2C_ADDR, data, ARRAY_SIZE(data), TCA_TIMEOUT);
	i2c_stop();
	if (ret) {
		is_disconnected = true;
		print("TCA9555: disconnected\n");
	}
}

bool tca9555_read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {

	// Store last value of row prior to reading
	matrix_row_t last_row_value = current_matrix[current_row];

	// Clear data in matrix row
	current_matrix[current_row] = 0;

	if (unlikely(is_disconnected)) {
		tca9555_init();
	}
	if (unlikely(is_disconnected)) {
		goto read_err;
	}

	// Select row and wait for row selecton to stabilize
	if (unlikely(select_row(current_row))) {
		goto read_err;
	}
	wait_us(100);

	uint8_t pin_state;
	if (unlikely(read_cols(&pin_state))) {
		goto read_err;
	}

	// For each col...
	for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
		// Select the col pin to read (active low)
		uint8_t col_mask = (ROW_SHIFTER << (col_pins[col_index] - P10));
		if (!(pin_state & col_mask)) {
			// Populate the matrix row with the state of the col pin
			current_matrix[current_row] |= (ROW_SHIFTER << col_index);
		}
	}

	// Unselect row
	if (unlikely(unselect_row(current_row))) {
		goto read_err;
	}

	return (last_row_value != current_matrix[current_row]);
read_err:
	is_disconnected = true;
	print("TCA9555: read error\n");
	return false; //(last_row_value != current_matrix[current_row]);
}
