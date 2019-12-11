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

#define _______ KC_TRNS
#define RAISE MO(1)
#define LOWER MO(2)
#define FUNC1 MO(3)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_MIN RCTL_T(KC_MINS)
#define C_Z LCTL(KC_Z)
#define C_X LCTL(KC_X)
#define C_C LCTL(KC_C)
#define C_V LCTL(KC_V)
#define C_A LCTL(KC_A)
#define SPOTLIT LGUI(KC_SPC)
#define SCRSHT LGUI(LSFT(KC_4))
#define LKSCR LCTL(LALT(KC_L))

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

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
		KC_NO,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                                        KC_F,   KC_G,    KC_C,    KC_R,   KC_L,    LKSCR,
		KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                                        KC_D,   KC_H,    KC_T,    KC_N,   KC_S,    KC_BSPC,
		CTL_ESC, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    FUNC1,   KC_ENT,  KC_NO,   KC_NO,   KC_B,   KC_M,    KC_W,    KC_V,   KC_Z,    KC_MINS,
	        KC_LSFT, KC_DEL,  KC_LALT, KC_LGUI, KC_NO,   KC_SPC,  RAISE,   KC_LSFT, KC_RSFT, LOWER,   KC_ENT, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT,KC_RSFT),
/*
 * Raise
 */
[1] = LAYOUT( /* L1 */
		_______,_______,_______,_______,_______,_______,                                _______,KC_RBRC,KC_LBRC,_______,KC_SLSH,_______,
		KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,
		_______,C_Z,    C_X,    C_C,    C_V,    C_A,    _______,_______,_______,_______,KC_PLUS,KC_EQL, _______,KC_LBRC,KC_RBRC,KC_PIPE,
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END,_______),
/*
 * Lower
 */
[2] = LAYOUT( /* L2 */
		_______,_______,_______,_______,_______,_______,                                _______,KC_RCBR,KC_LCBR,_______,KC_SLSH,_______,
		KC_TILD,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,                                KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,_______,
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_EXLM,KC_EQL, _______,KC_LCBR,KC_RCBR,KC_BSLS,
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END,_______),
/*
 * Lower
 */
[3] = LAYOUT( /* L3 */
		_______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5  ,		                KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, _______,
		_______,_______,_______,_______,_______,_______,                                _______,_______,_______,_______,_______,_______,
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______),
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
