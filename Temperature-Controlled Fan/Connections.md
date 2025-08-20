# Arduino Project Connections

## Hardware Components List
- **Arduino Uno** (with USB cable)
- **16x2 LCD Display** (with I2C module)
- **Breadboard**
- **Potentiometer** (for LCD contrast adjustment)
- **LEDs** (multiple, with appropriate resistors)
- **Resistors** (e.g., 220Ω or 330Ω for LEDs)
- **Jumper Wires** (various colors for connections)
- **Push Button** (optional, depending on setup)

## Connection Details
### Arduino to Breadboard
- **GND** (Arduino) → GND (Breadboard)
- **5V** (Arduino) → VCC (Breadboard)
- **Digital Pins (D2-D7)** → Breadboard (connected to LCD data pins via jumper wires)
- **A4 (SDA)** → Breadboard (I2C SDA line)
- **A5 (SCL)** → Breadboard (I2C SCL line)

### LCD to Breadboard
- **VCC** → 5V (from Arduino via breadboard)
- **GND** → GND (from Arduino via breadboard)
- **SDA** → A4 (Arduino)
- **SCL** → A5 (Arduino)
- **Contrast Pin** → Middle pin of potentiometer
- **Potentiometer**:
  - One end → 5V
  - Other end → GND
  - Middle pin → LCD contrast pin

### LEDs to Breadboard
- **Anode (long leg)** → Digital pins (e.g., D8, D9) via current-limiting resistors
- **Cathode (short leg)** → GND

### Additional Notes
- Ensure proper power distribution and avoid short circuits.
- Double-check pin connections before powering on.
