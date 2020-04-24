#pragma once

void tca9555_init(void);
bool tca9555_read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row);

//pins
#define P00 0
#define P01 1
#define P02 2 
#define P03 3
#define P04 4 
#define P05 5 
#define P06 6 
#define P07 7 
#define P10 10
#define P11 11
#define P12 12
#define P13 13
#define P14 14
#define P15 15
#define P16 16
#define P17 17

//commands
#define CMD_IN_P0  0x00
#define CMD_IN_P1  0x01
#define CMD_OUT_P0 0x02
#define CMD_OUT_P1 0x03
//
#define CMD_CFG_P0 0x06
#define CMD_CFG_P1 0x07
