// Copyright 2023 Ratata aka ラッタッタ (@Ratata aka ラッタッタ)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once#
#define WS2812_DI_PIN GP16
#define RGBLED_NUM 2
#define RGBLED_SPLIT {1, 1}

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
