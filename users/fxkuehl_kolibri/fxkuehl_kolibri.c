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
#   define LAYOUT_KOLIBRI_RAW_34 LAYOUT_KOLIBRI_LEFTY_34
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
#   define LAYOUT_KOLIBRI_RAW_36 LAYOUT_KOLIBRI_LEFTY_36
#   ifndef KOLIBRI_ONE_HANDED_NAV
#       define KOLIBRE_NAV_ON_RIGHT
#   endif
#   ifdef KOLIBRI_NUMPAD
#       define KOLIBRI_SOUTHPAW
#   endif
#else
#   ifdef LAYOUT_KOLIBRI_34
#       define LAYOUT_KOLIBRI_RAW_34 LAYOUT_KOLIBRI_34
#   else
#       define LAYOUT_KOLIBRI_RAW_36 LAYOUT_KOLIBRI_36
#   endif
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
#   define LAYOUT_KOLIBRI_RAW_36(                         \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, \
                  K32, K33, K34, K35, K36, K37) LAYOUT_KOLIBRI_RAW_34( \
        K00,     K01,     K02,     K03,     K04,     K05,     K06,     K07,     K08,     K09, \
        K10,     K11,     K12,     K13,     K14,     K15,     K16,     K17,     K18,     K19, \
        K20,     K21,     K22,     K23,     K24,     K25,     K26,     K27,     K28,     K29, \
                                   K33,     K34,     K35,     K36)
#endif

// Macro, combo and special function keys
enum custom_keycodes {
  M_EMAIL = SAFE_RANGE,
  M_XARGS,
  C_LR_PRN,
  C_LR_BRC,
  C_LR_CBR,
  C_LT_GT,
  C_COMMENT,
  F_CLEAR,
  F_PERMI,
};

// Hi-jack some unused 8-bit keycodes for the layer-(un)lock that can be used
// in a Layer-Tap
#define KC_FNLK KC_EXSEL
#define KC_SYLK KC_CRSEL
#define KC_MSLK KC_CLEAR_AGAIN

// Short cuts for mod-tap and layer-tap keys. On the 36-key version LALT moves
// to the outer left thumb key as one-shot mod. RALT moves to the outer right
// thumb key. 16-bit key codes need special handling in process_record_user.

// Base layer
#define MY_QUOT TD(TD_QUOT)
#define LC_T(K) LCTL_T(K)
#define LG_T(K) LGUI_T(K)
#define RG_T(K) RGUI_T(K)
#define RC_T(K) RCTL_T(K)
#define LS_BSLS LSFT_T(KC_BSLS)
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
#define LC_DLR  LCTL_T(KC_DLR)  // 16-bit
#define LG_LCBR LGUI_T(KC_LCBR) // 16-bit
#define LG_1    LGUI_T(KC_1)
#define RG_GT   RGUI_T(KC_GT)   // 16-bit
#define RG_3    RGUI_T(KC_3)
#define RC_SLSH RCTL_T(KC_SLSH)
#define FN_SCLN LT(L_FN, KC_SCLN)
#if defined(LAYOUT_KOLIBRI_LEFTY_34) || defined(LAYOUT_KOLIBRI_LEFTY_36)
#   define MD_SYLK LT(L_CONFIG, KC_SYLK)
#else
#   define MD_SYLK LT(L_MEDIA, KC_SYLK)
#endif
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
#define SY_MOUS LT(L_SYM, KC_MSLK)
#if defined(LAYOUT_KOLIBRI_LEFTY_34) || defined(LAYOUT_KOLIBRI_LEFTY_36)
#   define CO_FNLK LT(L_MEDIA, KC_FNLK)
#else
#   define CO_FNLK LT(L_CONFIG, KC_FNLK)
#endif
#define OVF_TAB LT(L_BASE_OV_FN, KC_TAB)
#ifdef LAYOUT_KOLIBRI_34
#   define LA_F7   LALT_T(KC_F7)
#   define LA_F10  LALT_T(KC_F10)
#else
#   define LA_F7   SK(F7)
#   define LA_F10  SK(F10)
#endif

