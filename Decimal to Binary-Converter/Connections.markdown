# Arduino Decimal to Binary Converter

This project implements a simple calculator using an Arduino Uno, a 4x4 keypad, and an I2C LCD display. The calculator Converts Decimal to Binay conversion and includes a clear function.

## Hardware Setup
- **Arduino Uno**: The main microcontroller.
- **4x4 Keypad**: Used for inputting numbers and operations.
- **I2C LCD (16x2)**: Displays the calculator input and results.

### Connections
- **Keypad**:
  - Rows: Connected to pins 9, 8, A0, A1.
  - Columns: Connected to pins A2, A3, A4, A5.
- **LCD (I2C)**:
  - Address: Typically 0x27 (adjust if needed).
  - Connected via I2C pins (SDA and SCL on Arduino Uno, typically A4 and A5).

## Software Overview
The code is written in C++ and uses the following libraries:
- `Wire.h`: For I2C communication with the LCD.
- `LiquidCrystal_I2C.h`: For controlling the LCD.
- `Keypad.h`: For handling keypad input.

### Calculation Logic
if (decValue == 0) binaryNum = "0";
      else {
        while (decValue > 0) {
          binaryNum = String(decValue % 2) + binaryNum;
          decValue /= 2;
        }
      }

## Notes
- Ensure the I2C address (0x27 or 0x3F) matches your LCD module.
- The calculator uses integer arithmetic, so decimal results are truncated.
- Reset the Arduino if the LCD displays unexpected behavior.