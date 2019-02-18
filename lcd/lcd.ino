#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
unsigned long lastMillis;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
}

void loop() { 
  showTextLCD("Hi", "Merunas");
}

// The LCD can show 32 characters where 16 are up and 16 are down
void showTextLCD(String message1, String message2) {
  if(millis() - lastMillis > 1000) {
    lastMillis = millis();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message1);
    lcd.setCursor(0, 1);
    lcd.print(message2);
  }
}