// Tap dance
enum {
    TD_F1,
    TD_F2,
    TD_F3,
    TD_F4,
    // F5 is a mod-tap
    // F6 is a mod-tap
    TD_F7,
    TD_F8,
    TD_F9,
    TD_F10,
    // F11 is a mod-tap
    // F12 is a mod-tap
    TD_PSCR,
    TD_SLCK,
    TD_PAUS,
    TD_QUOT,
};

#define SK(td)  TD(TD_##td)

typedef struct {
    uint16_t kc;
} safe_key_t;

static uint16_t last_safe_key = KC_NO;
static bool last_safe_key_held = false;

static void safe_key_finished(qk_tap_dance_state_t *state, void *user_data);
static void safe_key_reset(qk_tap_dance_state_t *state, void *user_data);

#define ACTION_TAP_DANCE_SAFE_KEY(kc) \
    { .fn = {NULL, safe_key_finished, safe_key_reset}, .user_data = (void *)&((safe_key_t){kc}), }

static void quot_on_each_tap(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_F1]   = ACTION_TAP_DANCE_SAFE_KEY(KC_F1),
    [TD_F2]   = ACTION_TAP_DANCE_SAFE_KEY(KC_F2),
    [TD_F3]   = ACTION_TAP_DANCE_SAFE_KEY(KC_F3),
    [TD_F4]   = ACTION_TAP_DANCE_SAFE_KEY(KC_F4),
    [TD_F7]   = ACTION_TAP_DANCE_SAFE_KEY(KC_F7),
    [TD_F8]   = ACTION_TAP_DANCE_SAFE_KEY(KC_F8),
    [TD_F9]   = ACTION_TAP_DANCE_SAFE_KEY(KC_F9),
    [TD_F10]  = ACTION_TAP_DANCE_SAFE_KEY(KC_F10),
    [TD_PSCR] = ACTION_TAP_DANCE_SAFE_KEY(KC_PSCR),
    [TD_SLCK] = ACTION_TAP_DANCE_SAFE_KEY(KC_SLCK),
    [TD_PAUS] = ACTION_TAP_DANCE_SAFE_KEY(KC_PAUS),
    [TD_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(quot_on_each_tap, NULL, NULL),
};

static void safe_key_finished(qk_tap_dance_state_t *state, void *user_data) {
    if ((state->pressed && !state->interrupted) || state->count >= 2) {
        // Key is held without interruption once or tapped multiple times.
        // Register it and let it be used without a tap-dance subsequently
        // until any other key pressed.
        safe_key_t *safe_key = (safe_key_t *)user_data;

        register_code16(safe_key->kc);
        last_safe_key = safe_key->kc;
        last_safe_key_held = true;
    }
}

static void safe_key_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (last_safe_key_held) {
        safe_key_t *safe_key = (safe_key_t *)user_data;

        unregister_code16(safe_key->kc);
        last_safe_key_held = false;
    }
}

#define IS_LT_MT(kc) (((kc) >= QK_LAYER_TAP    && (kc) <= QK_LAYER_TAP_MAX) || \
                      ((kc) >= QK_MOD_TAP      && (kc) <= QK_MOD_TAP_MAX  ) || \
                      ((kc) >= QK_ONE_SHOT_MOD && (kc) <= QK_ONE_SHOT_MOD_MAX))

static bool process_record_safe_keys(uint16_t keycode, keyrecord_t *record) {
    bool ret = true;

    if (last_safe_key != KC_NO && keycode >= SK(F1) && keycode <= SK(PAUS)) {
        safe_key_t *safe_key =
            (safe_key_t *)tap_dance_actions[TD_INDEX(keycode)].user_data;

        // Allow repeating the last safe key with a normal tap or hold
        if (safe_key->kc == last_safe_key) {
            if (record->event.pressed) {
                register_code16(safe_key->kc);
                last_safe_key_held = true;
            } else {
                reset_tap_dance(&tap_dance_actions[TD_INDEX(keycode)].state);
            }
            return false;
        }
    } else if (record->tap.count) {
        switch(keycode) { // Manually handle safe-keys with mod-taps
            case LC_F5:
            case LG_F6:
#ifdef LAYOUT_KOLIBRI_34
            case LA_F7:
            case LA_F10:
#endif
            case RG_F11:
            case RC_F12:
                if (last_safe_key == (keycode & 0xff)) {
                    last_safe_key_held = record->event.pressed;
                    return true;
                } else if (record->tap.count == 2) {
                    last_safe_key = keycode & 0xff;
                    last_safe_key_held = true;
                    return true;
                } else {
                    ret = false; // fall through
                }
        }
    }

    // Tapping anything other than the last safe key clears the memory of the
    // last safe key. Holding/releasing layer-tap or mod-tap keys is OK.
    if (last_safe_key != KC_NO && (!IS_LT_MT(keycode) || record->tap.count)) {
        // If the safe key is currently held, unregister before forgetting it.
        if (last_safe_key_held) {
            unregister_code16(last_safe_key);
            last_safe_key_held = false;
        }
        last_safe_key = KC_NO;
    }

    return ret;
}

