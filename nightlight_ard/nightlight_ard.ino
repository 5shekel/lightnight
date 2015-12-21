#include <DmxSimple.h>

#define smooth 1

#include "SmoothAnalogInput.h"

SmoothAnalogInput smp9;
SmoothAnalogInput smp8;
SmoothAnalogInput smp7;

int samples;

void setup() {
  Serial.begin(57600);

  pinMode(A9, INPUT);
  pinMode(A8, INPUT);
  pinMode(A7, INPUT);

  DmxSimple.usePin(3);
  DmxSimple.maxChannel(12);

  smp9.attach(9);
  smp8.attach(8);
  smp7.attach(7);


}

void loop() {

  int sm7 = smp7.read();
  int sm8 = smp8.read();
  int sm9 = smp9.read();

  //if (smooth) {
  Serial.print(sm7);
  Serial.print(" ");
  Serial.print(sm8);
  Serial.print(" ");
  Serial.print(sm9);
  //Serial.println();
    Serial.print(" ");

  //}  else {
  Serial.print(analogRead(A7));
  Serial.print(" ");
  Serial.print(analogRead(A8));
  Serial.print(" ");
  Serial.print(analogRead(A9));
  Serial.println();
  //}
  delay(10);
  //DmxSimple.write(1, brightness);
}


