# Mantis

![mantis](https://github.com/fxkuehl/mantis/blob/main/assets/v0.3-photos/01-mantis-rgb-top.jpg?raw=true)

A 40-key unibody split ergo keyboard using custom hexagonal key caps, placing the hands close together and rotating them 30°. The hex grid naturally results in aggressive column stagger that is close enough to anatomically reasonable (with aggressive pinky and index finger stagger). The raised center PCB, sculpted key caps and switches rotated differently per row result in approximation of two key wells tented at 15°. Existing 3x5+3 layouts with 36 keys should be adaptable for this keyboard.

* Keyboard Maintainer: [Felix Kuehling](https://github.com/fxkuehl)
* Hardware Supported: [Mantis v0.3](https://github.com/fxkuehl/mantis)
* Hardware Availability: N/A

Make example for this keyboard (after setting up your build environment):

    make mantis:default

Flashing example for this keyboard:

    make mantis:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
