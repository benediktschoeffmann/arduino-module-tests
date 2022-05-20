#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SdFat.h>
#include <Adafruit_SPIFlash.h>
#include <Adafruit_ImageReader.h>
#include "pins.h"

SdFat SD;
Adafruit_ImageReader reader(SD);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, -1); // connect to arduino reset


void setup() {
  Serial.begin(9600);
  Serial.println("serial started.");

  tft.initR(INITR_BLACKTAB);
  Serial.println("tft started.");

  Serial.println("trying to start filesystem.");
  if (!SD.begin(SD_CS, SD_SCK_MHZ(10))) { // Breakouts require 10 MHz limit due to longer wires
    Serial.println(F("SD begin() failed"));
    for (;;);
  }
  Serial.println("Success!");
  tft.fillScreen(ST7735_BLUE);
}

void loop() {

}
