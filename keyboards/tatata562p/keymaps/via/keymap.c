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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_ortho_5x12(
        KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,   KC_9,    KC_0,    KC_BSPC,
        KC_LALT, KC_GRV, KC_LBRC, KC_RBRC, KC_BSLS, KC_SCLN, KC_QUOT, KC_COMM, KC_DOT, KC_SLSH, KC_MINS, KC_EQL,
        KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,   KC_O,    KC_P,    KC_DEL,
        KC_LSFT, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,   KC_L,    KC_UP,   KC_ENT,
        KC_LCTL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_SPC,  KC_B,    KC_N,    KC_M,   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_L1] = LAYOUT_ortho_5x12(
        KC_NO,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,  KC_F10, KC_F11, 
        KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
        KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO
    ),
    
    [_L2] = LAYOUT_ortho_5x12(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    
    [_L3] = LAYOUT_ortho_5x12(
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