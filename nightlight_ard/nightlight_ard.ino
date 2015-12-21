#include <DmxSimple.h>
#include "RunningAverage.h"

void setup() {
  Serial.begin(57600);
  DmxSimple.usePin(3);
  DmxSimple.maxChannel(12);

  pinMode(A9, INPUT);
  pinMode(A8, INPUT);
  pinMode(A7, INPUT);

}

void loop() {
  Serial.println(analogRead(A9));
  Serial.println(analogRead(A8));
  Serial.println(analogRead(A7));

  delay(10);

  //DmxSimple.write(1, brightness);


}


