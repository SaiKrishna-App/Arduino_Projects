int gas_sensor = A0;
float gas_level = 0;
int pin_buzzer = 4;
void setup()
{
  pinMode(gas_sensor , INPUT);
  Serial.begin(9600);
}

void loop()
{
  gas_level = analogRead(gas_sensor);
  if(gas_level >= 160)
  {
    tone( pin_buzzer , 350);
    delay(50);
    noTone(pin_buzzer);
  }
}