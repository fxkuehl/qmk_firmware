// Copyright 2024 Felix Kuehling (@fxkuehl)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/* Finger assignment:
 * ┌─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┐
 * │  p  │  p  │  R  │  M  │             │  M  │  R  │  p  │  p  │
 * └──┲━━┷━━┳━━┷━━┳━━┷━━┱──┴──┐       ┌──┴──┲━━┷━━┳━━┷━━┳━━┷━━┱──┘
 *    ┃  p  ┃  R  ┃  M  ┃  I  │       │  I  ┃  M  ┃  R  ┃  p  ┃
 * ┌──┺━━┯━━┻━━┯━━┻━━┳━━┻━━┱──┴──┐ ┌──┴──┲━━┻━━┳━━┻━━┯━━┻━━┯━━┹──┐
 * │  p  │  R  │  M  ┃  I  ┃  I  │ │  I  ┃  I  ┃  M  │  R  │  p  │
 * └─────┴──┬──┴──┬──┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹──┬──┴──┬──┴─────┘
 *          │  M  │  I  │  I  │       │  I  │  I  │  M  │
 *          └─────┴─────┴─────┘       └─────┴─────┴─────┘     T - Thumb
 *             ┌─────┲━━━━━┱─────┐ ┌─────┲━━━━━┱─────┐        I - Index finger
 *             │  T  ┃  T  ┃  T  │ │  T  ┃  T  ┃  T  │        M - Middle finger
 *             └─────┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹─────┘        R - Ring finger
 *                      │  T  │       │  T  │                 p - Pinky finger
 *                      └─────┘       └─────┘
 *
 * Base Layer (based on QWERTY):
 * ┌─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┐
 * │  J  │  Q  │  W  │  E  │             │  I  │  O  │  P  │ '"' │
 * └──┲━━┷━━┳━━┷━━┳━━┷━━┱──┴──┐       ┌──┴──┲━━┷━━┳━━┷━━┳━━┷━━┱──┘
 *    ┃  A  ┃  S  ┃  D  ┃  R  │       │  U  ┃  K  ┃  L  ┃  B  ┃
 * ┌──┺━━┯━━┻━━┯━━┻━━┳━━┻━━┱──┴──┐ ┌──┴──┲━━┻━━┳━━┻━━┯━━┻━━┯━━┹──┐
 * │  Z  │  X  │  C  ┃  F  ┃  T  │ │  Y  ┃  N  ┃  ,@ │  .# │  \? │
 * └─Ctl─┴──┬──┴──┬──┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹──┬──┴──┬──┴─Ctl─┘
 *          │ Gui │  V  │  G  │       │  H  │  M  │ App │
 *          └─────┴─────┴─────┘       └─────┴─────┴─Gui─┘     ┌─────┐
 *             ┌─────┲━━━━━┱─────┐ ┌─────┲━━━━━┱─────┐        │ Tap │
 *             │ Alt ┃ Bsp ┃  _  │ │Enter┃     ┃ Del │        └─Hold┘
 *             └1shot┺Shift┹──┬──┘ └──┬──┺━━┯━━┹AltGr┘
 *                      │  -  │       │ Tab │
 *                      └─Sym─┘       └──Fn─┘
 *
 * Base Layer (based on Colemak-DH):
 * ┌─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┐
 * │  X  │  Q  │  W  │  F  │             │  U  │  Y  │  J  │ '"' │
 * └──┲━━┷━━┳━━┷━━┳━━┷━━┱──┴──┐       ┌──┴──┲━━┷━━┳━━┷━━┳━━┷━━┱──┘
 *    ┃  A  ┃  R  ┃  S  ┃  P  │       │  L  ┃  E  ┃  I  ┃  O  ┃
 * ┌──┺━━┯━━┻━━┯━━┻━━┳━━┻━━┱──┴──┐ ┌──┴──┲━━┻━━┳━━┻━━┯━━┻━━┯━━┹──┐
 * │  Z  │  V  │  C  ┃  T  ┃  B  │ │  M  ┃  N  ┃  ,@ │  .# │  \? │
 * └─Ctl─┴──┬──┴──┬──┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹──┬──┴──┬──┴─Ctl─┘
 *          │ Gui │  D  │  G  │       │  K  │  H  │ App │
 *          └─────┴─────┴─────┘       └─────┴─────┴─Gui─┘
 *             ┌─────┲━━━━━┱─────┐ ┌─────┲━━━━━┱─────┐
 *             │ Alt ┃ Bsp ┃  _  │ │Enter┃     ┃ Del │
 *             └1shot┺Shift┹──┬──┘ └──┬──┺━━┯━━┹AltGr┘
 *                      │  -  │       │ Tab │
 *                      └─Sym─┘       └──Fn─┘
 *
 * Sticky Num-Pad and editing layer:
 * ┌─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┐
 * │NumLk│  /  │  7  │  8  │             │rgSat│rgVal│rgSpd│rgTog│
 * └──┲━━┷━━┳━━┷━━┳━━┷━━┱──┴──┐       ┌──┴──┲━━┷━━┳━━┷━━┳━━┷━━┱──┘
 *    ┃  *  ┃  4  ┃  5  ┃  9  │       │rgHue┃  Up ┃Right┃ End ┃
 * ┌──┺━━┯━━┻━━┯━━┻━━┳━━┻━━┱──┴──┐ ┌──┴──┲━━┻━━┳━━┻━━┯━━┻━━┯━━┹──┐
 * │  .  │  1  │  2  ┃  6  ┃  -  │ │rgMod┃ Left┃ Down│ PgDn│ScrLk│
 * └─Ctl─┴──┬──┴──┬──┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹──┬──┴──┬──┴─Ctl─┘
 *          │  ,  │  3  │  +  │       │ Home│ PgUp│ Calc│
 *          └─Gui─┴─────┴─────┘       └─────┴─────┴─Gui─┘
 *             ┌─────┲━━━━━┱─────┐ ┌─────┲━━━━━┱─────┐
 *             │  0  ┃ Bsp ┃  _  │ │Enter┃     ┃ Del │
 *             └─Alt─┺Shift┹──┬──┘ └──┬──┺━━┯━━┹AltGr┘
 *                      │  =  │       │ Tab │
 *                      └─Sym─┘       └──Fn─┘
 *
 * Symbol Layer:
 * ┌─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┐
 * │  ~  │  !  │  <  │  >  │             │  (  │  )  │  |  │  :  │
 * └──┲━━┷━━┳━━┷━━┳━━┷━━┱──┴──┐       ┌──┴──┲━━┷━━┳━━┷━━┳━━┷━━┱──┘
 *    ┃  1  ┃  2  ┃  3  ┃  $  │       │  &  ┃  8  ┃  9  ┃  0  ┃
 * ┌──┺━━┯━━┻━━┯━━┻━━┳━━┻━━┱──┴──┐ ┌──┴──┲━━┻━━┳━━┻━━┯━━┻━━┯━━┹──┐
 * │  [  │  {  │  }  ┃  4  ┃  %  │ │  ^  ┃  7  ┃  -  │  *  │  /  │
 * └─Ctl─┴──┬──┴──┬──┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹──┬──┴──┬──┴─Ctl─┘
 *          │ Gui │  ]  │  5  │       │  6  │  +  │ ../ │
 *          └─────┴AltGr┴─────┘       └─────┴─────┴─Gui─┘
 *             ┌─────┲━━━━━┱─────┐ ┌─────┲━━━━━┱─────┐
 *             │ ... ┃ ... ┃ ... │ │  ;  ┃  =  ┃  `  │
 *             └─────┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹AltGr┘
 *                      │[Sym]│       │  .  │
 *                      └─────┘       └──Fn─┘
 *
 * Function layer:
 * ┌─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┐
 * │  F1 │  F2 │  F3 │  F4 │             │  F9 │ F10 │ F11 │ F12 │
 * └──┲━━┷━━┳━━┷━━┳━━┷━━┱──┴──┐       ┌──┴──┲━━┷━━┳━━┷━━┳━━┷━━┱──┘
 *    ┃ Esc ┃ Ins ┃ Bsp ┃  F5 │       │  F8 ┃  Up ┃Right┃ End ┃
 * ┌──┺━━┯━━┻━━┯━━┻━━┳━━┻━━┱──┴──┐ ┌──┴──┲━━┻━━┳━━┻━━┯━━┻━━┯━━┹──┐
 * │ Caps│Stick│ Vol+┃ Del ┃  F6 │ │  F7 ┃ Left┃ Down│ PgDn│ScrLk│
 * └─Ctl─┴──┬──┴──┬──┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹──┬──┴──┬──┴─Ctl─┘
 *          │ Vol-│ Mute│PrScr│       │ Home│ PgUp│Media│
 *          └─Gui─┴─────┴─────┘       └─────┴─────┴─Gui─┘
 *             ┌─────┲━━━━━┱─────┐ ┌─────┲━━━━━┱─────┐
 *             │ Alt ┃     ┃Enter│ │ Prev┃ Play┃ Next│
 *             └─────┺Shift┹──┬──┘ └──┬──┺━━┯━━┹─────┘
 *                      │ Tab │       │ [Fn]│
 *                      └─Sym─┘       └─────┘
 *
 * Mouse layer:
 * ┌─────┬─────┬─────┬─────┐             ┌─────┬─────┬─────┬─────┐
 * │     │     │     │     │             │ Btn3│     │     │     │
 * └──┲━━┷━━┳━━┷━━┳━━┷━━┱──┴──┐       ┌──┴──┲━━┷━━┳━━┷━━┳━━┷━━┱──┘
 *    ┃     ┃ M-L ┃ M-U ┃     │       │     ┃ W-U ┃ Btn2┃ Btn4┃
 * ┌──┺━━┯━━┻━━┯━━┻━━┳━━┻━━┱──┴──┐ ┌──┴──┲━━┻━━┳━━┻━━┯━━┻━━┯━━┹──┐
 * │ Ctl │     │ M-D ┃ M-R ┃     │ │     ┃ Btn1┃ W-D │ W-R │ Ctl │
 * └─────┴──┬──┴──┬──┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹──┬──┴──┬──┴─────┘
 *          │ Gui │     │     │       │ Btn5│ W-L │ Gui │
 *          └─────┴─────┴─────┘       └─────┴─────┴─────┘
 *             ┌─────┲━━━━━┱─────┐ ┌─────┲━━━━━┱─────┐
 *             │ Alt ┃Shift┃ Acl1│ │ ... ┃[Mou]┃ ... │
 *             └─────┺━━┯━━┹──┬──┘ └──┬──┺━━┯━━┹─────┘
 *                      │ Acl0│       │ ... │
 *                      └─────┘       └─────┘
 */

enum MantisKeycodes {
	// Hijack 8-bit keycode for macros that combine with mod-taps.
	// It's easier than defining tap-dances.
	DD_SLSH = KC_F13,
};

enum MantisLayers {
	LAYER_alpha = 0,
	LAYER_sticky,
	LAYER_sym,
	LAYER_fn,
#ifdef MOUSEKEY_ENABLE
	LAYER_mouse,
#endif
};

#ifdef MOUSEKEY_ENABLE
#define MS_SPC  LT(LAYER_mouse,KC_SPC)
#else
#define MS_SPC  KC_SPC
#endif

#define OS_LALT OSM(MOD_LALT)
#define SH_BSPC LSFT_T(KC_BSPC)
#define SY_MINS LT(LAYER_sym,KC_MINS)
#define FN_TAB  LT(LAYER_fn,KC_TAB)
#define AGR_DEL RALT_T(KC_DEL)
#define LA_P0   LALT_T(KC_P0)
#define SY_PEQL LT(LAYER_sym,KC_PEQL)
#define AGR_GRV RALT_T(KC_GRV)
#define AGR_RBR RALT_T(KC_RBRC)
#define FN_DOT  LT(LAYER_fn,KC_DOT)
#define SH_SPC  RSFT_T(KC_SPC)
#define SY_TAB  LT(LAYER_sym,KC_TAB)
#define TG_STKY TG(LAYER_sticky)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#ifndef MANTIS_COLEMAK
    [LAYER_alpha] = LAYOUT_all(
    // ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
        KC_J,   KC_Q,   KC_W,   KC_E,   KC_R,           KC_U,   KC_I,   KC_O,   KC_P,   KC_QUOT,
    // └───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───╥───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┘
            KC_A,   KC_S,   KC_D,   KC_F,   KC_T,   KC_Y,   KC_N,   KC_K,   KC_L,   KC_B,
    // ┌───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───╨───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┐
 LCTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_G,           KC_H,   KC_M,   KC_COMM,KC_DOT, RCTL_T(KC_BSLS),
    // ╞═══════╪═══════╪═══════╪═══════╪═══════╡       ╞═══════╪═══════╪═══════╪═══════╪═══════╡
        KC_LGUI,OS_LALT,SH_BSPC,SY_MINS,KC_UNDS,        KC_ENT, FN_TAB, MS_SPC, AGR_DEL,RGUI_T(KC_APP)
    // └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
    ),
#else
    [LAYER_alpha] = LAYOUT_all(
    // ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
        KC_X,   KC_Q,   KC_W,   KC_F,   KC_P,           KC_L,   KC_U,   KC_Y,   KC_J,   KC_QUOT,
    // └───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───╥───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┘
            KC_A,   KC_R,   KC_S,   KC_T,   KC_B,   KC_M,   KC_N,   KC_E,   KC_I,   KC_O,
    // ┌───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───╨───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┐
 LCTL_T(KC_Z),  KC_V,   KC_C,   KC_D,   KC_G,           KC_K,   KC_H,   KC_COMM,KC_DOT, RCTL_T(KC_BSLS),
    // ╞═══════╪═══════╪═══════╪═══════╪═══════╡       ╞═══════╪═══════╪═══════╪═══════╪═══════╡
        KC_LGUI,OS_LALT,SH_BSPC,SY_MINS,KC_UNDS,        KC_ENT, FN_TAB, MS_SPC, AGR_DEL,RGUI_T(KC_APP)
    // └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
    ),
#endif
    [LAYER_sticky] = LAYOUT_all(
    // ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
        KC_NUM, KC_PSLS,KC_P7,  KC_P8,  KC_P9,          RGB_HUI,RGB_SAI,RGB_VAI,RGB_SPI,RGB_TOG,
    // └───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───╥───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┘
            KC_PAST,KC_P4,  KC_P5,  KC_P6,  KC_PMNS,RGB_MOD,KC_LEFT,KC_UP,  KC_RGHT,KC_END,
    // ┌───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───╨───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┐
LCTL_T(KC_PDOT),KC_P1,  KC_P2,  KC_P3,  KC_PPLS,        KC_HOME,KC_PGUP,KC_DOWN,KC_PGDN,RCTL_T(KC_SCRL),
    // ╞═══════╪═══════╪═══════╪═══════╪═══════╡       ╞═══════╪═══════╪═══════╪═══════╪═══════╡
LGUI_T(KC_COMM),LA_P0,  _______,SY_PEQL,_______,        KC_PENT,_______,_______,_______,RGUI_T(KC_CALC)
    // └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
    ),
    [LAYER_sym] = LAYOUT_all(
    // ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
        KC_TILD,KC_EXLM,KC_LT,  KC_GT,  KC_DLR,         KC_AMPR,KC_LPRN,KC_RPRN,KC_PIPE,KC_COLN,
    // └───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───╥───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┘
            KC_1,   KC_2,   KC_3,   KC_4,   KC_PERC,KC_CIRC,KC_7,   KC_8,   KC_9,   KC_0,
    // ┌───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───╨───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┐
LCTL_T(KC_LBRC),KC_LCBR,KC_RCBR,AGR_RBR,KC_5,           KC_6,   KC_PLUS,KC_MINS,KC_ASTR,RCTL_T(KC_SLSH),
    // ╞═══════╪═══════╪═══════╪═══════╪═══════╡       ╞═══════╪═══════╪═══════╪═══════╪═══════╡
        _______,_______,_______,_______,_______,        KC_SCLN,FN_DOT, KC_EQL, AGR_GRV,RGUI_T(DD_SLSH)
    // └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
    ),
    [LAYER_fn] = LAYOUT_all(
    // ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
        KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,          KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,
    // └───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───╥───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┘
            KC_ESC, KC_INS, KC_BSPC,KC_DEL, KC_F6,  KC_F7,  KC_LEFT,KC_UP,  KC_RGHT,KC_END,
    // ┌───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───╨───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┐
LCTL_T(KC_CAPS),TG_STKY,KC_VOLU,KC_MUTE,KC_PSCR,        KC_HOME,KC_PGUP,KC_DOWN,KC_PGDN,RCTL_T(KC_SCRL),
    // ╞═══════╪═══════╪═══════╪═══════╪═══════╡       ╞═══════╪═══════╪═══════╪═══════╪═══════╡
LGUI_T(KC_VOLD),KC_LALT,SH_SPC, SY_TAB, KC_ENT,         KC_MPRV,_______,KC_MPLY,KC_MNXT,RGUI_T(KC_MSEL)
    // └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
    ),
#ifdef MOUSEKEY_ENABLE
    [LAYER_mouse] = LAYOUT_all(
    // ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,        XXXXXXX,KC_BTN3,XXXXXXX,XXXXXXX,XXXXXXX,
    // └───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───╥───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┘
            XXXXXXX,KC_MS_L,KC_MS_U,KC_MS_R,XXXXXXX,KC_BTN5,KC_BTN1,KC_WH_U,KC_BTN2,KC_BTN4,
    // ┌───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───╨───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┐
        KC_LCTL,XXXXXXX,KC_MS_D,XXXXXXX,XXXXXXX,        KC_HOME,KC_WH_L,KC_WH_D,KC_WH_R,KC_RCTL,
    // ╞═══════╪═══════╪═══════╪═══════╪═══════╡       ╞═══════╪═══════╪═══════╪═══════╪═══════╡
        KC_LGUI,KC_LALT,KC_LSFT,KC_ACL0,KC_ACL1,        XXXXXXX,XXXXXXX,_______,XXXXXXX,KC_RGUI
    // └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
    ),
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RGUI_T(DD_SLSH):
        if (!record->tap.count) // process holds normally
            return true;
        if (record->event.pressed) // send macro when tapped
            SEND_STRING("../");
	// disable normal processing of tap press and release
	return false;
    }
    return true;
}

/* Prefer tap on fingers, hold on thumbs */
static bool prefer_hold(uint16_t keycode, keyrecord_t *record) {
    if (record->event.key.row < 2 || (uint8_t)(keycode & 0xff) == KC_SPACE)
        return false;
    else if (record->event.key.row == 2)
        return record->event.key.col >= 4 && record->event.key.col <= 5;
    else
        return record->event.key.col >= 2 && record->event.key.col <= 7;
}
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return prefer_hold(keycode, record);
}
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return !prefer_hold(keycode, record);
}

/* Key overrides for @ and # on the base layer */
#define ko_make_basic_no_suppress(trig_mods, trig_key, repl_key) {	\
	.trigger_mods = (trig_mods),					\
	.layers = ~0,							\
	.suppressed_mods = 0,						\
	.options = ko_options_default,					\
	.negative_mod_mask = 0,						\
	.custom_action = NULL,						\
	.context = NULL,						\
	.trigger = (trig_key),						\
	.replacement = (repl_key),					\
	.enabled = NULL							\
}
const key_override_t   at_key_override = ko_make_basic_no_suppress(MOD_MASK_SHIFT, KC_COMM, KC_2);
const key_override_t hash_key_override = ko_make_basic_no_suppress(MOD_MASK_SHIFT, KC_DOT,  KC_3);
const key_override_t ques_key_override = ko_make_basic_no_suppress(MOD_MASK_SHIFT, RCTL_T(KC_BSLS),KC_SLSH);
const key_override_t **key_overrides = (const key_override_t *[]){
    &at_key_override,
    &hash_key_override,
    &ques_key_override,
    NULL
};

/* Alternative layer ideas
 *
 * Symbol Layer (num pad, .= duplicated):
 * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
 * │  ^  │  ~  │  @  │  #  │  $  │       │  7  │  8  │  9  │  :  │  `  │
 * └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┐ ┌──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┘
 *    │  !  │  (  │  =  │  )  │  &  │ │  *  │  4  │  5  │  6  │  -  │
 * ┌──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┘ └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┐
 * │  [  │  {  │  }  │  ]  │  |  │       │  +  │  1  │  2  │  3  │  \  │
 * └─Ctl─┴──┬──┴──┬──┴─────┴─────┘       └─────┴─────┴──┬──┴──┬──┴─Ctl─┘
 *          │ Gui ├─────┬─────┬─────┐ ┌─────┬─────┬─────┤ Gui │
 *          └─────┤ ... │ ... │ ... │ │  %  │  0  │  .  ├─────┘
 *                └─────┴──┬──┴──┬──┘ └──┬──┴──┬──┴AltGr┘
 *                         │ ... │       │  ;  │
 *                         └─────┘       └──Fn─┘
 */
