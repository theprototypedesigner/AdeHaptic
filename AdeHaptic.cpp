#include "AdeHaptic.h"

#define DEFAULT_INTENSITY 255
#define DEFAULT_FREQUENCY 0
#define DEFAULT_DURATION 200

Haptic::Haptic(byte pin) : _pin(pin) {
  this->init(DEFAULT_INTENSITY, DEFAULT_FREQUENCY, DEFAULT_DURATION);
}

Haptic::Haptic(byte pin, byte intensity)  : _pin(pin) {
  this->init(intensity, DEFAULT_FREQUENCY, DEFAULT_DURATION);
}

Haptic::Haptic(byte pin, byte intensity, short frequency)  : _pin(pin) {
  this->init(intensity, frequency, DEFAULT_DURATION);
}

Haptic::Haptic(byte pin, byte intensity, short frequency, short duration)  : _pin(pin) {
  this->init(intensity, frequency, duration);
}

void Haptic::init(byte intensity, short frequency, short duration) {
  this->setIntensity(intensity);
  this->setFrequency(frequency);
  this->setDuration(duration);
  pinMode(_pin, OUTPUT);
}

void Haptic::setIntensity(byte intensity) {
  _intensity = map(intensity,0,9,50,255);
  if(!isOff) analogWrite(_pin, _intensity);
}

void Haptic::setFrequency(float frequency) {
  if(frequency==0) _frequency = 0;  
  else _frequency = round(1000/frequency);
}

void Haptic::setDuration(short duration) {
  _duration = duration;
}

void Haptic::on() {
  lastOnTime = millis();
  turnOn = true;
}

void Haptic::off() {
  analogWrite(_pin, 0);
  turnOn = false;
}

void Haptic::update() {
  if(turnOn) {
    if(isOff) {
    if (_frequency == 0) {
      analogWrite(_pin, _intensity);
      isOff = false;
    } else if(millis() - lastOffTime > _frequency) {
      analogWrite(_pin, _intensity);
      isOff = false;
      lastOnTime = millis();
    }
    } else if(_frequency != 0) {
      if(millis() - lastOnTime > _duration) {
        analogWrite(_pin, 0);
        lastOffTime = millis();
        isOff = true;
      }
    }
  }
}