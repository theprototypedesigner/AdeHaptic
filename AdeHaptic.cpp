#include "AdeHaptic.h"

Haptic::Haptic(byte pin) {
  this->pin = pin;
  init();
}

void Haptic::init() {
  pinMode(pin, OUTPUT);
  update();
}

void Haptic::setIntensity(byte intensity) {
  this->intensity = map(intensity,0,9,50,255);
  if(!isOff) analogWrite(pin, this->intensity);
}


void Haptic::setFrequency(float frequency) {
  if(frequency==0) {
    this->frequency = 0;  
  } else {
    this->frequency = round(1000/frequency);
  }
}

void Haptic::setDuration(int duration) {
  this->duration = duration;
}

void Haptic::on() {
  lastOnTime = millis();
  turnOn = true;
  
}

void Haptic::off() {
  analogWrite(pin, 0);
  turnOn = false;
}

void Haptic::update() {
  if(turnOn) {
    if(isOff) {
    if (frequency == 0) {
      analogWrite(pin, intensity);
      isOff = false;
      return;
    }
    if(millis() - lastOffTime > frequency) {
      analogWrite(pin, intensity);
      isOff = false;
      lastOnTime = millis();
    }
    } else if(frequency != 0) {
      if(millis() - lastOnTime > duration) {
        analogWrite(pin, 0);
        lastOffTime = millis();
        isOff = true;
      }
    }
  }
}
