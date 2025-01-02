# void_ergo_s

![void_ergo_s](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Ioannis Maliouris](https://github.com/Ioannis Maliouris)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make void_ergo_s:default

Flashing example for this keyboard:

    make void_ergo_s:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available


## Compile and reset keyboard

### Compile
```
qmk compile -kb void_ergo_s -km default
```

### Persist
1. Disconnect the keyboard from the pc
2. Disconnect the right half from the keyboard
3. Connect the left part of the keyboard to pc
4. Persist the changes
5. Disconnect it
6. Connect the keyboards between them
7. Connect both parts to pc

```
qmk flash void_ergo_s.hex -bl avr-dude-split-left
```
