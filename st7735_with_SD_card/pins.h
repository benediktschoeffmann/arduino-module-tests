/*
Screen Side   SD side
===========   =======
LED           SD_SCK
SCK           SD_MISO
SDA           SD_MOSI
A0            SD_CS
RESET
CS
GND
VCC

That would be 8+4 pinb which is way to much.


So far, I found the following information: 
SPI pins for Arduino Nano 
D11 (MOSI - Microcontroller out, Serial In -> Display),
D12 (MISO - Microcontroller in, Serial Out -> SD),
D13 (SCK). 
CS (Chip Select) can be any pin, commonly D10 is used. 

So lets try this:

D13 (SPI Clock) to both SCK and SD_SCK
D12 (MISO) to SD_MISO
D11 (MOSI) to SDA
D10 (Chip select for Screen) to CS
D9  (PWM) to LED
D8  (Chip select for SD) to SD_CS
D7  (Data/Command for TFT)
*/

#ifndef _PINS_H
#define _PINS_H

  const int SPI_SCK = 13;
  const int SPI_MISO = 12;
  const int SPI_MOSI = 11;
  const int TFT_CS = 10;
  const int PWDM_LED = 9;
  const int SD_CS = 8;
  const int TFT_DC = 7;

#endif