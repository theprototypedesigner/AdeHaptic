#ifndef ADE_HAPTIC_H
#define ADE_HAPTIC_H

#include <Arduino.h>

class Haptic {

  private:

    const byte _pin;
    byte _intensity = 255;
    short _frequency = 3000;
    short _duration = 500;
    bool turnOn;
    bool isOff = true;
    unsigned long lastOffTime;
    unsigned long lastOnTime;
    
    void init(byte intensity, short frequency, short duration);

  public:

    Haptic(byte pin);
    Haptic(byte pin, byte intensity);
    Haptic(byte pin, byte intensity, short frequency);
    Haptic(byte pin, byte intensity, short frequency, short duration);

    void setIntensity(byte intensity);
    void setFrequency(float frequency);
    void setDuration(short duration);
    void on();
    void off();
    void update();
  
};

#endif