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
/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[0] = KEYMAP( /* Base */
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                 KC_NO  ,KC_NO  ,KC_NO  ,KC_NO ,KC_NO  ,KC_NO  ,
		KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                    KC_F,   KC_G,   KC_C,   KC_R,  KC_L,   KC_BSPC,
		LCTL_T(KC_ESC),
		         KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                    KC_D,   KC_H,   KC_T,   KC_N,  KC_S,   RCTL_T(KC_MINS),
		KC_LSPO, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, OSL(2), OSL(1),    KC_B,   KC_M,   KC_W,   KC_V,  KC_Z,   KC_RSPC,
		KC_CAPS, KC_NO, KC_SLSH,  KC_LALT, KC_LGUI, MO(1),KC_SPC, KC_ENT,    MO(2),  KC_LEFT,KC_DOWN,KC_UP, KC_RGHT,KC_DEL),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[1] = KEYMAP( /* L1 */
		_______,_______,   _______,   _______,   _______,   _______,                   _______,_______,_______,_______,_______,_______,
		KC_GRV ,KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC,
		_______,KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,                     _______,KC_PLUS,KC_LCBR,KC_RCBR,_______,KC_PIPE,
		_______,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),LCTL(KC_A),_______,_______,_______,KC_EQL, KC_LBRC,KC_RBRC,_______,_______,
		_______,_______,   _______,   _______,   _______,   _______,   _______,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END, _______),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[2] = KEYMAP ( /* L2 */
		_______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
		KC_TILD,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,                KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSPC,
		_______,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,                 _______,KC_EXLM,KC_LCBR,KC_RCBR,_______,KC_BSLS,
		_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_EQL ,KC_LBRC,KC_RBRC,_______,_______,
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______),
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
