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

---

## Limitations
- **8-Character** Limit: LCD displays typically support only 8 custom characters at a time (see the **"Handling the 8-Character Limit"** section below).

---

## Usage

The `printArabic` function is the core method for displaying Arabic text on the LCD. It handles right-to-left text alignment, character shaping, and ligatures. Below is a detailed explanation of its parameters and usage:

### Function Signature:
```cpp
void printArabic(String text, bool isRomanized=false, bool useLigatures=true);
```

### Arabic Text Input
The library supports direct Arabic text input in the Arduino IDE. You can write Arabic strings directly in your code, and the library will handle the rendering on the LCD. For example:
```cpp
lcd.printArabic("اللغة العربية"); // Direct Arabic text input
```

### Demo Usage Example:
```cpp
#include "LiquidCrystalArabic_I2C.h"

LiquidCrystalArabic lcd(0x27, 16, 2);

void setup() {
    lcd.init();           
    lcd.backlight();
    lcd.printArabic("اللغة العربية");
}

void loop() {}
```

### Romanized Arabic Fallback
If your IDE or compiler has issues with direct Arabic text (e.g., syntax or compilation errors), you can use Romanized Arabic as an alternative. The library includes a built-in mapping of Romanized characters to their corresponding Arabic Unicode values. Simply pass the Romanized text and set the isRomanized parameter to true:

For example:
```cpp
#include "LiquidCrystalArabic_I2C.h"

LiquidCrystalArabic lcd(0x27, 16, 2);

void setup() {
    Serial.begin(9600);
    lcd.init();           
    lcd.backlight();
    lcd.printArabic("allGo alArbeo", true);
}

void loop() {}
```

#### Romanized Arabic Mapping
The following mapping is used to convert Romanized characters to Arabic:

| **Romanized Character** | **Arabic Letter** |
|--------------------------|-------------------|
| `a`                      | ا                 |
| `b`                      | ب                 |
| `t`                      | ت                 |
| `T`                      | ث                 |
| `j`                      | ج                 |
| `H`                      | ح                 |
| `K`                      | خ                 |
| `d`                      | د                 |
| `Z`                      | ذ                 |
| `r`                      | ر                 |
| `z`                      | ز                 |
| `s`                      | س                 |
| `V`                      | ش                 |
| `X`                      | ص                 |
| `x`                      | ض                 |
| `P`                      | ط                 |
| `p`                      | ظ                 |
| `A`                      | ع                 |
| `G`                      | غ                 |
| `f`                      | ف                 |
| `q`                      | ق                 |
| `k`                      | ك                 |
| `l`                      | ل                 |
| `m`                      | م                 |
| `n`                      | ن                 |
| `h`                      | ه                 |
| `w`                      | و                 |
| `e`                      | ي                 |
| `c`                      | ء                 |
| `W`                      | آ                 |
| `u`                      | ى                 |
| `U`                      | أ                 |
| `O`                      | ؤ                 |
| `Y`                      | ئ                 |
| `M`                      | ـ (Kashida)       |
| `o`                      | ة                 |
| `i`                      | إ                 |

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
