// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// keymap layer number
enum keymap_layer {
  _BASE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_P1,   KC_P2,   KC_P3,
        KC_P4,   KC_P5,   KC_P6,
        KC_P7,   KC_P8,   KC_P9
    )
};
