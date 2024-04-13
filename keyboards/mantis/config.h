// Copyright 2023 Felix Kuehling (@fxkuehl)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef RGB_MATRIX_ENABLE
// The number of LEDs connected
#    define RGB_MATRIX_LED_COUNT 40

#    define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
#    define USB_SUSPEND_WAKEUP_DELAY 5000
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_LED_PROCESS_LIMIT 4
#    define RGB_MATRIX_LED_FLUSH_LIMIT 16
#    define RGB_MATRIX_TIMEOUT 60000

// At full brightness, 40 SK6812MINI-E would draw 1.6A. That's more than the
// 500mA that USB 2 provides and might blow a fuse in the controller.
// Up to about 1/4 maximum brightness should be safe with 400mA.
//
// Brightness 128 in the CIE1931_CURVE table is 48, about 18% of 255. With 40
// LEDs that would draw 288mA, plenty of margin.
//
// One could reduce the margin further with max brightness 140, being 63 in
// the CIE table, about 25% of 255, 400mA with 40 LEDs.
#ifdef USE_CIE1931_CURVE
//#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 128
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 140
#else
//#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 48
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 63
#endif
#define RGB_MATRIX_DEFAULT_HUE 176
#define RGB_MATRIX_DEFAULT_SAT 192
#define RGB_MATRIX_DEFAULT_SPD 96

// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
//#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
//#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_SAT
//#    define ENABLE_RGB_MATRIX_BAND_VAL
//#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
//#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
//#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
//#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
//#    define ENABLE_RGB_MATRIX_CYCLE_ALL
//#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
//#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
//#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
//#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
//#    define ENABLE_RGB_MATRIX_DUAL_BEACON
//#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//#    define ENABLE_RGB_MATRIX_RAINDROPS
//#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
//#    define ENABLE_RGB_MATRIX_HUE_BREATHING
//#    define ENABLE_RGB_MATRIX_HUE_PENDULUM
//#    define ENABLE_RGB_MATRIX_HUE_WAVE
//#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
//#    define ENABLE_RGB_MATRIX_PIXEL_FLOW
#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL

//#    define ENABLE_RGB_MATRIX_FLOWER_BLOOMING
//#    define ENABLE_RGB_MATRIX_STARLIGHT
//#    define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
//#    define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT
//#    define ENABLE_RGB_MATRIX_RIVER_FLOW

#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP

#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS

//#    define ENABLE_RGB_MATRIX_SPLASH
//#    define ENABLE_RGB_MATRIX_MULTISPLASH
//#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
//#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

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
