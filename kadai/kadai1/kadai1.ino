//************************************
//  example for KeyPad operation
//***********************************

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int k = 1;
String out;

void setup() {
  Serial.begin(9600);
  lcd.begin(2, 16);
  lcd.clear();
}

void loop() {
  if (k >= 98) {
    k = 1;
  }
  lcd.setCursor(0, 0);
  lcd_print(k);
  lcd.setCursor(0, 1);
  lcd_print(k + 1);
  k++;
  delay (500);
}

void lcd_print(int i) {
  lcd.print(i);
  lcd.print(" + ");
  lcd.print(i + 1);
  lcd.print(" = ");
  lcd.print(i * 2 + 1);
}