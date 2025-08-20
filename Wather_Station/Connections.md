# Arduino Connections for Temperature, Soil Moisture, and Light Sensor

## Components
- Arduino Uno
- TMP36 Temperature Sensor
- Soil Moisture Sensor
- 16x2 LCD Display (with I2C module)
- Light Sensor (Photoresistor with 10kΩ resistor)
- Breadboard
- Jumper wires

## Connections

### Arduino Uno to TMP36 Temperature Sensor
- TMP36 VCC to Arduino 5V
- TMP36 GND to Arduino GND
- TMP36 Signal (middle pin) to Arduino A0

### Arduino Uno to Soil Moisture Sensor
- Soil Moisture Sensor VCC to Arduino 5V
- Soil Moisture Sensor GND to Arduino GND
- Soil Moisture Sensor Signal to Arduino A1

### Arduino Uno to 16x2 LCD Display (I2C)
- LCD VCC to Arduino 5V
- LCD GND to Arduino GND
- LCD SDA to Arduino A4
- LCD SCL to Arduino A5

### Arduino Uno to Light Sensor (Photoresistor)
- Photoresistor one leg to Arduino 5V
- Photoresistor other leg to Arduino A2
- 10kΩ resistor from Arduino A2 to Arduino GND

## Notes
- Ensure proper power supply via USB or external power.
- Double-check all connections before powering on.