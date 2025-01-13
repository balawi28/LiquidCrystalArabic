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

## Handling the 8-Character Limit

LCD displays typically support only **8 custom characters** at a time, which is a challenge for rendering Arabic text due to its many character forms, where each letter has different forms (e.g., "هـ" vs. "ـهـ" vs. "ـه" vs. "ه"). Here’s how the library makes the best use of this limitation:

#### Optimizations:
1. **Reuse Character Slots:** If the same character form appears multiple times, it only occupies **one slot**.
2. **Ligature Handling:** Ligatures such as "لا" (which combines ل and ا) are treated as a single character, consuming only one slot despite being two characters.
3. **Leverage Already Defined Characters:** Predefined or frequently used characters (e.g., space) are reused without consuming additional custom character slots.
4. **User Control:** Users can display large texts by splitting them into smaller sections, ensuring the 8-character limit isn’t exceeded in each print call.

#### Example:
For the text `"بلادي بلا حروب وحصار"`, the library:
1. **Start with an empty character set** (0/8 slots used).
2. **Process each letter**:

| **Character**       | **Form**          | **Action**                                      | **Slot** |
|---------------------|-------------------|------------------------------------------------|----------|
| **بـ**              | Initial form      | New character                                   | **1/8**  |
| **ـلا**             | Ligature          | Treated as **one character**                   | **2/8**  |
| **د**               | Isolated form     | New character                                   | **3/8**  |
| **ي**               | Isolated form     | New character                                   | **4/8**  |
| Space               | -                 | Already defined in LCD memory                  | -        |
| **بـ**              | Initial form      | Already defined in a previous step             | -        |
| **ـلا**             | Ligature          | Already defined in a previous step             | -        |
| **حـ**              | Initial form      | New character                                   | **5/8**  |
| **ـر**              | Final form        | New character                                   | **6/8**  |
| **و**               | Isolated form     | New character                                   | **7/8**  |
| **ب**               | Isolated form     | New character (different from initial form **بـ**)| **8/8**  |
| Space               | -                 | Already defined in LCD memory                  | -        |
| **و**               | Isolated form     | Already defined in a previous step             | -        |
| **حـ**              | Initial form      | Already defined in a previous step             | -        |

3. **Stop at 8 characters**: The next letters (**ـصـ** and **ـا** and **ر**) cannot be displayed because the 8-character limit is reached.

## Features

- Supports rendering Arabic text on LCD displays (such as 16x2 or 20x4).
- Allows writing Arabic `String` directly in the code (e.g., ```lcd.printArabic("نص عربي")```).
- A custom-designed Arabic font that fits within the constraints of 8x5 pixels for each character.
- Supports all common Arabic characters and ligatures (e.g., Lam-Alef).
- Handles right-to-left text alignment and character shaping.
- Easy-to-use API for integrating Arabic text into Arduino projects.
- Lightweight and optimized for low-memory microcontrollers.
- Available in two versions: **I2C** and **normal (parallel)** LCD displays.
