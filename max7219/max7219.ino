/**
Load the LedControl library either over the Arduino Manager or 
on the authors (Eberhard Fahle) website: 

https://wayoda.github.io/LedControl/
*/

#include <LedControl.h>

#define CLK         13 // Clock 
#define CS          10 // ChipSelect    
#define DIN         11 // Data In
#define MAX_DEVICES 8  // Maximum number that can be theoretically controlled

int DELAY = 50;  // Blink time in ms
int ROWS = 8;
int COLS = 8;

// Number of connected devices
int kDevices;

LedControl lc = LedControl(DIN, CS, DIN, MAX_DEVICES); 

void setup() {
  kDevices = lc.getDeviceCount();

  // "wake up" the devices 
  for (int d=0; d < kDevices; d++) {
    lc.shutdown(d, false);
    lc.setIntensity(d, 8);
    lc.clearDisplay(d);
  }
}

void loop() {
  for (int col = 0; col < COLS; col++) {
    for (int row = 0; row < ROWS; row++) {
      for (int device = 0; device < kDevices; device++) {
        lc.setLed(device, row, ((row & 0) ? (col) : (COLS - col)), true);
      } 
      delay(DELAY);
      for (int device = 0; device < kDevices; device++) {
        lc.setLed(device, row, ((row & 0) ? (col) : (COLS - col)), false);
      } 
      delay(DELAY);
    }
  }
}