static void quot_on_each_tap(qk_tap_dance_state_t *state, void *user_data) {
    int8_t mods = get_mods();

    if (mods & ~MOD_MASK_SHIFT) // Don't do anything if non-shift mods are set
        return;

    if (state->count >= 3) // 3rd and subsequent tap insert a pair of quotes
        tap_code(KC_QUOT);
    if (state->count >= 2) { // 2nd and subsequent tap move the cursor left
        if (mods) del_mods(mods);
        tap_code(KC_LEFT);
        if (mods) add_mods(mods);
    }
}
static bool process_record_quot(uint16_t keycode, keyrecord_t *record) {
    if (keycode == TD(TD_QUOT)) {
        if (record->event.pressed)
            register_code(KC_QUOT);
        else
            unregister_code(KC_QUOT);
    }

    return true;
}

// Pre-defined base layouts with slight adaptations that optimize the symbol
// layer: < > ; : / are on the symbol layer. Quotes are more easily reachable
// on the base layer on QWERTY and Colemak-based layouts. < > are replaced
// with @ #. ? is on a thumb key.
#define KOLIBRI_BASE_QWERTY \
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    MY_QUOT, \
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_GRV

#define KOLIBRI_BASE_DVORAK \
        MY_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    \
        KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    \
        KC_GRV,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z

#define KOLIBRI_BASE_COLEMAK \
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    MY_QUOT, \
        KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    \
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_GRV

#define KOLIBRI_BASE_COLEMAK_DH \
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    MY_QUOT, \
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    \
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_GRV

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
        SK(F1),  SK(F2),  SK(F3),  SK(F4),  SK(PSCR),SK(SLCK),KC_HOME, KC_UP,   KC_END,  KC_CALC, \
        KC_ESC,  KC_INS,  KC_BSPC, KC_DEL,  KC_ENT,  KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, SK(PAUS),\
        LC_F5,   LG_F6,   LA_F7,   SK(F8),  KC_APP,  KC_PGDN, SK(F9),  LA_F10,  RG_F11,  RC_F12,  \
                          _______, RS_CAPS, SY_MOUS, K35,     K36,     _______)
#else
#   define KEYMAP_FN(K35, K36) LAYOUT_KOLIBRI_36( \
        KC_CALC, KC_HOME, KC_UP,   KC_END,  SK(PSCR),SK(SLCK),SK(F1),  SK(F2),  SK(F3),  SK(F4), \
        SK(PAUS),KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_ENT,  KC_BSPC, KC_DEL,  KC_INS,  KC_ESC, \
        LC_F5,   LG_F6,   LA_F7,   SK(F8),  KC_PGDN, KC_APP,  SK(F9),  LA_F10,  RG_F11,  RC_F12, \
                          _______, RS_CAPS, SY_MOUS, K35,     K36,     _______)
#endif

#ifdef KOLIBRI_NUMPAD
#   ifdef KOLIBRI_SOUTHPAW
#       define KEYMAP_SYM(K33, K34) LAYOUT_KOLIBRI_36( \
        KC_TILD, KC_7,    KC_8,    KC_9,    KC_PERC, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_COLN, \
        KC_EQL,  KC_4,    KC_5,    KC_6,    KC_ASTR, KC_PIPE, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, \
        LC_DLR,  LG_1,    LA_2,    KC_3,    KC_PLUS, KC_EXLM, RA_MINS, LA_LT,   RG_GT,   RC_SLSH, \
                          _______, K33,     K34,     FN_SCLN, RA_0,    RA_DOT)
