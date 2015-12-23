//NIGHTLIGHT
// https://github.com/5shekel/lightnight

#include <DmxSimple.h>

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

#include "SmoothAnalogInput.h"

SmoothAnalogInput smp9;
SmoothAnalogInput smp8;
SmoothAnalogInput smp7;

int samples, i;

void setup() {
  Serial.begin(57600);

  oled.begin();
  oled.clear(ALL);  // Clear the display's memory (gets rid of artifacts)
  oled.display();

  pinMode(A9, INPUT);
  pinMode(A8, INPUT);
  pinMode(A7, INPUT);

  DmxSimple.usePin(3);
  DmxSimple.maxChannel(12);

  smp9.attach(A9);
  smp8.attach(A8);
  smp7.attach(A7);


}

void loop() {

  int width = 4;
  int height = 64;

  int sm7 = smp7.read();
  sm7 = map(sm7, 0, 100, 0, 64);
  oled.rectFill(width*0, 0, width, sm7);

  int sm8 = smp8.read();
  sm8 = map(sm8, 0, 100, 0, 64);
  oled.rectFill(width*1, 0, width, sm8);

  int sm9 = smp9.read();
  sm9 = map(sm9, 0, 100, 0, 64);
  oled.rectFill(width*2, 0, width, sm9);

  oled.display(); oled.clear(PAGE);
  
  
    Serial.print(sm7);
    Serial.print(" ");
    Serial.print(sm8);
    Serial.print(" ");
    Serial.print(sm9);
    Serial.print(" ");
    Serial.print(analogRead(A7));
    Serial.print(" ");
    Serial.print(analogRead(A8));
    Serial.print(" ");
    Serial.print(analogRead(A9));
    Serial.println();
  
  delay(10);
  //DmxSimple.write(1, brightness);
}


