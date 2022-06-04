![Layout Overview](kle-kolibri.png)

# Kolibri

Kolobri is a keymap for small ergonomic/split keyboards with 3x5 keys and 2 thumb keys per hand. It is designed to be fully functional, comfortable and intuitive to use, easy to learn and well suited for fast typing and programming. Major highlights are:

* Shift, AltGr and layer keys on thumbs
* Bottom-row mod-taps for remaining modifiers
* Space, Tab, Underscore and Apostrophe on thumbs
* Per-key mod-tap configuration to favour "tap" on fingers and Space, "hold" on other thumb keys
* Non-AltGr letters, symbols and numbers accessible with at most one modifier (either Shift or Sym layer key)
* Most frequent keys on the home row: numbers, arrows, editing, Esc
* Fn layer can be locked
* Options for left or right-handed thumb clusters and Function layers

_[Groma Kolibri](https://typewriterreview.com/2015/11/19/groma-kolibri/) was the brand of my father's mechanical typewriter, the first I ever learned typing on as a kid. Kolibri is also the German word for hummingbird. Those two associations make it a fitting name for a small keyboard layout._

# Layer Design

The basic keyboard functionality is on three layers: Base (e.g. Colemak or QWERTY), num+sym, nav+fn. A fourth ctrl+macro layer adds keyboard control (backlight, reset, etc.), media keys and macros. It is activated by holding both layer keys.

The nav+fn layer can be locked. In this mode the nav+fn layer key temporarily activates a base-layer overlay to allow inserting a few characters without unlocking nav+fn. The num+sym layer can also be activated on top of the locked nav+fn layer.

An optional mouse layer can be enabled via the locked nav+fn layer. With more thumb keys per hand it could have a dedicated layer key on the base layer.

Ctrl, Gui and Alt modifiers are consistent across all layers, in the outer columns of the bottom row.

## Base Layer

```
   Top row tap:   Q   W   F   P   G              J   L   U   Y   ;:
  Home row tap:   A   R   S   T   D              H   N   E   I   O
Bottom row tap:   Z   X   C   V   B              K   M   ,#  .@  /?
Bottom row hold: Ctl Gui Alt                            Alt Gui Ctl
     Thumb tap:                   '   _     Tab Spc
     Thumb hold:                Shft Sym    Fn AltGr
```

Other than the bottom-row mod-taps, the 3x5 finger keys are mostly standard Colemak or QWERTY, with two exceptions: The shifted symbols of ',' and '.' (normally '<' and '>') are moved to the num+sym layer to avoid the thumb jumping between Shift and Sym for common bigrams such as '->', '<=' and '>='. They are replaced on the base layer with '#' and '@', which are not typically used in bigrams with other symbols.

For right-handed users, Shift is on the left thumb, AltGr on the right. This choice dictates much of the rest of the thumb cluster layout. The left thumb activates the num+fn layer that needs AltGr, and the right thumb activates the nav+fn layer that needs Shift. Space and Tab are on the right thumb and can be combined with Shift. Shift and Space, are on the home positions of the thumbs.

Two symbols do not fit in the num+sym layer and need to move to the left thumb on the base layer. Apostrophe and Underscore are convenient choices for typing and programming respectively. Apostrophe is placed on the Shift key to avoid the thumb jumping when typing "I'm". Underscore is on the num+sym layer key, which forces the thumb to jump when typing "UPPER_CASE_MACRO" names and avoids accidentally activating a tap+hold of Underscore instead of holding Shift.

## Num+Sym Layer

```
   Top row tap:   !   `   ~   $   %              ^   &   *   (   )
  Home row tap:   1   2   3   4   5              6   7   8   9   0
Bottom row tap:   [   {   }   ]   \              +   =   <   >   |
Bottom row hold: Ctl Gui Alt AGr                        Alt Gui Ctl
     Thumb tap:                  ___ ___     "   -
     Thumb hold:                            C+M AGr
```

This layer works without the Shift key. Numbers are on the home row. The corresponding shifted number symbols are in the upper row (except '#' and '@', which are replacing '<' and '>' on the base layer). This should be intuitive for users of TKL keyboards.

'<' and '>' keep their normal positions, so the only thing that changes is the "Shift" key used to activate them. '|' takes the place of '/'. '+' and '=' take the remaining right-hand bottom-row keys, which puts most of the common math and logical operators on the right hand.

The left bottom row has brackets, curly braces and '\'. The nested arrangement of the brackets around the curly braces makes the "[]" bigram easier to type than having the closed bracket on the ring finger.

The right thumb types double quotes and '-'. Since '-' is often surrounded by Space, it uses the same key as Space. That way the right thumb doesn't need to jump when typing such sequences. A second AltGr mod-tap key is added in the left bottom row to allow modifying the two symbols on the right thumb.

## Nav+Fn Layer

```
   Top row tap:   F1  F2  F3  F4 PScr          SLck Home ↑  End Vol+
  Home row tap:  Esc Ins  ⌫   ⌦   ↲            PgUp  ←   ↓   →  Vol-
Bottom row tap:   F5  F6  F7  F8 Menu          PgDn  F9 F10 F11 F12
Bottom row hold: Ctl Gui Alt                            Alt Gui Ctl
     Thumb tap:                 Caps FnLk   ___ ___
     Thumb hold:                Shft C+M
     Thumb hold with FnLk:           Sym   Base Mouse
```

The nav+fn layer has an inverted-T arrow key cluster in the home position of the right hand. Home and End keys are left and right of the Up key. PageUp/Down are on the inner index-finger column, where there are no mod-taps affecting key-repeat. Like on a normal keyboard, the arrow keys can be used one-handed.

The left home row has Esc, Insert, Backspace, Delete, Enter, with Backspace and Delete on the strongest fingers. Enter is a little harder to reach on the inner column to avoid hitting it accidentally.

The F-keys are arranged in groups of four: F1-F4 in top-left, F5-F8 in bottom-left, F9-F12 in bottom-right. The remaining spots are filled up with Menu, PrintScreen, ScrollLock, and media volume control.

Tapping the Shift key on this layer toggles CapsLock.

The Nav+Fn layer can be locked with the FnLk key. Tapping the same key again unlocks the layer. FnLk can reduce strain and free up the right thumb to type Space and Tab while editing or fixing indentation. The locked Nav+Fn layer is below the Num+Sym layer in the layer stack, so the Sym key still works on this layer. Holding the Fn key while the Nav+Fn layer is locked allows typing text without unlocking Nav+Fn. This is analogous to using Shift while CapsLock is enabled.

The AltGr function is replaced by a Mouse layer key if mouse keys are enabled.

## Alternative Nav+Fn Layers (TODO)

```
   Top row tap:   F1  F2  F3  F4 PScr          SLck Hom PDn PUp End
  Home row tap:  Esc Ins  ⌫   ⌦   ↲            Vol+  ←   ↓   ↑   →
Bottom row tap:   F5  F6  F7  F8 Menu          Vol-  F9 F10 F11 F12
Bottom row hold: Ctl Gui Alt                            Alt Gui Ctl
     Thumb tap:                 Caps FnLk   ___ ___
     Thumb hold:                Shft C+M
     Thumb hold with FnLk:           Sym   Base Mouse
```

An alternative navigation layer puts all the arrow keys in the home row, and paging, home and end keys in the upper row. This may have ergonomic benefits but requires more changes to muscle memory for anyone not used to Vi-style arrow keys.

Arrow keys on the right hand enable one-handed navigation or lazy browsing with only one hand on the keyboard. Some users may prefer the arrow keys in the left hand to reduce strain from holding the layer key with the same thumb. That would move the editing keys and Esc to the right instead. This variant can be combined with either of the arrow-key layouts.

## Ctrl+Macro Layer

This layer can control RGB underglow, QMK Reset and Debug functions as well as dynamic tapping term. It also has space for more media keys and personalized macros.

TODO: Formalize definition and reserve space for user-defined macros

## Mouse Layer

The right hand is used for mouse movement (inverted-T cluster) and left-right scrolling. The left hand has the scroll wheel and mouse buttons. The "left" mouse button is on the index-finger, "middle" and "right" button on the ring finger. Button 4 and 5 are on the pinky. Having the "left" button on the left index finger allows dragging while holding the button and any additional modifiers.

The thumb keys have Shift and one key to control mouse acceleration.

## Support for other layouts and languages (TODO)

Kolibri works best for US-English QWERTY and Colemak layouts where the OS keymap is set to US-English or a derived International layout with extra symbols on an AltGr layer.

Using Dvorak would require small changes to some symbol key positions since quotes would end up on the left pinky instead of thumb keys. Or Quotes could keep their Kolibri positions on the thumb keys and the left pinky gets ';:' instead.

Native support for other languages would require tweaks to the base and symbol layers. ISO keyboard layouts have one more key. To fit that, one key would need to move to the Nav+Fn layer.

# Motivation and Concepts

A popular layout for 3x5 split keyboards is [Miryoku](https://github.com/manna-harbour/miryoku). But its use of home-row mods is not for everyone. Especially Shift as mod-tap on a home-row key leads to frequent ambiguity between mod+tap or tap-tap that can hurt typing flow.

Kolibri is designed to be a fully functional alternative that is comfortable and intuitive to use without disrupting the flow of typing or coding. It aims to be easy to remember and learn for anyone coming from a TKL or similar keyboard without a num-pad. Requiring only two thumb keys per hand makes it compatible with a wider range of keyboards out of the box.

For full functionality and comfort, all modifier+key combinations must be possible to type without reaching or straining. The thumbs can only hold two modifiers or layer keys at the same time. Therefore most modifiers have to be assigned to fingers, with no more than one modifier per finger. On a 3x5 layout this requires dual-function keys. Modifier keys must be duplicated on both hands to avoid contortions and to make modifying any key possible.

Shift and AltGr are conceptually layer switching keys, except they are handled by the host rather than the keyboard firmware. Placing them on thumb keys along with firmware layer switching keys feels intuitive, while minimizing the use of problematic mod-tap or layer-tap keys in the 3x5 typing area. Moving remaining mod-taps to less frequently used bottom-row keys further reduces the impact on typing flow. Per-key mod-tap configuration can unambiguously favour "tap" on fingers and Space, and "hold" on Shift and layer thumb keys.

## Design Choices and Constraints

* 3x5 with 2 thumb keys per hand
* Shift, AltGr and layer keys on the thumbs
* Bottom-row mods for Ctrl, Gui, Alt
* Space and Tab on thumbs on the base layer
* Only one Space and one Shift key
* Use home row for most frequent keys on layers: editing, navigation, numbers
* Esc on the home row for use in Vim

With Shift and AltGr on thumbs, the remaining thumb keys are are too few for many Miryoku-style one-handed layers. Therefore this keymap uses fewer layers, which span both hands. Consequently mod-tap modifiers are needed on both hands on all layers to allow all modifier+key combinations, and combinations of thumb modifier/layer with same-hand finger keys are common by design.

Shift and AltGr must be on opposite thumbs to allow Shift+AltGr combinations. Right-handed users need Shift on the left thumb so it can be used as a modifier with the mouse. Space and Tab must be on the right thumb to allow combinations with Shift. The layer descriptions assume right-handedness. However, a version with flipped thumb-cluster is available for left-handed users.

Layers can use either Shift or AltGr, but not both, because one thumb is already holding the layer key. The num+sym layer is designed to work without Shift, so it can use AltGr. This also avoids three-key chords for all the common symbols. Nav+fn and (optional) Mouse layers need Shift (e.g. for highlighting text) but don't need AltGr.

Mod-tap keys require two presses in quick succession to enable key-repeat. Therefore keys that are frequently used with key-repeat, such as arrow keys, will not be placed on bottom-row modifier keys.

All four thumb keys are dual-function keys. With 3 thumb keys per hand, Space and Shift could be made single-function keys. The choice of "tap" functions of the base layer thumb keys is driven both by utility on the base layer and space-constraints on the num+sym layer:

* Space (obvious)
* Tab (Tab-completion, Alt+Tab, switching between UI elements, indentation)
* Underscore (snake_case function and variable names when programming)
* Apostrophe (I'm sure this doesn't need an explanation. It's obvious, isn't it?)

Enter is deliberately not on a thumb key to avoid pressing it accidentally. Backspace and Delete are quicker and more comfortable to hit repeatedly with one of the strong fingers on the nav+fn layer.

# QMK hacks

## Per-Key Mod-Tap Configuration

I configure mod-tap and layer-tap to prefer "tap" on finger keys and Space with `PERMISSIVE_HOLD`. This still allows fast modifier+key combos within the tapping term, but only if the modifier is held until after the other key is released. `IGNORE_MOD_TAP_INTERRUPT` is enabled to make mod-tap keys respect the `PERMISSIVE_HOLD` setting.

Layer-taps and Shift on the thumbs prefer "hold" with `HOLD_ON_OTHER_KEY`.

To make the tap-function of mod-taps on layers behave intuitively, a fix for [Bug17282](https://github.com/qmk/qmk_firmware/issues/17281) is needed.

## Mod-Tap with Shifted Symbols

Mod-Tap only works with 8-bit keycodes. Extended keycodes that apply a modifier (e.g. Shift for upper case letters) don't work with it out of the box. The QMK documentation suggests a [workaround that intercepts `process_record_user` and sends 16 bit keycodes with `tap_code16`](https://docs.qmk.fm/#/mod_tap?id=intercepting-mod-taps). I modified this idea to use the proper `register_code16` and `unregister_code16` calls to get tap+hold key-repeat.

## Moving '<' and '>' to the Num+Sym layer

Replacing '<' and '>' on the base layer is done with a small hack in `process_record_user` that sends different keycodes when `KC_COMM` or `KC_DOT` are pressed with Shift held.

## Nav+Fn layer lock

The locked layer is mostly a copy of the normal layer but with different thumb-key assignments. This allows overriding the locked Nav+Fn layer with Num+Sym or a base layer overlay. And it keeps the key combination to get to the Ctl+Macro layer consistent in all cases.

The FnLock key is also a layer-tap key for the Num+Sym layer. Therefore I cannot simply use `TG(L_NAV_FN_LOCKED)`, which is a 16-bit key code that doesn't work with `LT`. Instead I hijacked an unused 8-bit keycode for this key and process it myself in `process_record_user`.

# LICENSE
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
