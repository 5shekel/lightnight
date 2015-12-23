
//via https://github.com/rl337/Arduino/tree/master/libraries/SmoothAnalogInput

#ifndef SmoothAnalogInput_h
#define SmoothAnalogInput_h

#include <Arduino.h>

#define SMOOTH_ANALOG_INPUT_SIZE 10

class SmoothAnalogInput {
    public:
        SmoothAnalogInput(uint8_t pin);
       // void attach(int pin);
        void setScale(int min, int max);
        void setRampValUp(float ramp);
        int getMin();
        int getMax();
        int read();
        int raw();
    private:
        int _samples[SMOOTH_ANALOG_INPUT_SIZE];
        uint8_t pin;
        int _index;
        int _mapMin;
        int _mapMax;
        int _res;
        float _rampValUp;
};

#endif
