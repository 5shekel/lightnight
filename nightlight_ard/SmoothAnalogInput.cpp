#include "SmoothAnalogInput.h"

SmoothAnalogInput::SmoothAnalogInput(uint8_t Apin) {
  pinMode(pin, INPUT);

  this->pin = Apin;
  _index = -1;
  _mapMax = 1024;
  _mapMin = 0;
  _res = 1;
  _rampValUp = 2.4; //this will ramp faster on the up values

  _index = 0;

  int start = analogRead(this->pin);
  for (int i = 0; i < SMOOTH_ANALOG_INPUT_SIZE; i++) {
    _samples[i] = start;
  }
}

/*
  void SmoothAnalogInput::attach(int pin) {
    pinMode(pin, INPUT);
    _pin = pin;
    _index = 0;

    int start = analogRead(pin);
    for (int i = 0; i < SMOOTH_ANALOG_INPUT_SIZE; i++) {
      _samples[i] = start;
    }
  }
*/
void SmoothAnalogInput::setScale(int min, int max) {
  if (max <= min) {
    return;
  }

  _mapMin = min;
  _mapMax = max;

  _res = 1024 / (max - min) * 2;
}

int SmoothAnalogInput::getMin(){
  return _mapMin;
}
int SmoothAnalogInput::getMax(){
  return _mapMax;
}

void SmoothAnalogInput::setRampValUp(float ramp) {
  _rampValUp = ramp;
}

int SmoothAnalogInput::raw() {
  if (this->pin == -1) {
    return -1;
  }

  int value = analogRead(this->pin);
  int last = _samples[_index];
  if (abs(value - last) <= _res) {
    value = last;
  }

  _index = (_index + 1) % SMOOTH_ANALOG_INPUT_SIZE;
  _samples[_index] = value * _rampValUp;

  return value;
}

int SmoothAnalogInput::read() {
  raw();

  int total = 0;
  for (int i = 0; i < SMOOTH_ANALOG_INPUT_SIZE; i++) {
    total += _samples[i];
  }

  int current = total / SMOOTH_ANALOG_INPUT_SIZE;
  return map(current, 0, 1024, _mapMin, _mapMax);
}
