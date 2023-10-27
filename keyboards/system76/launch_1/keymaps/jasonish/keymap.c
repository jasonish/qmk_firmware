/*
 *  Copyright (C) 2021  System76
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#define ______ KC_TRNS

// Left-hand home row mods
#define _A LGUI_T(KC_A)
#define _S LALT_T(KC_S)
#define _D LSFT_T(KC_D)
#define _F LCTL_T(KC_F)

// Right-hand home row mods
#define _J RCTL_T(KC_J)
#define _K RSFT_T(KC_K)
#define _L LALT_T(KC_L)
#define _SCLN LGUI_T(KC_SCLN)

#define NAV_SPC LT(1, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     /**/  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,   KC_HOME,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      /**/  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      /**/  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  KC_PGDN,
    KC_LCTL, _A,      _S,      _D,      _F,      KC_G,      /**/  KC_H,    _J,      _K,      _L,      _SCLN,   KC_QUOT, KC_ENT,            KC_END,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      /**/  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,
             KC_LCTL, MO(1)  , KC_LALT, KC_LGUI, NAV_SPC,   /**/           KC_SPC,  KC_RCTL, KC_RALT, MO(1),            KC_LEFT, KC_DOWN,  KC_RGHT
  ),

  [1] = LAYOUT(
    QK_BOOT, _______, _______, _______, _______, _______,   /**/ _______, _______, _______, _______, _______, _______, KC_PSCR, KC_INS ,  KC_MPLY,
    _______, _______, _______, _______, _______, _______,   /**/ _______, _______, _______, _______, _______, _______, _______, KC_UNDO,  KC_VOLU,
    _______, _______, _______, _______, _______, _______,   /**/ RGB_TOG, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______,  KC_VOLD,
    _______, _______, _______, _______, _______, _______,   /**/ KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______, _______,           KC_MUTE,
    _______, _______, _______, _______, _______, _______,   /**/ KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,          _______,
             _______, _______, _______, _______, _______,   /**/          _______, _______, _______, _______,          _______, _______, _______
  ),
};

#include "achordion.h"

void bootmagic_lite_reset_eeprom(void);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QK_BOOT:
	// Override the Launch keyboard default action which doesn't
	// allow QMK flashing.
	bootmagic_lite_reset_eeprom();
	bootloader_jump();
	return false;
    default:
	break;
    }
    if (!process_achordion(keycode, record)) {
	return false;
    }

    return true;
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
#if 0
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand in Dvorak.
  switch (tap_hold_keycode) {
    case HOME_A:  // A + U.
      if (other_keycode == HOME_U) { return true; }
      break;

    case HOME_S:  // S + H and S + G.
      if (other_keycode == HOME_H || other_keycode == KC_G) { return true; }
      break;
  }

#endif

  // Achordion picks up H as being on the same side as A, so fix this
  // case.
  if (tap_hold_keycode == _A && other_keycode == KC_H) {
      return true;
  }

  // Allow NAV_SPC to work on all sides.
  if (tap_hold_keycode == NAV_SPC) {
      return true;
  }


  // This from the Achordion docs.
  if (other_record->event.key.row % (MATRIX_ROWS) >= 4) { return true; }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

#if 0
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    case HOME_N:
    // Repeating is useful for Vim navigation keys.
    case QHOME_J:
    case QHOME_K:
    case QHOME_L:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}
#endif
