#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// ================= LCD (I2C) =================
// Address is usually 0x27 or 0x3F, adjust if needed
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ================= KEYPAD SETUP =================
const byte ROWS = 4, COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};
byte rowPins[ROWS] = {9, 8, A0, A1};  
byte colPins[COLS] = {A2, A3, A4, A5}; 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// ================= CALCULATOR VARIABLES =================
String num1 = "", num2 = "";
char op = 0;
bool secondNum = false;

void setup() {
  lcd.init();       // initialize the LCD
  lcd.backlight();  // turn on backlight
  lcd.print("Calc Ready!");
  delay(1000);
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();

  if (!key) return; // no key pressed

  if (key >= '0' && key <= '9') {       // Number pressed
    if (!secondNum) { num1 += key; lcd.setCursor(0,0); lcd.print(num1); }
    else { num2 += key; lcd.setCursor(0,1); lcd.print(num2); }
  }

  else if (key=='+' || key=='-' || key=='*' || key=='/') { // Operator
    op = key; secondNum = true;
    lcd.setCursor(15,0); lcd.print(op);
  }

  else if (key=='=') {                  // Calculate
    long a=num1.toInt(), b=num2.toInt(), res=0;

    if (op=='+') res=a+b;
    else if (op=='-') res=a-b;
    else if (op=='*') res=a*b;
    else if (op=='/' && b!=0) res=a/b;
    else { lcd.clear(); lcd.print("Err: Divide0"); return; }

    lcd.clear();
    lcd.print(a); lcd.print(op); lcd.print(b);
    lcd.setCursor(0,1); lcd.print("= "); lcd.print(res);

    // reset for next calc
    num1=num2=""; op=0; secondNum=false;
  }

  else if (key=='C') {                  // Clear
    num1=num2=""; op=0; secondNum=false;
    lcd.clear();
  }
}
