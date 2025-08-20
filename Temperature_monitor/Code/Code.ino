#include <LiquidCrystal.h>
#define temp_sensor  A0
#define rs  0
#define en  1
#define d4  2
#define d5  3
#define d6  4
#define d7  5

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int temperature = 0;

void setup() {	
  lcd.begin(16,2);
  pinMode(temp_sensor , INPUT);
}

void loop() {
  temperature = analogRead(temp_sensor);
  temperature = map(temperature,20,358,-40,125);
  lcd.clear();
  lcd.print("TEMP : ");
  lcd.print(temperature);
  lcd.print(" \xB0""C");
  delay(200);
}