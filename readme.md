# rpkeebs RPWK21

- [More information on Printables](https://www.printables.com/model/1676148-rpkeebs-wk21-a-numpad-for-the-rpwk87-project)
- [Brutalist Numpad housing 5 degree incline](https://www.tinkercad.com/things/3jfW5QKoDV1-rpwk21-brutalist-housing-5-deg-incline)

## Getting started

- Ensure you have qmk properly installed and for convenience also install QMK Toolbox
- Clone repo https://github.com/vial-kb/vial-qmk first
- Then clone this repo in the keyboards folder;

```shell
git clone https://github.com/vial-kb/vial-qmk.git MyKBDProject
git clone https://github.com/rmpel/qmk-vial-keyboard-wk21.git MyKBDProject/keyboards/rpkeebs/rpwk21
```

## This is for a homebrew PCB, as a companion for this PCB;

- https://nl.aliexpress.com/item/1005008447490532.html
- TX SUO TKL PCB 1.2MM WK hotswap PCB

## PCB Design;
- [Remons Janky NumPad PCB](https://github.com/rmpel/rpkeebs-suo-tx-numpad)

## A custom QMK firmware for the 21-key Numpad WK21 keyboard, featuring:

- **MCU**: STM32F411CEU6 (probably overkill for a numpad, but it's what I had)
- **Layout**: 21-key Numpad
- **Matrix**: 6 rows × 4 columns (direct GPIO, no shift register)
- **Features**: Per-key RGB + underglow (WS2812), Vial support

## How to program?

- First to put the device in DFU mode, you need to push the Boot button while plugging in the USB cable.
- Then you can build and program this QMK/VIAL firmware; `qmk flash -kb rpkeebs/rpwk21 -km vial`
- After the first time, you can put the board in DFU mode by pressing M4 + M1 (FN + M1) while plugged in.

# AI WARNING

- Yes, this firmware ws configured with help of AI.
- I told claude what I wanted, claude messed it up.
- I told claude how to do better, claude fixed it.

---

## Hardware Overview

### Microcontroller
- **STM32F411CEU6** (Blackpill compatible)
- 100 MHz ARM Cortex-M4
- 512KB Flash, 128KB RAM
- USB 2.0 Full Speed

### Matrix Configuration
- **6 rows** (direct GPIO pins)
- **4 columns** (direct GPIO pins)
- **Diode direction**: ROW2COL

### RGB LEDs (WS2812)
- 21 per-key LEDs
- 12 underglow LEDs
- 1 status LED (under NumLock key)

---

## Resources

- **QMK Firmware Docs**: https://docs.qmk.fm/
- **Vial Documentation**: https://get.vial.today/docs/
- **STM32F411 Datasheet**: https://www.st.com/resource/en/datasheet/stm32f411ce.pdf
- **74HC595 Datasheet**: https://www.ti.com/lit/ds/symlink/sn74hc595.pdf
- **WS2812B Datasheet**: https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf
- **QMK Discord**: https://discord.gg/qmk

---

## Default keymap

Layer 0 (Base Layer):

```
╔═══════╗╔═══════╗╔═══════╗╔═══════╗
║  F13  ║║  F14  ║║  F15  ║║  FN   ║
║       ║║       ║║       ║║ Layer1║
╚═══════╝╚═══════╝╚═══════╝╚═══════╝
╔═══════╗╔═══════╗╔═══════╗╔═══════╗
║ Num   ║║   /   ║║   *   ║║   -   ║
║  Lock ║║       ║║       ║║       ║
╚═══════╝╚═══════╝╚═══════╝╚═══════╝
╔═══════╗╔═══════╗╔═══════╗╔═══════╗
║   7   ║║   8   ║║   9   ║║       ║
║       ║║       ║║       ║║       ║
╚═══════╝╚═══════╝╚═══════╝║   +   ║
╔═══════╗╔═══════╗╔═══════╗║       ║
║   4   ║║   5   ║║   6   ║║       ║
║       ║║       ║║       ║║       ║
╚═══════╝╚═══════╝╚═══════╝╚═══════╝
╔═══════╗╔═══════╗╔═══════╗╔═══════╗
║   1   ║║   2   ║║   3   ║║   E   ║
║       ║║       ║║       ║║   n   ║
╚═══════╝╚═══════╝╚═══════╝║   t   ║
╔════════════════╗╔═══════╗║   e   ║
║       0        ║║   .   ║║   r   ║
║                ║║       ║║       ║
╚════════════════╝╚═══════╝╚═══════╝

The dot can be a comma when you are on a mac depending on your keyboard language.
```

Layer 1 (Function Layer):

```
╔═══════╗╔═══════╗╔═══════╗╔═══════╗
║ Boot  ║║   ▽   ║║ Toggle║║   ▽   ║
║ Loadr ║║       ║║ Layer2║║       ║
╚═══════╝╚═══════╝╚═══════╝╚═══════╝
╔═══════╗╔═══════╗╔═══════╗╔═══════╗
║   ▽   ║║   ▽   ║║   ▽   ║║   ▽   ║
║       ║║       ║║       ║║       ║
╚═══════╝╚═══════╝╚═══════╝╚═══════╝
╔═══════╗╔═══════╗╔═══════╗╔═══════╗
║ RGB   ║║ RGB   ║║ RGB   ║║   ▽   ║
║ OnOff ║║ Mode+ ║║ Hue+  ║║       ║
╚═══════╝╚═══════╝╚═══════╝║       ║
╔═══════╗╔═══════╗╔═══════╗║       ║
║ RGB   ║║ RGB   ║║ RGB + ║║       ║
║ Val.+ ║║ Val.- ║║ Speed ║║       ║
╚═══════╝╚═══════╝╚═══════╝╚═══════╝
╔═══════╗╔═══════╗╔═══════╗╔═══════╗
║ RGB   ║║ RGB   ║║ RGB - ║║   ▽   ║
║ Sat+  ║║ Sat-  ║║ Speed ║║       ║
╚═══════╝╚═══════╝╚═══════╝║       ║
╔════════════════╗╔═══════╗║       ║
║        ▽       ║║   ▽   ║║       ║
║                ║║       ║║       ║
╚════════════════╝╚═══════╝╚═══════╝

```

Layer 2 (Mouse layer, use FN + M3 to toggle on/off):

```
╔═══════╗╔═══════╗╔═══════╗╔═══════╗
║   ▽   ║║   ▽   ║║   ▽   ║║ MO(3) ║
║       ║║       ║║       ║║       ║
╚═══════╝╚═══════╝╚═══════╝╚═══════╝
╔═══════╗╔═══════╗╔═══════╗╔═══════╗
║   ▽   ║║   ▽   ║║   ▽   ║║   ▽   ║
║       ║║       ║║       ║║       ║
╚═══════╝╚═══════╝╚═══════╝╚═══════╝
╔═══════╗╔═══════╗╔═══════╗╔═══════╗
║ Mouse ║║ Mouse ║║ Mouse ║║   ▽   ║
║ Btn 1 ║║   ↑   ║║ Btn 2 ║║       ║
╚═══════╝╚═══════╝╚═══════╝║       ║
╔═══════╗╔═══════╗╔═══════╗║       ║
║ Mouse ║║ Mouse ║║ Mouse ║║       ║
║   ←   ║║   ↓   ║║   →   ║║       ║
╚═══════╝╚═══════╝╚═══════╝╚═══════╝
╔═══════╗╔═══════╗╔═══════╗╔═══════╗
║ Mouse ║║ Mouse ║║ Mouse ║║ Mouse ║
║ Wh.Up ║║ Wh.Dn ║║ Wh.Lf ║║ Wh.Rt ║
╚═══════╝╚═══════╝╚═══════╝║       ║
╔════════════════╗╔═══════╗║       ║
║     Mouse      ║║   ▽   ║║       ║
║     Btn 3      ║║       ║║       ║
╚════════════════╝╚═══════╝╚═══════╝
```

Layer 3 is currently the same as Layer 1.


## License

This firmware is released under the GPL v2 License. See `LICENSE` file for details.

---

## Contributing

If you improve this firmware or discover the correct pin mappings, please consider:
1. Opening an issue or pull request on the QMK repository
2. Sharing your findings with the community
3. Documenting any hardware modifications or discoveries

---

## Acknowledgments

- QMK Firmware team for the amazing framework
- Vial team for the GUI configuration tool
- Claude AI for extensive assistance with firmware configuration

---

**Maintainer**: rmpel

**Last Updated**: 2026-02-21
