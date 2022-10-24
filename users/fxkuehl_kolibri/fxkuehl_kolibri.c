/*
Copyright 2022 Felix Kuehling <felix.kuehling@gmail.com>

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
#include "fxkuehl_kolibri.h"

// Mirror the thumbs on left-handed layout
#if defined(LAYOUT_KOLIBRI_LEFTY_34)
#   define LAYOUT_KOLIBRI_34(                             \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, \
                       K33, K34, K35, K36) LAYOUT_KOLIBRI_LEFTY_34( \
        K00,     K01,     K02,     K03,     K04,     K05,     K06,     K07,     K08,     K09, \
        K10,     K11,     K12,     K13,     K14,     K15,     K16,     K17,     K18,     K19, \
        K20,     K21,     K22,     K23,     K24,     K25,     K26,     K27,     K28,     K29, \
                                   K36,     K35,     K34,     K33)
#   ifndef KOLIBRI_ONE_HANDED_NAV
#       define KOLIBRE_NAV_ON_RIGHT
#   endif
#   ifdef KOLIBRI_NUMPAD
#       define KOLIBRI_SOUTHPAW
#   endif
#elif defined(LAYOUT_KOLIBRI_LEFTY_36)
#   define LAYOUT_KOLIBRI_36(                             \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, \
                  K32, K33, K34, K35, K36, K37) LAYOUT_KOLIBRI_LEFTY_36( \
        K00,     K01,     K02,     K03,     K04,     K05,     K06,     K07,     K08,     K09, \
        K10,     K11,     K12,     K13,     K14,     K15,     K16,     K17,     K18,     K19, \
        K20,     K21,     K22,     K23,     K24,     K25,     K26,     K27,     K28,     K29, \
                          K37,     K36,     K35,     K34,     K33,     K32)
#   ifndef KOLIBRI_ONE_HANDED_NAV
#       define KOLIBRE_NAV_ON_RIGHT
#   endif
#   ifdef KOLIBRI_NUMPAD
#       define KOLIBRI_SOUTHPAW
#   endif
#else
#   ifdef KOLIBRI_ONE_HANDED_NAV
#       define KOLIBRI_NAV_ON_RIGHT
#   endif
#endif

// Define the 34-key layout by discarding the two extra thumb keys from the
// 36-key layout
#ifdef LAYOUT_KOLIBRI_34
#   define LAYOUT_KOLIBRI_36(                             \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, \
                  K32, K33, K34, K35, K36, K37) LAYOUT_KOLIBRI_34( \
        K00,     K01,     K02,     K03,     K04,     K05,     K06,     K07,     K08,     K09, \
        K10,     K11,     K12,     K13,     K14,     K15,     K16,     K17,     K18,     K19, \
        K20,     K21,     K22,     K23,     K24,     K25,     K26,     K27,     K28,     K29, \
                                   K33,     K34,     K35,     K36)
#endif

// Macro keys
enum custom_keycodes {
  M_EMAIL = SAFE_RANGE,
  M_XARGS
};

// Hi-jack two unused 8-bit keycodes for the layer-(un)lock that can be used
// in a Layer-Tap
#define KC_FNLK KC_EXSEL
#define KC_SYLK KC_CRSEL

// Short cuts for mod-tap and layer-tap keys. On the 36-key version LALT moves
// to the outer left thumb key as one-shot mod. RALT moves to the outer right
// thumb key. 16-bit key codes need special handling in process_record_user.

// Base layer
#define LC_T(K) LCTL_T(K)
#define LG_T(K) LGUI_T(K)
#define RG_T(K) RGUI_T(K)
#define RC_T(K) RCTL_T(K)
#define LS_QUOT LSFT_T(KC_QUOT)
#define SY_UNDS LT(L_SYM, KC_UNDS) // 16-bit
#define FN_TAB  LT(L_FN, KC_TAB)
#ifdef LAYOUT_KOLIBRI_34
#   define LA_T(K) LALT_T(K)
#   define RA_SPC  RALT_T(KC_SPC)
#else
#   define LA_T(K) K
#   define RA_SPC  KC_SPC
#   define RA_DEL  RALT_T(KC_DEL)
#   define OS_LALT OSM(MOD_LALT)
#endif

// Num+Sym layer
#define LC_LBRC LCTL_T(KC_LBRC)
#define LC_PLUS LCTL_T(KC_PLUS) // 16-bit
#define LG_LCBR LGUI_T(KC_LCBR) // 16-bit
#define LG_1    LGUI_T(KC_1)
#define RG_GT   RGUI_T(KC_GT)   // 16-bit
#define RG_3    RGUI_T(KC_3)
#define RC_PLUS RCTL_T(KC_PLUS) // 16-bit
#define RC_EXLM RCTL_T(KC_EXLM) // 16-bit
#define FN_DQUO LT(L_FN, KC_DQUO) // 16-bit
#define MD_SYLK LT(L_MEDIA, KC_SYLK)
#define OVS_TAB LT(L_BASE_OV_SYM, KC_TAB)
#ifdef LAYOUT_KOLIBRI_34
#   define LA_RCBR LALT_T(KC_RCBR) // 16-bit
#   define RA_RBRC RALT_T(KC_RBRC)
#   define RA_EQL  RALT_T(KC_EQL)
#   define LA_LT   LALT_T(KC_LT)   // 16-bit
#   define LA_2    LALT_T(KC_2)
#   define RA_MINS RALT_T(KC_MINS)
#   define RA_0    RALT_T(KC_0)
#else
#   define LA_RCBR RALT_T(KC_RCBR) // 16-bit
#   define RA_RBRC KC_RBRC
#   define RA_EQL  KC_EQL
#   ifdef KOLIBRI_SOUTHPAW
#       define LA_LT   RALT_T(KC_LT) // 16-bit
#   else
#       define LA_LT   KC_LT
#   endif
#   define LA_2    KC_2
#   define RA_MINS KC_MINS
#   define RA_0    KC_0
#   define RA_DOT  RALT_T(KC_DOT)
#endif

// Nav+Fn layer
#define LC_F5   LCTL_T(KC_F5)
#define LG_F6   LGUI_T(KC_F6)
#define RG_F11  RGUI_T(KC_F11)
#define RC_F12  RCTL_T(KC_F12)
#define RS_CAPS RSFT_T(KC_CAPS)
#define MC_FNLK LT(L_MACRO, KC_FNLK)
#define OVF_TAB LT(L_BASE_OV_FN, KC_TAB)
#ifdef LAYOUT_KOLIBRI_34
#   define LA_F7   LALT_T(KC_F7)
#   define LA_F10  LALT_T(KC_F10)
#else
#   define LA_F7   KC_F7
#   define LA_F10  KC_F10
#endif

// Pre-defined base layouts with slight adaptations that optimize the symbol
// layer: < > ; : are on the symbol layer. They are replaced on the base layer
// with @ # ` ~. On QWERTY P and `~ are swapped. In Dvorak, /? is back on the
// base layer, replacing ;:, while '\" is replaced with `~.
#define KOLIBRI_BASE_QWERTY \
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_GRV,  \
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_P,    \
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define KOLIBRI_BASE_DVORAK \
        KC_GRV,  KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    \
        KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    \
        KC_SLSH, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z

#define KOLIBRI_BASE_COLEMAK \
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_GRV,  \
        KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    \
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define KOLIBRI_BASE_COLEMAK_DH \
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_GRV,  \
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    \
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH

// Colemak-DK is the default base layout, if none is specified in config.h
#ifndef KOLIBRI_BASE_LAYOUT
#   define KOLIBRI_BASE_LAYOUT KOLIBRI_BASE_COLEMAK_DH
#endif

// Add bottom row mod-taps to the base layout
#define LAYOUT_KOLIBRI_BASE_MODS_36( \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, \
                  K32, K33, K34, K35, K36, K37) LAYOUT_KOLIBRI_36( \
        K00,      K01,      K02,     K03,     K04,     K05,     K06,     K07,      K08,      K09, \
        K10,      K11,      K12,     K13,     K14,     K15,     K16,     K17,      K18,      K19, \
   LC_T(K20),LG_T(K21),LA_T(K22),    K23,     K24,     K25,     K26,LA_T(K27),RG_T(K28),RC_T(K29),\
                            K32,     K33,     K34,     K35,     K36,     K37)

// The Base layer gets duplicated to add a Base-Override layer that can be
// layered on top of a locked Nav+Fn layer. The layer keys are parametrized.
#define KEYMAP_BASE(LAYOUT, K33, K34, K35, K36) LAYOUT_KOLIBRI_BASE_MODS_36(LAYOUT, \
                          OS_LALT, K33,     K34,     K35,     K36,     RA_DEL)

// The Nav+Fn layer gets duplicated for a momentary and a locked version.
// The layer keys are parametrized. There are two versions with arrows on the
// right and left respectively. If mousekeys are enabled, AltGr on the locked
// Nav+FN layer is repurposed as mouse layer-tap.
#ifdef MOUSEKEY_ENABLE
#define MS_SPC LT(L_MOUSE, KC_SPC)
#else
#define MS_SPC KC_TRNS
#endif

#ifdef KOLIBRI_NAV_ON_RIGHT
#   define KEYMAP_FN(K35, K36) LAYOUT_KOLIBRI_36( \
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PSCR, KC_SLCK, KC_HOME, KC_UP,   KC_END,  KC_CALC, \
        KC_ESC,  KC_INS,  KC_BSPC, KC_DEL,  KC_ENT,  KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_PAUS, \
        LC_F5,   LG_F6,   LA_F7,   KC_F8,   KC_APP,  KC_PGDN, KC_F9,   LA_F10,  RG_F11,  RC_F12,  \
                          _______, RS_CAPS, _______, K35,     K36,     _______)
#else
#   define KEYMAP_FN(K35, K36) LAYOUT_KOLIBRI_36( \
        KC_CALC, KC_HOME, KC_UP,   KC_END,  KC_PSCR, KC_SLCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,  \
        KC_PAUS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_ENT,  KC_BSPC, KC_DEL,  KC_INS,  KC_ESC, \
        LC_F5,   LG_F6,   LA_F7,   KC_F8,   KC_PGDN, KC_APP,  KC_F9,   LA_F10,  RG_F11,  RC_F12, \
                          _______, RS_CAPS, _______, K35,     K36,     _______)
#endif

#ifdef KOLIBRI_NUMPAD
#   ifdef KOLIBRI_SOUTHPAW
#       define KEYMAP_SYM(K33, K34) LAYOUT_KOLIBRI_36( \
        KC_PIPE, KC_7,    KC_8,    KC_9,    KC_PERC, KC_CIRC, KC_DLR,  KC_LPRN, KC_RPRN, KC_COLN, \
        KC_MINS, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_SCLN, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, \
        LC_PLUS, LG_1,    LA_2,    KC_3,    KC_AMPR, KC_BSLS, RA_EQL,  LA_LT,   RG_GT,   RC_EXLM, \
                          _______, K33,     K34,     FN_DQUO, RA_0,    RA_DOT)
#   else
#       define KEYMAP_SYM(K33, K34) LAYOUT_KOLIBRI_36( \
        KC_BSLS, KC_LPRN, KC_RPRN, KC_DLR,  KC_PERC, KC_CIRC, KC_7,    KC_8,    KC_9,    KC_COLN, \
        KC_EXLM, KC_LT,   KC_EQL,  KC_GT,   KC_SCLN, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_MINS, \
        LC_LBRC, LG_LCBR, LA_RCBR, RA_RBRC, KC_PIPE, KC_AMPR, KC_1,    LA_2,    RG_3,    RC_PLUS, \
                          _______, K33,     K34,     FN_DQUO, RA_0,    RA_DOT)
#   endif
#else
#   define KEYMAP_SYM(K33, K34) LAYOUT_KOLIBRI_36( \
        KC_EXLM, KC_LPRN, KC_RPRN, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_SCLN, KC_COLN, \
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
        LC_LBRC, LG_LCBR, LA_RCBR, RA_RBRC, KC_PIPE, KC_BSLS, KC_EQL,  LA_LT,   RG_GT,   RC_PLUS, \
                          _______, K33,     K34,     FN_DQUO, RA_MINS, RA_DOT)
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = KEYMAP_BASE(KOLIBRI_BASE_LAYOUT, LS_QUOT, SY_UNDS, FN_TAB, RA_SPC),

    // Locked Fn layer sits below the Sym layer:
    // - Inner key is Tab/Base-Overlay
    // - Home key is Space/Mouse-layer
    //
    // Base-Overlay temporarily restores a (slightly modified) base layer
    [L_FN_LOCKED] = KEYMAP_FN(OVF_TAB, MS_SPC),

    // Base-Overlay over the locked Fn layer:
    // - Inner key is transparent (held by thumb to enable this layer)
    // - Home key (pressed by the index finger) is Fn-unlock/Macro
    //
    // Hold inner + hold home key always enables the Macro layer
    // Hold inner + tap home key is the same key combo to Fn lock or unlock.
    [L_BASE_OV_FN] = KEYMAP_BASE(KOLIBRI_BASE_LAYOUT, LS_QUOT, SY_UNDS, _______, MC_FNLK),

    // Locked Sym layer sits below the Fn layer:
    // - Inner key is Underscore/Base-Overlay
    // - Home key is Space/Shift (adds an extra Space key to use between numbers/symbols)
    //
    // Base-Overlay temporarily restores a (slightly modified) base layer
    [L_SYM_LOCKED] = KEYMAP_SYM(KC_SPC, OVS_TAB),

    // Base-Overlay over the locked Sym layer:
    // - Inner key is transparent (held by thumb to enable this layer)
    // - Home key (pressed by the index finger) is Sym-lock/Media
    //
    // Hold inner + hold home key always enables the Media layer
    // Hold inner + tap home key is the same key combo to Sym lock or unlock
    [L_BASE_OV_SYM] = KEYMAP_BASE(KOLIBRI_BASE_LAYOUT, MD_SYLK, _______, FN_TAB, RA_SPC),

    // Momentary Fn layer:
    // - Inner key is transparent (held by thumb to enable this layer)
    // - Home key (pressed by index finger) is Fn-lock/Media
    [L_FN] = KEYMAP_FN(_______, MC_FNLK),

    // Momentary Sym layer:
    // - Inner key is transparent (held by thumb to enable this layer)
    // - Home key (pressed by index finger) is Sym-lock/Macro
    [L_SYM] = KEYMAP_SYM(MD_SYLK, _______),

    [L_MACRO] = LAYOUT_KOLIBRI_36(
        RESET,   DT_PRNT, DT_DOWN, DT_UP,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, M_XARGS, M_EMAIL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, KC_LSFT, XXXXXXX, _______, _______, XXXXXXX),

    [L_MEDIA] = LAYOUT_KOLIBRI_36(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MYCM, KC_MSEL, KC_MSTP, KC_MUTE, KC_VOLD,
                          XXXXXXX, _______, _______, XXXXXXX, KC_RSFT, XXXXXXX),

#ifdef MOUSEKEY_ENABLE
    [L_MOUSE] = LAYOUT_KOLIBRI_36(
        KC_BTN5, KC_WH_L, KC_WH_U, KC_WH_R, _______, _______, _______, KC_MS_U, _______, _______,
        KC_BTN4, KC_BTN2, KC_WH_D, KC_BTN1, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
        KC_LCTL, KC_LGUI, KC_LALT, KC_BTN3, _______, _______, _______, KC_LALT, KC_RGUI, KC_RCTL,
                          _______, KC_LSFT, KC_ACL0, _______, _______, _______)
#endif
};

/* Prefer tap on all MTs except Shift. These are all the bottom-row mods and
 * AltGr. Other thumb keys (Shift and layers) prefer hold.
 */
