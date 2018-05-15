//************************************
//  example for KeyPad operation
//***********************************

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int key_action;
int k, input;
int num = 1;
char keypad[6] = {'R', 'U', 'D', 'L', 'S', 'N'};
#define RIGHT     0
#define UP       1
#define DOWN     2
#define LEFT    3
#define SELECT  4
#define EVENTNON 5
int mode = RIGHT;

void setup() {
  Serial.begin(9600);
  lcd.begin(2, 16);
  lcd.clear();
}

void loop() {
  key_action = Keypad();
  if (num >= 98) {
    num = 1;
  }
  switch (key_action) {
    case RIGHT:
      mode = RIGHT;
      break;
    case LEFT:
      mode = LEFT;
      break;
    case UP:
      num = 1;
      lcd.clear();
      break;
    default:
      if (mode == RIGHT) {
        lcd.setCursor(0, 0);
      	lcd_print(num);
      	lcd.setCursor(0, 1);
      	lcd_print(num + 1);
	num++;
      }
  }
  delay(500);
}

void lcd_print(int i) {
  lcd.print(i);
  lcd.print(" + ");
  lcd.print(i + 1);
  lcd.print(" = ");
  lcd.print(i * 2 + 1);
}

int Keypad(){
  //  KEYPAD_RIGHT 0
  //  KEYPAD_UP 1
  //  KEYPAD_DOWN 2
  //  KEYPAD_LEFT 3
  //  KEYPAD_SELECT 4
  //  KEYPAD_NONE 5

 int NUM_KEYS = 5;
 int adc_key_val[5] = {30, 150, 360, 535, 760 };//閾値電圧設定
  input = analogRead(0);  //　　AD出力1023　=　5V
  Serial.print ("analog value=" );
  Serial.print(input);
  for (k = 0; k < NUM_KEYS; k++){
    if (input < adc_key_val[k]) {
      Serial.print(",  K= ");
      Serial.println(k);
      return k;
    }
  }
  if (k >= NUM_KEYS)
    k = 5;     // No valid key pressed
  return k;
}
