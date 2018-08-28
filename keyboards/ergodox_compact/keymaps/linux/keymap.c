/* Copyright 2017 Andrew Sutherland (dr3wsuth3rland@gmail.com)
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
#include "ergodox_compact.h"

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = KEYMAP( /* Base */
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,  KC_0,    KC_BSLS,
		KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                   KC_F,    KC_G,    KC_C,    KC_R,  KC_L,    KC_SLSH,
		KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                   KC_D,    KC_H,    KC_T,    KC_N,  KC_S,    KC_MINS,
		KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   KC_ESC, KC_NO,  KC_B,    KC_M,    KC_W,    KC_V,  KC_Z,    KC_RSFT,
		KC_CAPS, KC_NO,   OSL(2),  KC_LALT, KC_LGUI, KC_SPC, OSL(1), KC_ENT, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_RCTL),
[1] = KEYMAP( /* L1 */
		_______,KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,                  _______,_______,_______,_______,_______,_______,
		_______,KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,                 _______,KC_PLUS,KC_LBRC,KC_RBRC,_______,_______,
		_______,KC_F11,    KC_F12,    KC_F13,    KC_F14,    KC_F15,                 _______,KC_EQL, KC_LCBR,KC_RCBR,_______,_______,
		_______,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),_______,_______,_______,_______,KC_EXLM,KC_LPRN,KC_RPRN,_______,_______,
		_______,_______,   _______,   _______,   _______,   _______,_______,_______,KC_DEL, KC_HOME,KC_PGDN,KC_PGUP,KC_END, _______),
[2] = KEYMAP ( /* L2 */
		_______,_______,_______,_______,_______,_______,                _______,KC_NO,  KC_SLSH,KC_ASTR,KC_MINS,_______,
		_______,_______,_______,_______,_______,_______,                _______,KC_7,   KC_8,   KC_9,   KC_PLUS,_______,
		_______,_______,_______,_______,_______,_______,                _______,KC_4,   KC_5,   KC_6,   KC_NO,  _______,
		_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_1,   KC_2,   KC_3,   KC_NO,  _______,
		_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_0,   KC_NO,  KC_DOT, KC_NO,  _______),
[3] = KEYMAP ( /* L3 */
		_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
		_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
		_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______),
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