static bool prefer_tap(uint16_t keycode) {
    return (keycode & 0xe000) == QK_MOD_TAP &&
         (keycode & 0x0f00) != MOD_LSFT << 8;
}
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return !prefer_tap(keycode);
}
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return prefer_tap(keycode);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* Modify shifted '.' and ',' on the base layer to move '<' and '>' to the
     * Num+Sym layer. Remember the modified code for releasing it later even
     * if shift was released first.
     */
    static uint16_t comm_release = 0;
    static uint16_t  dot_release = 0;

    /* Sym layer doesn't use shift, so skip custom shift processing. */
    if (IS_LAYER_ON(L_SYM))
        goto macros;

    if ((get_mods() & MOD_MASK_SHIFT) && record->event.pressed) {
        uint16_t new_code = 0;

        switch (keycode & 0xff) {
        case KC_COMM: new_code = comm_release = (keycode & 0xff00) | KC_2; break; // '@'
        case KC_DOT:  new_code =  dot_release = (keycode & 0xff00) | KC_3; break; // '#'
        }
        if (new_code) {
            register_code16(new_code);
            clear_weak_mods();
            return false;
        }
    } else if (record->event.pressed) {
        switch (keycode & 0xff) {
        case KC_COMM: comm_release = 0; break;
        case KC_DOT:   dot_release = 0; break;
        }
    } else { // Release event
        uint16_t new_code = 0;

        switch (keycode & 0xff) {
        case KC_COMM: new_code = comm_release; break;
        case KC_DOT:  new_code =  dot_release; break;
        }
        if (new_code) {
            unregister_code16(new_code);
            return false;
        }
    }

