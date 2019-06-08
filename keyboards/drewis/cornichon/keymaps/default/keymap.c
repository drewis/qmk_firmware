/* Copyright 2018 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "cornichon.h"

#define _____ KC_TRNS
#define C_C LCTL(KC_C)
#define C_V LCTL(KC_V)
#define C_X LCTL(KC_X)
#define C_Z LCTL(KC_Z)
#define C_A LCTL(KC_A)
#define MIN_CTL RCTL_T(KC_MINS)
#define ESC_CTL LCTL_T(KC_ESC)
#define BSLS_CTL RCTL_T(KC_BSLS)
#define PIPE_CTL RCTL_T(KC_PIPE)
#define DEL_ALT LALT_T(KC_DEL)
#define BAK_ALT RALT_T(KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* DVORAK
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+-------------+------+------+------+------+
 * |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------|------+------+------+------+------+
 * |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+
 * |ESCCTL|ALT   |SHIFT |RAISE |SPACE |ENTER |LOWER |SHIFT |ALT   | - CTL|
 * `---------------------------------------------------------------------'
 */

[0] = LAYOUT( /* Base */
//  KC_QUOT, KC_COMM, KC_DOT,  KC_P  , KC_Y  , KC_F  , KC_G  , KC_C  , KC_R  , KC_L  ,
//  KC_A,    KC_O,    KC_E,    KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,   KC_S,
//  KC_SCLN, KC_Q,    KC_J,    KC_K,   KC_X,   KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,
//  ESC_CTL, DEL_ALT, KC_LSFT, MO(1),  KC_SPC, KC_ENT, MO(2),  KC_RSFT,BAK_ALT,MIN_CTL
  ESC_CTL, KC_COMM, KC_DOT,  KC_P  , KC_Y  , KC_F  , KC_G  , KC_C  , KC_R  , KC_BSPC  ,
  KC_QUOT, KC_O,    KC_E,    KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,   KC_L,
  KC_A,    KC_Q,    KC_J,    KC_K,   KC_X,   KC_B,   KC_M,   KC_W,   KC_V,   KC_S,
  KC_SCLN, DEL_ALT, KC_SPC,  MO(1),  KC_LSFT,KC_RSFT,MO(2),  KC_ENT, MIN_CTL,KC_Z
  ),
/* Raise
 * ,---------------------------------------------------------------------.
 * |   `  |      |      |      |      |      |   [  |   ]  |   =  |   ?  |
 * |------+------+------+------+-------------+------+------+------+------+
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|------+------+------+------+------+
 * |  CZ  |  CX  |  CC  |  CV  |  CA  |      |LEFT  |DOWN  |  UP  |RIGHT |
 * |------+------+------+------+------+------+------+------+------+------+
 * |      |      |      |      | BACK | TAB  |      |      |      |  |   |
 * `---------------------------------------------------------------------'
 */
[1] = LAYOUT(
  KC_GRV,  RGB_M_P, RGB_M_SW,RGB_TOG, _____,   _____,   KC_LBRC, KC_RBRC, KC_EQL, KC_QUES,
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,   KC_9,    KC_0,
  C_Z,     C_X,     C_C,     C_V,     C_A,     _____,   KC_LEFT, KC_DOWN,KC_UP,   KC_RIGHT,
  _____, _____,   _____,     _____,   KC_TAB,  _____, _____,  _____, _____,       BSLS_CTL
		),
/* LOWER
 * ,---------------------------------------------------------------------.
 * |   ~  |      |      |      |      |      |   {  |   }  |   +  |   /  |
 * |------+------+------+------+-------------+------+------+------+------+
 * |   !  |   @  |   @  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|------+------+------+------+------+
 * |  CZ  |  CX  |  CC  |  CV  |  CA  |      |LEFT  |DOWN  |  UP  |RIGHT |
 * |------+------+------+------+------+------+------+------+------+------+
 * |      |      |      |      | BACK | TAB  |      |      |      |  \   |
 * `---------------------------------------------------------------------'
 */
[2] = LAYOUT(
  KC_TILD, RGB_M_P, RGB_M_SW,RGB_TOG, _____,   _____,   KC_LCBR, KC_RCBR,KC_PLUS, KC_SLSH,
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,KC_LPRN, KC_RPRN,
  C_Z,     C_X,     C_C,     C_V,     C_A,     _____,   KC_LEFT, KC_DOWN,KC_UP,   KC_RIGHT,
  _____, _____,   _____,     _____,   KC_TAB,  _____,  _____,   _____, _____,     PIPE_CTL
		)
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}

void encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 0) {
		tap_code(KC_PGDN);
	}
}
