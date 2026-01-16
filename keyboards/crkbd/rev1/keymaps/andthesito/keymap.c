/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

enum crkbd_layers {
    _QWERTY,
    _NUMEROS,
    _SIMBOLOS,
    _MOVIMIENTO,
    _RATON,
    _FUNCT,
    _MEDIA,
    _ADJUST
};

enum custom_keycodes {
    TEAMS_CODE_WORD = SAFE_RANGE,
    TEAMS_CODE_BLOCK
};


#include "efectos_rgb.c"
#include "pantalla_oled.c"
// Tap Dance declarations
enum {
    TD_EXLM_IEXL,
	TD_QUES_IQUE,
    TD_DQUOT_QUOT
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_EXLM_IEXL] = ACTION_TAP_DANCE_DOUBLE(ES_EXLM, ES_IEXL),
    [TD_QUES_IQUE] = ACTION_TAP_DANCE_DOUBLE(ES_QUES, ES_IQUE),
    [TD_DQUOT_QUOT] = ACTION_TAP_DANCE_DOUBLE(ES_DQUO, ES_QUOT),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case TEAMS_CODE_BLOCK:
			if (record->event.pressed) {
				switch (detected_host_os()) {
					case OS_MACOS:
							// macOS: Cmd+Alt+Shift+B
						tap_code16(LSFT(LALT(LGUI(KC_B))));
						break;
					case OS_WINDOWS:
					case OS_LINUX:
					default:
						// Win/Linux: Ctrl+Alt+Shift+B
						tap_code16(LSFT(LALT(LCTL(KC_B))));
						break;
				}
			}
			return false;
		case TEAMS_CODE_WORD:
			if (record->event.pressed) {
				switch (detected_host_os()) {
					case OS_MACOS:
						// macOS: Cmd+Alt+Shift+C
						tap_code16(LSFT(LALT(LGUI(KC_C))));
						break;
					case OS_WINDOWS:
					case OS_LINUX:
					default:
						// Win/Linux: Ctrl+Alt+Shift+C
						tap_code16(LSFT(LALT(LCTL(KC_C))));
						break;
				}
			}
			return false;
		case KC_COPY:
			if (record->event.pressed) {
				switch (detected_host_os()) {
					case OS_MACOS:
						tap_code16(LGUI(KC_C));   // Cmd+C
						break;
					case OS_WINDOWS:
					case OS_LINUX:
					default:
						tap_code16(LCTL(KC_INS)); // Ctrl+Insert (universal copy)
						break;
				}
			}
			return false;
		case KC_PASTE:
			if (record->event.pressed) {
				switch (detected_host_os()) {
					case OS_MACOS:
						tap_code16(LGUI(KC_V));    // Cmd+V
						break;
					case OS_WINDOWS:
					case OS_LINUX:
					default:
						tap_code16(LSFT(KC_INS));   // Shift+Insert (universal paste)
						break;
				}
			}
			return false;
		case KC_CUT:
			if (record->event.pressed) {
				switch (detected_host_os()) {
					case OS_MACOS:
						tap_code16(LGUI(KC_X));     // Cmd+X
						break;
					case OS_WINDOWS:
					case OS_LINUX:
					default:
						tap_code16(LSFT(KC_DEL));   // Shift+Delete (universal cut)
						break;
				}
			}
			return false;
		case KC_UNDO:
			if (record->event.pressed) {
				switch (detected_host_os()) {
					case OS_MACOS:   tap_code16(LGUI(KC_Z)); break;
					case OS_WINDOWS:
					case OS_LINUX:
					default:         tap_code16(LCTL(KC_Z)); break;
				}
			}
			return false;
		case KC_AGAIN:
			if (record->event.pressed) {
				switch (detected_host_os()) {
					case OS_MACOS:   tap_code16(LSFT(LGUI(KC_Z))); break; // Shift+Cmd+Z
					case OS_WINDOWS:
					case OS_LINUX:
					default:         tap_code16(LCTL(KC_Y)); break;
				}
			}
			return false;
        case ES_MORD:
            if (detected_host_os() == OS_MACOS) {
                if (record->event.pressed) {
                    register_code16(ES_MAC_MORD);
                } else {
                    unregister_code16(ES_MAC_MORD);
                }
                return false; // Skip all further processing of this key
            }
        case ES_LABK:
            if (detected_host_os() == OS_MACOS) {
                if (record->event.pressed) {
                    register_code16(ES_MAC_LABK);
                } else {
                    unregister_code16(ES_MAC_LABK);
                }
                return false; // Skip all further processing of this key
            }
        case ES_RABK:
            if (detected_host_os() == OS_MACOS) {
                if (record->event.pressed) {
                    register_code16(ES_MAC_RABK);
                } else {
                    unregister_code16(ES_MAC_RABK);
                }
                return false; // Skip all further processing of this key
            }
        case ES_TILD:
            if (detected_host_os() == OS_MACOS) {
                if (record->event.pressed) {
                    register_code16(ES_MAC_TILD);
                } else {
                    unregister_code16(ES_MAC_TILD);
                }
                return false; // Skip all further processing of this key
            }
        case ES_BSLS:
            if (detected_host_os() == OS_MACOS) {
                if (record->event.pressed) {
                    register_code16(ES_MAC_BSLS);
                } else {
                    unregister_code16(ES_MAC_BSLS);
                }
                return false; // Skip all further processing of this key
            }
        default:
            return true; // Process all other keycodes normally
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*[_EJEMPLO] = LAYOUT_split_3x6_3(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                _______, _______,  _______,         XXXXXXX, XXXXXXX, XXXXXXX
  ),*/
    [_QWERTY] = LAYOUT_split_3x6_3(
    ES_MORD,         ES_Q,         ES_W,         ES_E,         ES_R,         ES_T,          ES_Y,    ES_U,          ES_I,         ES_O,         ES_P,            KC_BSPC,
    LSFT_T(KC_CAPS), LALT_T(ES_A), LGUI_T(ES_S), RCTL_T(ES_D), RSFT_T(ES_F), ES_G,          ES_H,    RSFT_T(ES_J),  RCTL_T(ES_K), LGUI_T(ES_L), LALT_T(ES_NTIL), RSFT_T(ES_ACUT),
    ES_LABK,         ES_Z,         ES_X,         ES_C,         ES_V,         ES_B,          ES_N,    ES_M,          ES_COMM,      ES_DOT,       ES_MINS,         ES_TILD,
                   LT(_RATON,KC_DEL), LT(_NUMEROS,KC_TAB), LT(_MOVIMIENTO,KC_ESC),          LT(_FUNCT,KC_ENT), LT(_SIMBOLOS,KC_SPC), LT(_MEDIA,KC_BSPC)
  ),
    [_NUMEROS] = LAYOUT_split_3x6_3(
    _______,       ES_1,          ES_2,          ES_3,          ES_4,          ES_5,            ES_6,    ES_7, ES_8, ES_9, ES_0,    _______,
    OSM(MOD_RALT), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LCTL), OSM(MOD_LSFT), _______,         ES_ASTR, ES_4, ES_5, ES_6, ES_SLSH, XXXXXXX,
     _______,      XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,         ES_PLUS, ES_1, ES_2, ES_3, ES_MINS, _______,
                                                 _______,       _______,       _______,         KC_ENT,  ES_0, ES_DOT
  ),
    [_SIMBOLOS] = LAYOUT_split_3x6_3(
    KC_BSLS, TD(TD_EXLM_IEXL), TD(TD_DQUOT_QUOT), ES_BULT,          ES_DLR,  ES_PERC,                 ES_AMPR, ES_SLSH, ES_LPRN, ES_RPRN, ES_EQL,  TD(TD_QUES_IQUE),
    ES_BSLS, ES_PIPE,          ES_AT,             ES_HASH,          ES_TILD, ES_EURO,                 ES_IQUE, ES_LCBR, ES_RCBR, ES_CIRC, ES_QUOT, ES_GRV,
    ES_LABK, ES_RABK,          XXXXXXX,           TEAMS_CODE_WORD,  XXXXXXX, TEAMS_CODE_BLOCK,        ES_NOT,  ES_LBRC, ES_RBRC, _______, _______, _______,
                                                                   _______, _______,  _______,        XXXXXXX, XXXXXXX, XXXXXXX
  ),
    [_MOVIMIENTO] = LAYOUT_split_3x6_3(
    _______,       KC_UNDO,       KC_CUT,        KC_COPY,       KC_PASTE,      KC_AGAIN,        KC_AGAIN, KC_PASTE, KC_COPY, KC_CUT,   KC_UNDO, _______, 
    OSM(MOD_RALT), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LCTL), OSM(MOD_LSFT), _______,         KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT, _______, _______,
    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,         KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,   _______, _______,
                                                             _______, _______, XXXXXXX,         LCTL(KC_INS), LSFT(KC_INS), KC_INS 
  ),
    [_RATON] = LAYOUT_split_3x6_3(
      _______, KC_UNDO,  KC_CUT, KC_COPY,KC_PASTE,KC_AGAIN,                    KC_AGAIN,KC_PASTE, KC_COPY,  KC_CUT, KC_UNDO, _______, 
      _______, _______, _______, _______, _______, _______,                     MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT, _______, _______,
      _______, _______, MS_ACL0, MS_ACL1, MS_ACL2, _______,                     KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______, _______,
                                          _______, _______,  _______,   MS_BTN1, MS_BTN2, MS_BTN3
  ),
    [_FUNCT] = LAYOUT_split_3x6_3(
      XXXXXXX,   KC_F9,   KC_F10, KC_F11,  KC_F12, XXXXXXX,                     KC_AGAIN,KC_PASTE, KC_COPY,  KC_CUT, KC_UNDO, _______, 
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                 _______,OSM(MOD_LSFT),OSM(MOD_LCTL),OSM(MOD_LGUI),OSM(MOD_LALT),OSM(MOD_RALT),
      XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      MO(_ADJUST), KC_APP,  KC_PSCR,   XXXXXXX, XXXXXXX, XXXXXXX
  ),
    [_MEDIA] = LAYOUT_split_3x6_3(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY, KC_MSEL,                      XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
  ),
    [_ADJUST] = LAYOUT_split_3x6_3(
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
  )
};


