# LiquidCrystalArabic

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Version](https://img.shields.io/badge/version-1.0.0-green.svg)


This library allows Arduino-based boards to render Arabic text on Hitachi HD44780 LCDs (or compatible chipsets), managing its unique characteristics such as right-to-left writing, character shaping, and connection rules.

---

## Description

Key features include support for all common Arabic characters and ligatures (e.g., Lam-Alef), right-to-left text alignment, and an easy-to-use API for integrating Arabic text into Arduino projects. It is designed for Arduino enthusiasts, educators, and developers who need to display Arabic text on LCD screens for projects like signage, information displays, or educational tools.

Contributions and feedback are always welcome.

![1](https://github.com/user-attachments/assets/12880240-471a-43cc-8f5d-7119bdad414d)

---

## Dependencies

This library comes in **two versions**, each tailored for specific hardware setups:

1. **`LiquidCrystalArabic_I2C.h`**:  
   - Designed for **I2C LCD displays**.  
   - Extends the [LiquidCrystal I2C](https://docs.arduino.cc/libraries/liquidcrystal-i2c) library by **Frank de Brabander**.  
   - Use this version if your LCD is connected via I2C.

2. **`LiquidCrystalArabic.h`**:  
   - Designed for **normal (parallel) LCD displays**.  
   - Extends the [LiquidCrystal](https://docs.arduino.cc/libraries/liquidcrystal) library by **Arduino, Adafruit**.  
   - Use this version if your LCD is connected via parallel pins.


### Installation:
- Install the required base library (`LiquidCrystal I2C` or `LiquidCrystal`) before using this library.  
- The base libraries can be installed via the Arduino Library Manager. If multiple libraries with the same name exist, ensure you select the correct one by verifying the author's name.

---

## Features

- Supports rendering Arabic text on LCD displays of different sizes (such as 16x2 or 20x4).
- Allows writing Arabic `String` directly in the source code (e.g., ```lcd.printArabic("نص عربي")```).
- A custom-designed Arabic font that fits within the constraints of 8x5 pixels for each character.
- Supports all common Arabic characters and ligatures (e.g., Lam-Alef (لا)).
- Handles right-to-left text alignment and character shaping.
- Easy-to-use API for integrating Arabic text into Arduino projects.
- Lightweight and optimized for low-memory microcontrollers.
- Available in two versions: **I2C** and **normal (parallel)** LCD displays.

---

## Limitations
- **8-Character** Limit: HD44780-based LCDs typically support only 8 custom characters at a time (see the **"Handling the 8-Character Limit"** section below).

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

### Demo Usage Example for I2C:

<img align="right" src="https://github.com/user-attachments/assets/8489e859-9e4f-4aa3-be57-8ddae1b03ed2" style="height: 26ch;">

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

### Demo Usage Example for parallel:

<img align="right" src="https://github.com/user-attachments/assets/9f9ed3b5-28d7-4c4c-8756-d2811f2b3c83" style="height: 27ch;">

```cpp
#include "LiquidCrystalArabic.h"

LiquidCrystalArabic lcd(12, 11, 10, 9, 8, 7);

void setup() {
    lcd.begin(16, 2);
    lcd.printArabic("اللغة العربية");
}

void loop() {}
```

### Displaying Predefined LCD Characters Alongside Arabic Text
You can still print Predefined LCD Characters through the `lcd.print` method that is available in the original LiquidCrystal library. For example:

```cpp
#include "LiquidCrystalArabic_I2C.h"

LiquidCrystalArabic lcd(0x27, 16, 2);

void setup() {
    lcd.init();           
    lcd.backlight();
    lcd.printArabic("انجليزي"); // Direct Arabic text input
    lcd.setCursor(0, 0); // Set the cursor to the top left cell
    lcd.print("English"); // Print English text
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
    lcd.init();           
    lcd.backlight();
    lcd.printArabic("allGo alArbeo", true); // Check the "Romanized Arabic Mapping" section to understand this mapping.
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

## Public Methods

```cpp
LiquidCrystalArabic(uint8_t lcd_addr, uint8_t lcd_cols, uint8_t lcd_rows)
```
**Constructor**: Initializes the LCD with the specified I2C address, number of columns, and rows.  
- **Parameters**:
  - `lcd_addr`: I2C address of the LCD.
  - `lcd_cols`: Number of columns in the LCD.
  - `lcd_rows`: Number of rows in the LCD.

```cpp
void setCursorArabic(uint8_t x, uint8_t y)
```
Sets the cursor position for Arabic text, accounting for right-to-left writing.  
- **Parameters**:
  - `x`: Column position (0-based, from the right).
  - `y`: Row position (0-based).

```cpp
void moveCursorToLeft()
```
Moves the cursor one position to the left, wrapping around to the next row if necessary. Useful for right-to-left text rendering.

```cpp
void printArabic(String text, bool isRomanized = false, bool useLigatures = true)
```
Prints Arabic text on the LCD. Supports both direct Arabic text and Romanized Arabic input.  
- **Parameters**:
  - `text`: The text to display (Arabic or Romanized).
  - `isRomanized`: If `true`, treats the input as Romanized Arabic.
  - `useLigatures`: If `true`, handles Arabic ligatures (e.g., "لا") as single characters.

---

## Handling the 8-Character Limit

LCD displays typically support only **8 custom characters** at a time, which is a challenge for rendering Arabic text due to its many character forms, where each letter has different forms (e.g., "هـ" vs. "ـهـ" vs. "ـه" vs. "ه"). Here’s how the library makes the best use of this limitation:

#### Optimizations:
1. **Reuse Character Slots:** If the same character form appears multiple times, it only occupies **one slot** in the LCD's limited memory.
2. **Ligature Handling:** Ligatures such as "لا" (which combines ل and ا) are treated as a single character, consuming only one slot despite being two characters.
3. **Common Combinations**: Frequent Arabic combinations like "ال" (which combines ا and ل) are treated as a single character.
4. **Leverage Already Defined Characters:** Predefined characters (e.g., space) are printed without consuming additional custom character slots.
5. **User Control:** Users can display large texts by splitting them into smaller sections, ensuring the 8-character limit isn’t exceeded in each print call.

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
