#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //(บางรุ่นจะเป็น 0x3f, ความยาว, ความกว้าง)
DHT dht(2, DHT22); //(pin digitalที่เราใช้,ชนิดรุ่นเซนเซอร์)
float temp_c;
float humidity;
void setup() {
   
   lcd.begin();
   lcd.backlight();
   //lcd.noBacklight();
   Serial.begin(9600);
   dht.begin();
}

void loop() {
  temp_c = dht.readTemperature();
  humidity = dht.readHumidity();

  Serial.print("Temperature: ");    //ทำการเช็ค sensor
  Serial.print(temp_c);
  Serial.print(" C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\n");

  lcd.home();             //แสดงผลออกทางจอ LCD
  //lcd.setCursor(0,0)      // ค่า default โดยเริ่มเป็น 0,0 อยู่แล้ว
  lcd.print("Temp: ");
  lcd.print(temp_c);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
  lcd.print(humidity);
  lcd.print(" %");
  
  delay(2000); //ความถี่ของตัว sensor คือ 0.5 Hz ใช้เวลาในการวัด 2 วินาทีต่อครั้ง

  

}