const uint16_t PROGMEM lr_brc_combo[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM lr_cbr_combo[] = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM lt_gt_combo[]  = {LA_LT,   RG_GT,   COMBO_END};
#   else
#       define KEYMAP_SYM(K33, K34) LAYOUT_KOLIBRI_36( \
        KC_TILD, KC_LPRN, KC_RPRN, KC_DLR,  KC_PERC, KC_CIRC, KC_7,    KC_8,    KC_9,    KC_COLN, \
        KC_EXLM, KC_LT,   KC_EQL,  KC_GT,   KC_AMPR, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_MINS, \
        LC_LBRC, LG_LCBR, LA_RCBR, RA_RBRC, KC_PIPE, KC_PLUS, KC_1,    LA_2,    RG_3,    RC_SLSH, \
                          _______, K33,     K34,     FN_SCLN, RA_0,    RA_DOT)
const uint16_t PROGMEM lr_brc_combo[] = {LC_LBRC, RA_RBRC, COMBO_END};
const uint16_t PROGMEM lr_cbr_combo[] = {LG_LCBR, LA_RCBR, COMBO_END};
const uint16_t PROGMEM lt_gt_combo[]  = {KC_LT,   KC_GT,   COMBO_END};
#   endif
#else
#   define KEYMAP_SYM(K33, K34) LAYOUT_KOLIBRI_36( \
        KC_EXLM, KC_LPRN, KC_RPRN, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_COLN, \
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
        LC_LBRC, LG_LCBR, LA_RCBR, RA_RBRC, KC_PIPE, KC_TILD, KC_MINS, LA_LT,   RG_GT,   RC_SLSH, \
                          _______, K33,     K34,     FN_SCLN, RA_EQL,  RA_DOT)
const uint16_t PROGMEM lr_brc_combo[] = {LC_LBRC, RA_RBRC, COMBO_END};
const uint16_t PROGMEM lr_cbr_combo[] = {LG_LCBR, LA_RCBR, COMBO_END};
const uint16_t PROGMEM lt_gt_combo[]  = {LA_LT,   RG_GT,   COMBO_END};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = KEYMAP_BASE(KOLIBRI_BASE_LAYOUT, LS_BSLS, SY_UNDS, FN_TAB, RA_SPC),

    // Locked Fn layer sits below the Sym layer:
    // - Inner key is Tab/Base-Overlay
    // - Home key is Space/AltGr
    //
    // Base-Overlay temporarily restores a (slightly modified) base layer
    [L_FN_LOCKED] = KEYMAP_FN(OVF_TAB, RA_SPC),

    // Base-Overlay over the locked Fn layer:
    // - Inner key is transparent (held by thumb to enable this layer)
    // - Home key (pressed by the index finger) is Fn-unlock/Macro
    //
    // Hold inner + hold home key always enables the Macro layer
    // Hold inner + tap home key is the same key combo to Fn lock or unlock.
    [L_BASE_OV_FN] = KEYMAP_BASE(KOLIBRI_BASE_LAYOUT, LS_BSLS, SY_UNDS, _______, CO_FNLK),

    // Locked Sym layer sits below the Fn layer:
    // - Inner key is Underscore/Base-Overlay
    // - Home key enables a shifted base overlay so uppercase letters can be
    //   inserted while the Sym layer is locked
    //
    // Base-Overlay temporarily restores a (slightly modified) base layer
    [L_SYM_LOCKED] = KEYMAP_SYM(LM(L_BASE_OV_SHIFT, MOD_LSFT), OVS_TAB),

    // Base-Overlay over the locked Sym layer:
    // - Inner key is transparent (held by thumb to enable this layer)
    // - Home key (pressed by the index finger) is Sym-lock/Media
    //
    // Hold inner + hold home key always enables the Media layer
    // Hold inner + tap home key is the same key combo to Sym lock or unlock
    [L_BASE_OV_SYM]   = KEYMAP_BASE(KOLIBRI_BASE_LAYOUT, MD_SYLK, _______, FN_TAB, RA_SPC),
    [L_BASE_OV_SHIFT] = KEYMAP_BASE(KOLIBRI_BASE_LAYOUT, _______, _______, FN_TAB, RA_SPC),

