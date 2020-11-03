/*
Copyright 2012-2019 Jun Wako, Jack Humbert, Yiancar, Andrew Sutherland

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

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include "wait.h"
#include "util.h"
#include "matrix.h"
#include "config.h"
#include "quantum.h"
#include "debounce.h"
#include "tca9555.h"

//#define ONEHANDED

//#define MATRIX_HEARTBEAT

static pin_t row_pins[ROWS_PER_HAND] = MATRIX_ROW_MASTER_PINS;
static pin_t col_pins[MATRIX_COLS] = MATRIX_COL_MASTER_PINS;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t raw_matrix[MATRIX_ROWS];

// helper functions

inline uint8_t matrix_rows(void) { return MATRIX_ROWS; }

inline uint8_t matrix_cols(void) { return MATRIX_COLS; }

bool matrix_is_modified(void) {
    if (debounce_active()) return false;
    return true;
}

inline bool matrix_is_on(uint8_t row, uint8_t col) {
	return (matrix[row] & ((matrix_row_t)1 << col));
}

inline matrix_row_t matrix_get_row(uint8_t row) { return matrix[row]; }

void matrix_print(void) {
    print_matrix_header();

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row);
        print(": ");
        print_matrix_row(row);
        print("\n");
    }
}

uint8_t matrix_key_count(void) {
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += matrix_bitpop(i);
    }
    return count;
}

// matrix code
//#if (DIODE_DIRECTION == COL2ROW)

static void select_row(uint8_t row) {
    setPinOutput(row_pins[row]);
    writePinLow(row_pins[row]);
}

static void unselect_row(uint8_t row) {
	setPinInputHigh(row_pins[row]);
}

static void unselect_rows(void) {
    for (uint8_t x = 0; x < ROWS_PER_HAND; x++) {
        setPinInputHigh(row_pins[x]);
    }
}

static void init_pins(void) {
    unselect_rows();
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        setPinInputHigh(col_pins[x]);
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Store last value of row prior to reading
    matrix_row_t last_row_value = current_matrix[current_row];

    // Clear data in matrix row
    current_matrix[current_row] = 0;

    // Select row and wait for row selecton to stabilize
    select_row(current_row);
    wait_us(30);

    // For each col...
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
	// Select the col pin to read (active low)
	uint8_t pin_state = readPin(col_pins[col_index]);
        // Populate the matrix row with the state of the col pin
        current_matrix[current_row] |= pin_state ? 0 : (ROW_SHIFTER << col_index);
    }

    // Unselect row
    unselect_row(current_row);

    return (last_row_value != current_matrix[current_row]);
}

//#endif

void matrix_init(void) {
    //debug_enable = true;
    //debug_matrix = true;


    // initialize key pins
    init_pins();
#ifndef ONEHANDED
    tca9555_init();
#endif

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
	raw_matrix[i] = 0;
    }

    debounce_init(MATRIX_ROWS);

    matrix_init_quantum();
}

uint16_t heartbeat = 0;

uint8_t matrix_scan(void) {
    bool changed = false;
    uint8_t current_row;

    // Set row, read cols
    for (current_row = 0; current_row < ROWS_PER_HAND; current_row++) {
        changed |= read_cols_on_row(raw_matrix, current_row);
    }

#ifndef ONEHANDED
    for (current_row = 0; current_row < ROWS_PER_HAND; current_row++) {
        changed |= tca9555_read_cols_on_row(raw_matrix + ROWS_PER_HAND, current_row);
    }
#endif

    debounce(raw_matrix, matrix, MATRIX_ROWS, changed);

#ifdef MATRIX_HEARTBEAT
    if (((heartbeat++) % 2000) == 0) {
	    print("Heartbeat\n");
	    //matrix_print();
    }
#endif

    matrix_scan_quantum();
    return (uint8_t) changed;
}
