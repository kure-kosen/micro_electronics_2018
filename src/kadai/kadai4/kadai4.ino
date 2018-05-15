//************************************
//  example for KeyPad operation
//***********************************

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int read_val;
float r, v, t;

void setup() {
  Serial.begin(9600);
  lcd.begin(2, 16);
  lcd.clear();
}

void loop() {
  read_val = analogRead(1);
  v = read_val * 5.0 / 1023.0;
  r = (10000.0*v)/(5.0 - v);
  t = 1.0/(log(r/10000.0)/3380.0+(1.0/297.0)) - 273.0;
  lcd.print(t);

  delay(500);
  lcd.clear();
}