#ifdef MOUSEKEY_ENABLE
    // The mouse layer is under the Fn layer because it is toggled via Fn
    [L_MOUSE] = LAYOUT_KOLIBRI_36(
        _______, KC_BTN4, KC_BTN5, _______, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, _______,
        _______, KC_BTN2, KC_BTN3, KC_BTN1, _______, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, _______,
        KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, _______, KC_WH_D, KC_RALT, KC_LALT, KC_RGUI, KC_RCTL,
                          _______, KC_LSFT, KC_ACL0, FN_TAB,  KC_ACL1, _______),
#endif

    // Momentary Fn layer:
    // - Inner key is transparent (held by thumb to enable this layer)
    // - Home key (pressed by index finger) is Fn-lock/Media
    [L_FN] = KEYMAP_FN(_______, CO_FNLK),

    // Momentary Sym layer:
    // - Inner key is transparent (held by thumb to enable this layer)
    // - Home key (pressed by index finger) is Sym-lock/Macro
    [L_SYM] = KEYMAP_SYM(MD_SYLK, _______),

    [L_CONFIG] = LAYOUT_KOLIBRI_RAW_36(
        RESET,   DT_PRNT, DT_DOWN, DT_UP,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, F_PERMI, XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, KC_LSFT, F_CLEAR, _______, _______, XXXXXXX),

    [L_MEDIA] = LAYOUT_KOLIBRI_RAW_36(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, M_EMAIL, XXXXXXX, M_XARGS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MYCM, KC_MSEL, KC_MSTP, KC_MUTE, KC_VOLD,
                          XXXXXXX, _______, _______, XXXXXXX, KC_RSFT, XXXXXXX),
};

enum combos {
    LR_PRN,
    LR_BRC,
    LR_CBR,
    LT_GT,
    SLSH_ASTR,
    NUM_COMBOS
};
uint16_t COMBO_LEN = NUM_COMBOS;

const uint16_t PROGMEM  lr_prn_combo[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM comment_combo[] = {RC_SLSH, KC_ASTR, COMBO_END};
/* other combos are defined conditionally for different Sym layer variants */

combo_t key_combos[] = {
  [LR_PRN]    = COMBO( lr_prn_combo, C_LR_PRN),
  [LR_BRC]    = COMBO( lr_brc_combo, C_LR_BRC),
  [LR_CBR]    = COMBO( lr_cbr_combo, C_LR_CBR),
  [LT_GT]     = COMBO(  lt_gt_combo, C_LT_GT),
  [SLSH_ASTR] = COMBO(comment_combo, C_COMMENT),
};

/* Prefer tap on all MTs except Shift and AltGr/Del. These are all the
 * bottom-row mods and AltGr/Spc. Other thumb keys prefer hold.
 */
static bool prefer_tap(uint16_t keycode) {
    return (keycode & 0xe000) == QK_MOD_TAP &&
#ifndef LAYOUT_KOLIBRI_34
           keycode != RA_DEL &&
#endif
           (keycode & 0x0f00) != MOD_LSFT << 8;
}
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return !prefer_tap(keycode);
}
static bool permissive = true;
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return permissive && prefer_tap(keycode);
}

/* Replace some shifted symbols with different ones. Used to selectively move
 * some symbols from the base layer to the Sym layer.
 */
static bool process_record_shifted_symbols(uint16_t keycode, keyrecord_t *record) {
    // Remember the modified code for releasing it later even if Shift was
    // released first.
    static uint16_t comm_release, dot_release, grv_release;
    uint16_t new_code = 0;

    // Ignore Sym-layer where the shifted symbols moved to
    if (IS_LAYER_ON(L_SYM))
        return true;

    if ((get_mods() & MOD_MASK_SHIFT) && record->event.pressed) { // Shifted key press
        switch (keycode & 0xff) {
        case KC_COMM: new_code = comm_release = (keycode & 0xff00) | KC_2;    break; // '@'
        case KC_DOT:  new_code =  dot_release = (keycode & 0xff00) | KC_3;    break; // '#'
        case KC_GRV:  new_code =  grv_release = (keycode & 0xff00) | KC_SLSH; break; // '?'
        default: return true; // continue processing other keys normally
        }
        register_code16(new_code);
        return false; // stop processing
    } else if (record->event.pressed) { // Non-shifted key press
        switch (keycode & 0xff) {
        case KC_COMM: comm_release = 0; break;
        case KC_DOT:   dot_release = 0; break;
        case KC_GRV:   grv_release = 0; break;
        }
        return true; // continue processing normally
    } else { // Key release
        switch (keycode & 0xff) {
        case KC_COMM: new_code = comm_release; break;
        case KC_DOT:  new_code =  dot_release; break;
        case KC_GRV:  new_code =  grv_release; break;
        }
        if (!new_code)
            return true;
        unregister_code16(new_code);
        return false; // stop processing
    }
}

