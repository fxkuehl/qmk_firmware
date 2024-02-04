#pragma once

#define VIAL_KEYBOARD_UID {0xA9, 0xDE, 0x76, 0xF1, 0x89, 0x3A, 0x7E, 0xF1}
#define VIAL_UNLOCK_COMBO_ROWS { 3, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 0 }

// Immediate hold on other key press for thumb mod-taps (already enabled for VIAL)
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// Permissive hold for Space and finger mod-taps to allow fast combos (already enabled for VIAL)
#define PERMISSIVE_HOLD_PER_KEY
// Mod-taps and layer-taps behave the same way (default on current QMK)
//#define IGNORE_MOD_TAP_INTERRUPT

#if defined(CONVERT_TO_PROTON_C) || \
    defined(CONVERT_TO_KB2040) || \
    defined(CONVERT_TO_PROMICRO_RP2040) || \
    defined(CONVERT_TO_BLOK) || \
    defined(CONVERT_TO_BIT_C_PRO) || \
    defined(CONVERT_TO_STEMCELL) || \
    defined(CONVERT_TO_BONSAI_C4) || \
    defined(CONVERT_TO_RP2040_CE) || \
    defined(CONVERT_TO_ELITE_PI) || \
    defined(CONVERT_TO_HELIOS) || \
    defined(CONVERT_TO_LIATRIS) || \
    defined(CONVERT_TO_MICHI)
#    define DYNAMIC_KEYMAP_LAYER_COUNT 8
#else
// Undef some RGB effects that don't fit on a ProMicro
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    undef ENABLE_RGB_MATRIX_BREATHING
#    undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#endif
