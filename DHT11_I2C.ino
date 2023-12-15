#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht11.h>

#define DHT11PIN 4

dht11 DHT11;

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Serial.begin(9600);

  lcd.init();                      
  lcd.backlight();                 
  lcd.setCursor(0, 0);
  lcd.print("Kelembapan: ");
  lcd.setCursor(0, 1);
  lcd.print("Suhu: ");

}

void loop() {
  int chk = DHT11.read(DHT11PIN);

  lcd.setCursor(11, 0);
  lcd.print((int)DHT11.humidity);
  lcd.print("% ");

  lcd.setCursor(6, 1);
  lcd.print((int)DHT11.temperature);
  lcd.print(" C");

  delay(2000);
}
