#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//--- Pin constants
const byte TEMP_PIN   = A0;
const byte GREEN_LED  = 10;
const byte RED_LED    = 9;
const byte FAN_PIN    = 7;
const byte BUZZER_PIN = 8;

void setup() {
  pinMode(GREEN_LED,  OUTPUT);
  pinMode(RED_LED,    OUTPUT);
  pinMode(FAN_PIN,    OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  static int lastC      = INT16_MIN;                 // stores previous reading
  int raw      = analogRead(TEMP_PIN);               // sensor value
  int celsius  = map((raw - 20) * 3.04, 0, 1023, -40, 125);
  int fahren   = celsius * 9 / 5 + 32;

  //— Update screen only when temperature changes
  if (celsius != lastC) {
    lastC = celsius;
    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("C: "); lcd.print(celsius);
    lcd.setCursor(8, 0); lcd.print("F: "); lcd.print(fahren);
  }

  //— Actuators: HIGH = true condition
  digitalWrite(GREEN_LED,  celsius <= 30);
  digitalWrite(RED_LED,    celsius >= 31);
  digitalWrite(FAN_PIN,    celsius > 40);
  digitalWrite(BUZZER_PIN, celsius > 40);

  delay(100);
}
