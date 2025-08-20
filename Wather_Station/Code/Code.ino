#include <Adafruit_LiquidCrystal.h>
#define T_PIN A0
#define L_PIN A1
#define M_PIN A2
Adafruit_LiquidCrystal lcd(0);

class Sensors {
public:
  int t, l, m;
  static const char* n[];
  static const char* u[];
  static const char* ln[];

  Sensors() : t(0), l(0), m(0) {}

  void take() {
    t = map(analogRead(T_PIN), 20, 358, -40, 125);
    l = map(analogRead(L_PIN), 0, 13, 0, 100);
    m = map(analogRead(M_PIN), 0, 876, 0, 100);
  }

  void genData(int* b) {
    int d[] = {t, l, m};
    for(int i = 0; i < 3; i++) b[i] = d[i];
  }

  void print_lcd() {
    int d[3];
    genData(d);
    lcd.setCursor(0,0);
    for(int i = 0; i < 3; i++) {
      if(i == 2) lcd.setCursor(0,1);
      lcd.print(ln[i]);
      lcd.print(d[i]);
      lcd.print(" ");
      delay(100);
    }
  }

  void print_serial() {
    int d[3];
    genData(d);
    for(int i = 0; i < 3; i++) {
      Serial.print("[INFO] ");
      Serial.print(n[i]);
      Serial.print(": ");
      Serial.print(d[i]);
      Serial.println(u[i]);
    }
    Serial.println();
  }

  void copy(const Sensors& o) {
    t = o.t; l = o.l; m = o.m;
  }
};

//Define static members outside the class
const char* Sensors::n[]  = {"Temp", "Light", "Moist"};
const char* Sensors::u[]  = {"*C", "%", "%"};
const char* Sensors::ln[] = {"T:", "L:", "M:"};

//Now you can declare objects
Sensors now, prev;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.println("92100588034");
}

void loop() {
  now.take();
  if(prev.m > 99 && now.m < 100) lcd.clear();
  now.print_lcd();
  prev.copy(now);
  delay(1000);
}
