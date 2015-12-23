//NIGHTLIGHT
// https://github.com/5shekel/lightnight


//DMX
////////////////////////////////
#include <DmxSimple.h>
/////////////////////////////////////

/// OLED
///////////////////////////////////////////////////////
#include <Wire.h>  // Include Wire if you're using I2C
#include <SPI.h>  // Include SPI if you're using SPI
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library
// https://learn.sparkfun.com/tutorials/micro-oled-breakout-hookup-guide
//////////////////////////
// MicroOLED Definition //
//////////////////////////
#define PIN_DC    8  // Connect DC to pin 8 (required for SPI)
#define PIN_RESET 9  // Connect RST to pin 9 (req. for SPI and I2C)
#define PIN_CS    10 // Connect CS to pin 10 (required for SPI)
// on teensy 3.2
// connect pin SCK/SCLK 13
// connect MOSI/SDI 11

#define DC_JUMPER 0
MicroOLED oled(PIN_RESET, PIN_DC, PIN_CS);
int Screen_width = 4;
int Screen_height = 64;

#include "SmoothAnalogInput.h"
SmoothAnalogInput smArray[12] = {
  SmoothAnalogInput(A0), SmoothAnalogInput(A1), SmoothAnalogInput(A2),
  SmoothAnalogInput(A3), SmoothAnalogInput(A4), SmoothAnalogInput(A5),
  SmoothAnalogInput(A6), SmoothAnalogInput(A7), SmoothAnalogInput(A8),
  SmoothAnalogInput(A9), SmoothAnalogInput(A10), SmoothAnalogInput(A1)
};

void setup() {
  Serial.begin(57600);

  oled.begin();
  oled.clear(ALL);  // Clear the display's memory (gets rid of artifacts)
  oled.display();

  DmxSimple.usePin(3);
  DmxSimple.maxChannel(12);
}

void loop() {


  for (int iii = 0; iii < 12; iii++) {
    int reading = smArray[iii].read();
    reading = map(reading, 0, 100, 0, 64);
    oled.rectFill(Screen_width * iii, 0, Screen_width, reading);

    Serial.print(reading);
    Serial.print(" ");
  }
  Serial.println();
  oled.display(); oled.clear(PAGE);

  //DmxSimple.write(1, brightness);

  delay(10);
}


