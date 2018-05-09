//************************************
//  example for KeyPad operation
//***********************************

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int read_val, range;

void setup() {
  Serial.begin(9600);
  lcd.begin(2, 16);
  lcd.clear();
}

void loop() {
  read_val = analogRead(1);
  range = (6787 / (read_val - 3)) - 4;
  lcd.print(range);
  delay(500);
  lcd.clear();
}
