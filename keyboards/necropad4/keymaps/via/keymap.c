// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// keymap layer number
enum keymap_layer {
  _BASE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    
    [_BASE] = LAYOUT(
        KC_ESC, KC_BSPC,
        KC_Q,   KC_W,    KC_E, KC_UP,
        KC_A,   KC_S,    KC_D, KC_LEFT, KC_DOWN, KC_RGHT
    )
};
