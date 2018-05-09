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
  v = read_val * float(5) / float(1023);
  r = (10000.0*v)/(5.0 - v);
  t = float(1)/(log(r/float(10000))/float(3380)+(float(1)/float(297)));
  lcd.print(t - 273);

  Serial.println(read_val);
  Serial.println(v);
  Serial.println(r);
  Serial.println(t);
  Serial.println();
  
  delay(500);
  lcd.clear();
}
