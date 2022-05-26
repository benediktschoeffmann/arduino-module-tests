/**
Load the LedControl library either over the Arduino Manager or 
on the authors (Eberhard Fahle) website: 

https://wayoda.github.io/LedControl/
*/

#include <LedControl.h>

#define DIN         12 // Data In
#define CLK         11 // Clock 
#define CS          10 // ChipSelect    
#define MAX_DEVICES 8  // Maximum number that can be theoretically controlled

const int DELAY = 25;  // Blink time in ms
const int ROWS = 8;
const int COLS = 8;

// Number of connected devices
int kDevices;

LedControl lc = LedControl(DIN, CLK, CS, 1); 

void setup() {
  kDevices = 4;

  // "wake up" the devices 
  for (int d=0; d < kDevices; d++) {
    lc.shutdown(d, false);
    lc.setIntensity(d, 8>>(4-d));
    lc.clearDisplay(d);
  }
}


void loop() {
  for (int row=0; row < ROWS; row++) {
    for (int col=0; col < COLS; col++) {
      for (int device=0; device < kDevices; device++) {
        lc.setLed(device, row, (row%2) ? (col) : (COLS-1-col), true);
      }
      delay(DELAY);
      for (int device=0; device < kDevices; device++) {
        lc.setLed(device, row, (row%2) ? (col) : (COLS-1-col), false);
      }
      delay(DELAY);
    }

  }
}
