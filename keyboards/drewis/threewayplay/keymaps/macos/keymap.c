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
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

#define _______ KC_TRNS
#define RAISE MO(1)
#define LOWER MO(2)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_MIN RCTL_T(KC_MINS)
#define C_Z LGUI(KC_Z)
#define C_X LGUI(KC_X)
#define C_C LGUI(KC_C)
#define C_V LGUI(KC_V)
#define C_A LGUI(KC_A)
#define SPOTLIT LGUI(KC_SPC)
#define SCRSHT LGUI(LSFT(KC_4))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |EscCtl|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  | - Ctl|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS | Del  | Alt  | GUI  |Raise |Space |Enter |Lower | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[0] = LAYOUT( /* Base */
		KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,  KC_F,   KC_G,   KC_C,   KC_R,  KC_L,   KC_BSPC,
		CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,  KC_D,   KC_H,   KC_T,   KC_N,  KC_S,   CTL_MIN,
		KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,  KC_B,   KC_M,   KC_W,   KC_V,  KC_Z,   KC_RSFT,
	        KC_CAPS, KC_DEL,  KC_LALT, KC_LGUI, RAISE,   KC_SPC,KC_ENT,LOWER,   KC_LEFT,KC_DOWN,KC_UP, KC_RIGHT),
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
[1] = LAYOUT( /* L1 */
		KC_GRV ,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, _______,
		_______,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,  KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_PIPE,
		_______,C_Z,    C_X,    C_C,    C_V,    C_A,   KC_PLUS,KC_EQL, KC_RABK,KC_LBRC,KC_RBRC,_______,
		_______,_______,_______,_______,_______,_______,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F11 |  F12 |  F13 | F14  |  F15 |             |  F16 |  F17 | F18  |   ?  |  /   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[2] = LAYOUT( /* L2 */
		KC_TILD,KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_QUES,KC_SLSH,_______,
		_______,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSLS,
		_______,_______,_______,_______,_______,_______,KC_EXLM,KC_EQL, KC_LABK,KC_LCBR,KC_RCBR,_______,
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______),
[3] = LAYOUT( /* L3 */
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
		_______,_______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,_______,
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______),
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
