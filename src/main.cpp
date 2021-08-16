#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 7
DHT dht(DHTPIN, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:

 Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000); // 2 секунды задержки
  float h = dht.readHumidity(); //Измеряем влажность
  float t = dht.readTemperature(); //Измеряем температуру
  if (isnan(h) || isnan(t)) {  // Проверка. Если не удается считать показания, выводится «Ошибка считывания», и программа завершает работу
    Serial.println("Ошибка считывания");
    return;
  }
  Serial.print("Hunidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Тemperature: ");
  Serial.print(t);
  Serial.println(" *C "); //Вывод показателей на экран
  lcd.setCursor(0, 0);

  lcd.print("Humidity : ");
    lcd.print(dht.readHumidity());
lcd.setCursor(0, 1);

  lcd.print("Temperature : ");
    lcd.print(dht.readTemperature());
  
}