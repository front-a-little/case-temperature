/***************************************************
  This is a example sketch demonstrating the graphics
  capabilities of the SSD1331 library  for the 0.96"
  16-bit Color OLED with SSD1331 driver chip

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/684

  These displays use SPI to communicate, 4 or 5 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>

// Pin setup
#define sclk 13
#define mosi 11
#define cs   10
#define rst  9
#define dc   8


// Color definitions
#define	BLACK             0x0000
#define COLOR_TEMPERATURE 0xFEA0
#define COLOR_RISING      0xF800
#define COLOR_FALLING     0x0400

// Item dimensions
#define iconWidth 20
#define iconHeight 20

Adafruit_SSD1331 display = Adafruit_SSD1331(&SPI, cs, dc, rst);
int w = 0;
int h = 0;

void setup(void) {
  display.begin();
  w = display.width()-5;
  h = display.height()-5;
  display.setTextWrap(false);
}

void loop() {
  display.fillScreen(BLACK);
  printTemperature("40");
  printRisingIcon();
  delay(5000);
  display.fillScreen(BLACK);
  printTemperature("23");
  printFallingIcon();
  delay(5000);
}

void printFallingIcon(){
  display.fillTriangle(w-iconWidth, h-iconHeight, w-iconWidth/2, h, w, h-iconHeight, COLOR_FALLING);
}

void printRisingIcon(){
  display.fillTriangle(w-iconWidth, h, w-iconWidth/2, h-iconHeight, w, h, COLOR_RISING);
}

void printTemperature(String temperature) {
  display.setCursor(0, 0);
  display.setTextColor(COLOR_TEMPERATURE);
  display.setTextSize(5);
  display.print(temperature);
  display.setTextSize(2);
  display.print("o");
  display.setTextSize(3);
  display.print("C");
}
