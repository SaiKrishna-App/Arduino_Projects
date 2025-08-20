# Arduino UNO + MQ Gas Sensor + Buzzer Circuit

## Components Used
- **1 × Arduino UNO**
- **1 × Breadboard**
- **1 × MQ Gas Sensor Module** (e.g., MQ-2 / MQ-135)
- **1 × Buzzer**
- **1 × Resistor** (typically 10kΩ for sensor voltage divider)
- **Jumper Wires**
- **USB Cable** (for powering Arduino)

---

## Circuit Connections

### Power Connections
- **Arduino 5V → Breadboard Positive Rail (+)**
- **Arduino GND → Breadboard Negative Rail (−)**

### MQ Gas Sensor
- **VCC Pin → 5V (Breadboard + rail)**
- **GND Pin → GND (Breadboard − rail)**
- **Analog Out (A0) → Arduino Analog Pin A5**
- **Load Resistor** (10kΩ) connected between **Analog Out (A0)** and **GND**

### Buzzer
- **Positive (long leg) → Arduino Digital Pin 7**
- **Negative (short leg) → GND (Breadboard − rail)**

---

## Working Principle
1. The **MQ Gas Sensor** detects gas concentration and outputs an analog voltage.  
2. The Arduino reads this analog signal from **A5**.  
3. If the detected gas value exceeds a threshold, the Arduino can activate the **buzzer** on **Pin 7**.  

---

## Notes
- Ensure the MQ sensor preheats for a few minutes before taking stable readings.  
- The resistor value (load resistor) may vary depending on the exact MQ sensor used.  
