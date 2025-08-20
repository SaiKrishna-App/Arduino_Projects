#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
int trigPin = 5;    // TRIG pin
int echoPin = 4;    // ECHO pin

float duration, distance;

void setup()
{
  Serial.begin(9600);  
lcd.begin (16,2);
  lcd.init(); //initializes lcd
  lcd.backlight();//turns on backlight of lcd

lcd.home ();//moves cursor to home positio of lcd

delay(1000);
lcd.clear();
  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
}

void loop()
{ // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10000);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance = 0.017 * duration;
  Serial.println(distance);

  // print the value to lcd
 lcd.print(distance);
delay(2000);
lcd.clear();
}