
//via https://github.com/rl337/Arduino/tree/master/libraries/SmoothAnalogInput

#ifndef SmoothAnalogInput_h
#define SmoothAnalogInput_h

#include <Arduino.h>

#define SMOOTH_ANALOG_INPUT_SIZE 10

class SmoothAnalogInput {
    public:
        SmoothAnalogInput();
        void attach(int pin);
        void scale(int min, int max);
        void setRampValUp(float ramp);
        int read();
        int raw();
    private:
        int _samples[SMOOTH_ANALOG_INPUT_SIZE];
        int _pin;
        int _index;
        int _mapMin;
        int _mapMax;
        int _res;
        float _rampValUp;
};

#endif