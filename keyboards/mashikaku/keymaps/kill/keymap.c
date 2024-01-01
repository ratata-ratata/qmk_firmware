// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// keymap layer number
enum keymap_layer {
  _BASE,
  _L1,
  _L2,
  _L3,
};

static bool x_pressed = false;
static bool c_pressed = false;
static bool v_pressed = false;
static bool b_pressed = false;

static int lay0 = 0;
static int lay1 = 0;
static int lay2 = 0;
static int lay3 = 0;

static bool wkeep = false;
static bool akeep = false;
static bool skeep = false;
static bool dkeep = false;
/*
enum custom_keycodes {
    USER00 = SAFE_RANGE,
	USER01,USER02,USER03
};
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	
/*
judge layer command
 */
	case KC_X:
        if (record->event.pressed) {
            x_pressed = true;
        } else {
            x_pressed = false;
			lay0 = 0;
			lay1 = 0;
			lay2 = 0;
			lay3 = 0;
        }
        break;
	
	case KC_C:
        if (record->event.pressed) {
            c_pressed = true;
        } else {
            c_pressed = false;
			lay0 = 0;
			lay1 = 0;
			lay2 = 0;
			lay3 = 0;
        }
        break;

	case KC_V:
        if (record->event.pressed) {
            v_pressed = true;
        } else {
            v_pressed = false;
			lay0 = 0;
			lay1 = 0;
			lay2 = 0;
			lay3 = 0;
        }
        break;

	case KC_B:
        if (record->event.pressed) {
            b_pressed = true;
        } else {
            b_pressed = false;
			lay0 = 0;
			lay1 = 0;
			lay2 = 0;
			lay3 = 0;
        }
        break;

/*
switch layer command
 */
	case KC_1:
		if (record->event.pressed) {
			if (x_pressed && c_pressed && v_pressed && b_pressed) {
				lay0 ++;
				if (lay0 == 5) {
					set_single_persistent_default_layer(0);
				}
			}
		}
		return true;
		break;
		
	case KC_2:
		if (record->event.pressed) {
			if (x_pressed && c_pressed && v_pressed && b_pressed) {
				lay1 ++;
				if (lay1 == 5) {
					set_single_persistent_default_layer(1);
				}
			}
		}
		return true;
		break;

	case KC_3:
		if (record->event.pressed) {
			if (x_pressed && c_pressed && v_pressed && b_pressed) {
				lay2 ++;
				if (lay2 == 5) {
					set_single_persistent_default_layer(2);
				}
			}
		}
		return true;
		break;

	case KC_4:
		if (record->event.pressed) {
			if (x_pressed && c_pressed && v_pressed && b_pressed) {
				lay3 ++;
				if (lay3 == 5) {
					set_single_persistent_default_layer(3);
				}
			}
		}
		return true;
		break;

/*
judge killswitch

	case QK_KB_0:
        if (record->event.pressed) {
            wkeep = true;
        } else {
            wkeep = false;
        }
        break;

	case QK_KB_1:
        if (record->event.pressed) {
            akeep = true;
        } else {
			akeep = false;
        }
        break;

	case QK_KB_2:
        if (record->event.pressed) {
            skeep = true;
        } else {
            skeep = false;
        }
        break;

	case QK_KB_3:
        if (record->event.pressed) {
            dkeep = true;
        } else {
            dkeep = false;
        }
        break;
 */

/*
aka killswitch
 */

    case QK_KB_0:
        if (record->event.pressed) {
			wkeep = true;
			unregister_code(KC_S);
            register_code(KC_W);
        } else {
			wkeep = false;
            unregister_code(KC_W);
			if (skeep) {
				register_code(KC_S);
			}
        }
        break;

    case QK_KB_1:
        if (record->event.pressed) {
			akeep = true;
			unregister_code(KC_D);
            register_code(KC_A);
        } else {
			akeep = false;
            unregister_code(KC_A);
			if (dkeep) {
				register_code(KC_D);
			}
        }
        break;

    case QK_KB_2:
        if (record->event.pressed) {
			skeep = true;
			unregister_code(KC_W);
            register_code(KC_S);
        } else {
			skeep = false;
            unregister_code(KC_S);
			if (wkeep) {
				register_code(KC_W);
			}
        }
        break;

    case QK_KB_3:
        if (record->event.pressed) {
			dkeep = true;
			unregister_code(KC_A);
            register_code(KC_D);
        } else {
			dkeep = false;
            unregister_code(KC_D);
			if (akeep) {
				register_code(KC_A);
			}
        }
        break;


    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_ortho_6x12(
        KC_ESC,   KC_F13,   KC_F14,   KC_GRV,   KC_LBRC,   KC_RBRC,   KC_SCLN,   KC_QUOT,   KC_COMM,   KC_DOT,    KC_SLSH,   KC_BSPC,
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_EQL,
        KC_TAB,   KC_Q,     QK_KB_0,     KC_E,     KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
        KC_CAPS,  QK_KB_1,     QK_KB_2,     QK_KB_3,     KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_ENT,    KC_ENT,
        KC_LSFT,  KC_PSCR,  KC_Z,     KC_X,     KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_RSFT,   KC_UP,     KC_DEL,
        KC_LCTL,  MO(_L1),  KC_LALT,  MO(_L1),  KC_SPC,    KC_SPC,    KC_LSFT,   KC_SPC,    MO(_L1),   KC_LEFT,   KC_DOWN,   KC_RGHT
    ),

    [_L1] = LAYOUT_ortho_6x12(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO
    ),
    
    [_L2] = LAYOUT_ortho_6x12(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    
    [_L3] = LAYOUT_ortho_6x12(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

void keyboard_post_init_user(void) {
    // Initialize RGB to static black
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(0, 0, 0);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
};

void housekeeping_task_user(void) {
    led_t led_state = host_keyboard_led_state();

    if (led_state.caps_lock) {
        rgblight_sethsv_at(0, 255, 50, 0);
    } else {
        rgblight_sethsv_at(0, 0, 0, 0);
    }
};    