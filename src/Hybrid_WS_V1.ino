#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#define OLED_DC     5
#define OLED_CS     6
#define OLED_RESET  4
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, 11, 13, 5, 4, 6);

#define DHTPIN 7
#define DHTTYPE DHT22
#define LDRPIN A7

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  display.clearDisplay();
  display.display();
  delay(1000);
}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int isik = analogRead(LDRPIN);


  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);


  display.setTextSize(1);
  display.setCursor(10, 0);
  display.println("HYBRID ELECRTONICS");
  display.drawLine(0, 10, 127, 10, SSD1306_WHITE);


  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print("T:"); display.print(t, 1); display.println("C");
  display.print("H:%"); display.println((int)h);

  display.setTextSize(1);
  display.setCursor(0, 55);
  display.print("Isik Seviyesi: "); display.print(isik);


  display.display(); 
  

  Serial.print("Nem: % "); Serial.print(h);
  Serial.print(" Sicaklik: "); Serial.print(t); Serial.println(" C");

  delay(2000);
}
