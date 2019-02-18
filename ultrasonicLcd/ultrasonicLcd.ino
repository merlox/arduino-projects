#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
int lcdUpdateInterval = 100;
unsigned long lastMillis;
int echoPin = 2;
int triggerPin = 3;
long duration;
int distance;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() { 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  showTextLCD("Distance", String(distance) + " cm");
}

// The LCD can show 32 characters where 16 are up and 16 are down
void showTextLCD(String message1, String message2) {
  if(millis() - lastMillis > lcdUpdateInterval) {
    lastMillis = millis();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message1);
    lcd.setCursor(0, 1);
    lcd.print(message2);
  }
}
