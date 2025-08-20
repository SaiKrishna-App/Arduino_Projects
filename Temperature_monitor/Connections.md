# Connections File for Arduino Uno Temperature Sensor with LCD

# Arduino Uno Pins
GND -> Breadboard GND
5V -> Breadboard VCC
A0 -> LM35 Vout
Digital 2 -> LCD RS
Digital 3 -> LCD Enable
Digital 4 -> LCD D4
Digital 5 -> LCD D5
Digital 6 -> LCD D6
Digital 7 -> LCD D7

# LM35 Temperature Sensor
VCC -> Breadboard VCC (via 220 ohm resistor)
GND -> Breadboard GND
Vout -> Arduino A0

# LCD Display
VSS -> Breadboard GND
VDD -> Breadboard VCC
V0 -> 10k Potentiometer wiper (contrast adjustment)
RS -> Arduino Digital 2
RW -> Breadboard GND
Enable -> Arduino Digital 3
D4 -> Arduino Digital 4
D5 -> Arduino Digital 5
D6 -> Arduino Digital 6
D7 -> Arduino Digital 7
A -> Breadboard VCC (via 220 ohm resistor)
K -> Breadboard GND