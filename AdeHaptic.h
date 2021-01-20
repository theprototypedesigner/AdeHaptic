#ifndef ADE_HAPTIC_H
#define ADE_HAPTIC_H

#include <Arduino.h>

class Haptic {

  private:

    byte pin;
    byte intensity;
    int frequency;
    int duration;
    bool turnOn;
    bool isOff = true;
    unsigned long lastOffTime;
    unsigned long lastOnTime;
    

  public:

    Haptic(byte pin);

    void init();
    void setIntensity(byte intensity);
    void setFrequency(float frequency);
    void setDuration(int duration);
    void on();
    void off();
    void update();

  
};

#endif