macros:
    if (record->event.pressed) { // Macros
        switch (keycode) {
        case M_EMAIL:
            SEND_STRING("Felix Kuehling <Felix.Kuehling@amd.com>");
            return false;
        case M_XARGS:
            SEND_STRING(" -print0 | xargs -0 grep ");
            return false;
        }
    }

    if (record->tap.count) {
        uint16_t code16;

        // Layer locking
        switch(keycode) {
        case MC_FNLK: // Fn-Lock/Unlock
            if (record->event.pressed) {
                layer_invert(L_FN_LOCKED);
                layer_off(L_SYM_LOCKED);
            }
            return false; // doesn't send any keycode
        case MD_SYLK: // Sym-Lock/Unlock
            if (record->event.pressed) {
                layer_invert(L_SYM_LOCKED);
                layer_off(L_FN_LOCKED);
            }
            return false; // doesn't send any keycode
        default:
	    break; // fall through
        }

        // Mod-tap with modified tap-action
        if (IS_LAYER_ON(L_SYM) || IS_LAYER_ON(L_SYM_LOCKED)) {
            switch (keycode) {
            case FN_DQUO: code16 = KC_DQUO; break;
#if defined(KOLIBRI_SOUTHPAW)
            case LC_PLUS: code16 = KC_PLUS; break;
            case RC_EXLM: code16 = KC_EXLM; break;
#else
            case LG_LCBR: code16 = KC_LCBR; break;
            case LA_RCBR: code16 = KC_RCBR; break;
            case RC_PLUS: code16 = KC_PLUS; break;
#endif
#if !defined(KOLIBRI_NUMPAD) || defined(KOLIBRI_SOUTHPAW)
#   if defined(LAYOUT_KOLIBRI_34) || defined(KOLIBRI_SOUTHPAW)
            case LA_LT:   code16 = KC_LT; break;
#   endif
            case RG_GT:   code16 = KC_GT; break;
#endif
            default: return true;
            }
        } else {
            switch (keycode) {
            case SY_UNDS: code16 = KC_UNDS; break;
            default: return true;
            }
        }
        if (record->event.pressed) {
            register_code16(code16);
            clear_weak_mods();
	} else
            unregister_code16(code16);
	return false;
    }

    return true;
}
