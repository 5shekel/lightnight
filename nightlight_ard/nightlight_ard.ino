
//NIGHTLIGHT
// https://github.com/5shekel/lightnight

#define DEBUG 1
#define piezoArraySize 8

int Screen_width = 64;
int Screen_height = 48;

////// peizo smoothing /////////////////////////////////////////////////////
/// with a little help from http://playground.arduino.cc/Code/LED
#include "SmoothAnalogInput.h"
SmoothAnalogInput smArray[piezoArraySize] = {
  SmoothAnalogInput(A0), SmoothAnalogInput(A1), SmoothAnalogInput(A2),
  SmoothAnalogInput(A3), SmoothAnalogInput(A4), SmoothAnalogInput(A5),
  SmoothAnalogInput(A6), SmoothAnalogInput(A7)};
//////////////////////////////////////////////////////////////////////


/*
/////OLED///////////////////////////////////////////
#include <Wire.h>  // Include Wire if you're using I2C
#include <SPI.h>  // Include SPI if you're using SPI
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library
// https://learn.sparkfun.com/tutorials/micro-oled-breakout-hookup-guide
#define PIN_DC    8  // Connect DC to pin 8 (required for SPI)
#define PIN_RESET 9  // Connect RST to pin 9 (req. for SPI and I2C)
#define PIN_CS    10 // Connect CS to pin 10 (required for SPI)
// on teensy 3.2
// connect pin SCK/SCLK 13
// connect MOSI/SDI 11

#define DC_JUMPER 0
MicroOLED oled(PIN_RESET, PIN_DC, PIN_CS);
//////////////////////////////////////////////////////////////////////
*/
/// DMX ////////////////////////
#include <DmxSimple.h>
/////////////////////////////////////

void setup() {
  Serial.begin(9600);
/*
  for (int iii = 0; iii < piezoArraySize; iii++) {
    //smArray[iii].setScale(0, 255);
  }
*/
  //oled.begin();

  DmxSimple.usePin(4);
  DmxSimple.maxChannel(8);
}

void loop() {


  for (int iii = 0; iii < piezoArraySize; iii++) {
    int reading = smArray[iii].read();


    //reading = map(reading, smArray[iii].getMin(), smArray[iii].getMax(), 0, Screen_height);
    reading = constrain(reading, 5 , 100);
    reading = map(reading, 5, 100, 0, 255);
    
    if (DEBUG) {
      Serial.print(reading);
      Serial.print(" ");
    }

    //dmx address start at 1
    DmxSimple.write(iii+1, reading);

    //int width = (Screen_width / piezoArraySize) ; //will give 64/12=4
    //oled.rectFill(width * iii, 1, width - 1, reading);
  }
  if (DEBUG) Serial.println();

 // oled.display();
 // oled.clear(PAGE);


  delay(10);
}


