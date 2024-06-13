// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// keymap layer number
enum keymap_layer {
  _BASE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_BSPC,
        KC_TAB, KC_3, KC_4, KC_ENT,
        KC_LSFT, KC_5, KC_6
    )
};
