//************************************
//  example for KeyPad operation
//***********************************

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int key_action;
int k, input;
char keypad[6] = {'R', 'U', 'D', 'L', 'S', 'N'};
#define RIGHT     0
#define UP       1
#define DOWN     2
#define LEFT    3
#define SELECT  4
#define EVENTNON 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(2, 16);
  lcd.clear();
}

void loop() {
  lcd.clear();
  key_action = Keypad();
  lcd.setCursor(0, 0);
  lcd.print(" Selected key: " );
  lcd.setCursor(0, 1);
  lcd.print("Lev=");
  lcd.print(input);
  lcd.print(",K=");
  lcd.print (key_action);
  lcd.print(", ");
  lcd.print(keypad[key_action]);
  delay (1000);
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