static bool process_record_macros(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case M_EMAIL: SEND_STRING("Felix Kuehling <Felix.Kuehling@amd.com>"); return false;
        case M_XARGS: SEND_STRING(" -print0 | xargs -0 grep "); return false;
        case C_LR_PRN:  SEND_STRING("()" SS_TAP(X_LEFT)); return false;
        case C_LR_BRC:  SEND_STRING("[]" SS_TAP(X_LEFT)); return false;
        case C_LR_CBR:  SEND_STRING("{\n}" SS_TAP(X_UP) SS_TAP(X_END) "\n"); return false;
        case C_LT_GT:   SEND_STRING("<>" SS_TAP(X_LEFT)); return false;
        case C_COMMENT: SEND_STRING("/* */" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
                        return false;
	case F_PERMI:
            permissive = !permissive;
            if (permissive)
                SEND_STRING("permissive");
            else
                SEND_STRING("strict");
            return false;
        case F_CLEAR: // Clears all keyboard state: locked layers and caps-lock
            layer_off(L_FN_LOCKED);
            layer_off(L_SYM_LOCKED);
            layer_off(L_MOUSE);
            if (host_keyboard_led_state().caps_lock)
                tap_code(KC_CAPS);
            return false;
        }
    }
    return true;
}

static bool process_record_layer_lock(uint16_t keycode, keyrecord_t *record) {
    if (!record->tap.count)
        return true;

    switch(keycode) {
    case CO_FNLK: // Fn-Lock/Unlock
        if (record->event.pressed) {
            layer_invert(L_FN_LOCKED);
            layer_off(L_SYM_LOCKED);
            layer_off(L_MOUSE);
        }
        return false; // doesn't send any keycode
    case MD_SYLK: // Sym-Lock/Unlock
        if (record->event.pressed) {
            layer_invert(L_SYM_LOCKED);
            layer_off(L_FN_LOCKED);
            layer_off(L_MOUSE);
        }
        return false; // doesn't send any keycode
    case SY_MOUS: // Mouse-Lock/Unlock
        if (record->event.pressed) {
            layer_invert(L_MOUSE);
            layer_off(L_SYM_LOCKED);
            layer_off(L_FN_LOCKED);
        }
        return false; // doesn't send any keycode
    default: return true;
    }
}

static bool process_record_lt_mt_hacks(uint16_t keycode, keyrecord_t *record) {
    uint16_t code16;

    if (!record->tap.count)
        return true;

    if (IS_LAYER_ON(L_SYM) || IS_LAYER_ON(L_SYM_LOCKED)) {
        switch (keycode) {
#if defined(KOLIBRI_SOUTHPAW)
        case LC_DLR:  code16 = KC_DLR; break;
#else
        case LG_LCBR: code16 = KC_LCBR; break;
        case LA_RCBR: code16 = KC_RCBR; break;
#endif
#if !defined(KOLIBRI_NUMPAD) || defined(KOLIBRI_SOUTHPAW)
#   if defined(LAYOUT_KOLIBRI_34) || defined(KOLIBRI_SOUTHPAW)
        case LA_LT:   code16 = KC_LT; break;
#   endif
        case RG_GT:   code16 = KC_GT; break;
#endif
        case FN_SCLN:
            if (record->tap.count >= 2) {
                if (record->event.pressed)
                    register_code(KC_ENT);
                else
                    unregister_code(KC_ENT);
                return false;
            }
            // fall through
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
        clear_weak_mods(); // Avoid modifying subsequent rolling key strokes
    } else
        unregister_code16(code16);
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_record_safe_keys(keycode, record) &&
           process_record_quot(keycode, record) &&
           process_record_shifted_symbols(keycode, record) &&
           process_record_macros(keycode, record) &&
           process_record_layer_lock(keycode, record) &&
           process_record_lt_mt_hacks(keycode, record);
}
