# Arduino Calculator Project

This project implements a simple calculator using an Arduino Uno, a 4x4 keypad, and an I2C LCD display. The calculator supports basic arithmetic operations (addition, subtraction, multiplication, and division) and includes a clear function.

## Hardware Setup
- **Arduino Uno**: The main microcontroller.
- **4x4 Keypad**: Used for inputting numbers and operations.
- **I2C LCD (16x2)**: Displays the calculator input and results.

### Connections
- **Keypad**:
  - Rows: Connected to pins 9, 8, A0, A1.
  - Columns: Connected to pins A2, A3, A4, A5.
- **LCD (I2C)**:
  - Address: Typically 0x27 or 0x3F (adjust if needed).
  - Connected via I2C pins (SDA and SCL on Arduino Uno, typically A4 and A5).

## Software Overview
The code is written in C++ and uses the following libraries:
- `Wire.h`: For I2C communication with the LCD.
- `LiquidCrystal_I2C.h`: For controlling the LCD.
- `Keypad.h`: For handling keypad input.

### Key Variables
- `num1` and `num2`: Store the first and second numbers as strings.
- `op`: Stores the arithmetic operator (+, -, *, /).
- `secondNum`: Boolean flag to track whether the second number is being entered.

### Functions
- **`setup()`**: Initializes the LCD, turns on the backlight, and displays "Calc Ready!" for 1 second.
- **`loop()`**: Continuously checks for keypad input and performs the following actions:
  - **Number Input**: Appends digits to `num1` or `num2` and updates the LCD.
  - **Operator Input**: Sets the operator and prepares for the second number.
  - **Equals ('=')**: Performs the calculation based on the operator and displays the result.
  - **Clear ('C')**: Resets all variables and clears the LCD.

### Calculation Logic
- Converts `num1` and `num2` to integers using `toInt()`.
- Performs the selected operation and displays the result on the LCD.
- Handles division by zero error with an "Err: Divide0" message.

## Usage
1. Enter the first number using the keypad.
2. Press an operator key (+, -, *, /).
3. Enter the second number.
4. Press '=' to see the result.
5. Press 'C' to clear and start a new calculation.

## Notes
- Ensure the I2C address (0x27 or 0x3F) matches your LCD module.
- The calculator uses integer arithmetic, so decimal results are truncated.
- Reset the Arduino if the LCD displays unexpected behavior.