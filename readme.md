# rpkeebs RPWK21

- [More information on Printables](https://www.printables.com/model/1612022-rpkeebs-wk78-another-janky-keyboard-project-based)
- [Brutalist housing 5 degree incline](https://www.tinkercad.com/things/j2OqCod8cQN-rpwk21-brutalist-housing-5-deg-incline)
- [Brutalist housing 3.5 degree incline](https://www.tinkercad.com/things/h4vcry9e0PI-rpwk21-brutalist-housing-35-deg-incline)

## Getting started

- Ensure you have qmk properly installed and for convenience also install QMK Toolbox
- Clone repo https://github.com/vial-kb/vial-qmk first
- Then clone this repo in the keyboards folder;

```shell
git clone https://github.com/vial-kb/vial-qmk.git MyKBDProject
git clone https://github.com/rmpel/qmk-vial-keyboard-wk21.git MyKBDProject/keyboards/rpkeebs/rpwk21
```

## This is for an existing PCB;

- https://nl.aliexpress.com/item/1005008447490532.html
- Numpad PCB WK 1.2MM
- TX SUO Numpad PCB 1.2MM WK hotswap PCB

## A custom QMK firmware for the SUO 21-key Numpad WK21 keyboard, featuring:

- **MCU**: STM32F411CEU6
- **Layout**: 21-key Numpad
- **Matrix**: 6 rows × 4 columns (direct GPIO, no shift register)
- **Features**: Per-key RGB + underglow (WS2812), Vial support

## How to program?

- First to put the device in DFU mode, you need to short the Boot0 line to Logic High when plugging in.
- I found the VDD line connected to a chip left of the MCU and the Boot0 line connected to a pull-down resistor. You can short this with tweezers or a paperclip; I soldered wires.
- If you program my firmware, you only need this once! You can powerup with ESC held down to do the same from then on.
- Then you need to unlock the flash memory; `dfu-util -a 0 -s :unprotect:force`
- Then you can build and program this QMK/VIAL firmware; `qmk flash -kb rpkeebs/rpwk21 -km vial`

# WARNING

- Flashing a custom firmware voids warranty!
- Flashing can go wrong, you might brick your PCB!
- Just because this worked for ME does not mean it will work for YOU.
- OpenAI Claude or Google Gemini can help you! - Claude helped me.

# AI WARNING

- Yes, this firmware ws configured with help of AI.
- I told claude what I wanted, claude messed it up.
- I told claude how to do better, claude fixed it.
- I asked claude to guide me through measurements with a multimeter in continuity to find the matrix layout, then the LED layout
- And still, claude F***ed up, but, after 8 long hours, THIS WORKS. The entire configuration is PERFECT.

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
