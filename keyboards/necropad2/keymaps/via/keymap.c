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

    [_BASE] = LAYOUT(
        KC_1,    KC_2, KC_3, KC_4,
        KC_LSFT, KC_A, KC_S, KC_D,
        KC_Y,    KC_U, KC_I, KC_O,
        KC_H,    KC_J, KC_K, KC_L,
        KC_SPC
    ),
    
    [_L1] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO
    ),

    [_L2] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO
    ),

    [_L3] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO
    )
};
