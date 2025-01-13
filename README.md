# LiquidCrystalArabic

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Version](https://img.shields.io/badge/version-1.0.0-green.svg)

This library enables Arduino-based boards to control Hitachi HD44780LCD or any other LCD with a compatible chipset. It handles Arabic script's unique characteristics, such as right-to-left writing, character shaping, and connectivity rules. Perfect for projects requiring Arabic text output on LCD screens.

**Note:** This library comes in two versions—one for I2C LCD displays and one for normal (parallel) LCD displays. Choose the version that matches your hardware setup. The I2C version of the library extends [LiquidCrystal I2C](https://docs.arduino.cc/libraries/liquidcrystal-i2c) by `Frank de Brabander`, while the normal version extends  [LiquidCrystal](https://docs.arduino.cc/libraries/liquidcrystal) by `Arduino, Adafruit`.

---

## Description

Key features include support for all common Arabic characters and ligatures (e.g., Lam-Alef), right-to-left text alignment, and an easy-to-use API for integrating Arabic text into Arduino projects. It is designed for Arduino enthusiasts, educators, and developers who need to display Arabic text on LCD screens for projects like signage, information displays, or educational tools.

Contributions and feedback are always welcome.

---

## Features

- Supports rendering Arabic text on LCD displays (such as 16x2 or 20x4).
- Allows writing Arabic `String` directly in the code (e.g., ```lcd.printArabic("نص عربي")```).
- A custom-designed Arabic font that fits within the constraints of 8x5 pixels for each character.
- Supports all common Arabic characters and ligatures (e.g., Lam-Alef).
- Handles right-to-left text alignment and character shaping.
- Easy-to-use API for integrating Arabic text into Arduino projects.
- Lightweight and optimized for low-memory microcontrollers.
- Available in two versions: **I2C** and **normal (parallel)** LCD displays.
