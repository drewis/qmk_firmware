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
#include "drewis_key19.h"

#define _____ KC_TRNS
#define +++++ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_double( /* Base */
  KC_QUOT, KC_COMM, KC_DOT,  KC_P  , KC_Y  , KC_F  , KC_G  , KC_C  , KC_R  , KC_L  ,
  KC_A,    KC_O,    KC_E,    KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,   KC_S,
  KC_SCLN, KC_Q,    KC_J,    KC_K,   KC_X,   KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,
  KC_LSFT,   KC_LCTRL,   MO(1),    KC_SPC,      KC_ENT, MO(1),  KC_RCTRL,  KC_RSFT
  ),
[1] = LAYOUT_double(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,
  KC_TAB,  KC_GRV,  _____,   _____,   _____,   _____,   KC_SLSH, KC_LBRC,  KC_RBRC, KC_BSPC,
  KC_ESC, _____,   _____,   _____,   _____,   _____,    KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT,
  _____, _____,   _____,   _____, _____, _____, _____, _____
		),
[2] = LAYOUT_double(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,   KC_9,    KC_0,
  KC_TAB, _____,   _____,   _____,   _____,   _____,   _____,   _____,  _____,   _____,
  KC_TAB, _____,   _____,   _____,   _____,   _____,   _____,   _____,  _____,   _____,
  _____, _____,   _____,   _____,   _____,   _____,   _____,   _____
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
