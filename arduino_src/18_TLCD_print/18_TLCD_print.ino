#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2, 1, 0, 11, 10, 9);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello!!");
  lcd.setCursor(0,1);
  lcd.print("Hello!!");
  lcd.cursor();
  lcd.blink();
}

void loop() {

}
