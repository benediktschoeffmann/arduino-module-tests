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

int DELAY = 50;  // Blink time in ms
int ROWS = 8;
int COLS = 8;

// Number of connected devices
int kDevices;

LedControl lc = LedControl(DIN, CLK, CS, 1); 

void setup() {
  kDevices = 1;

  // "wake up" the devices 
  for (int d=0; d < kDevices; d++) {
    lc.shutdown(d, false);
    lc.setIntensity(d, 8);
    lc.clearDisplay(d);
  }
}


void loop() {
  for (int row=0; row < ROWS; row++) {
    for (int col=0; col < COLS; col++) {
      lc.setLed(0, row, (row%2) ? (col) : (COLS-1-col), true);
      delay(DELAY);
      lc.setLed(0, row, (row%2) ? (col) : (COLS-1-col), false);
      delay(DELAY);
    }

  }
}
