#include "AdeHaptic.h"

//initialize each motor, to use different intensity, use PWM pins. In this case I'm using pins 9,10 and 11 of an Arduino Uno
Haptic motor1(9);
Haptic motor2(10);
Haptic motor3(11);


unsigned long lastHzTime, lastIntensityTime;
byte Hz = 0;
float frequency[] = {1.5, 3, 5, 10, 0};
byte intensity;

void setup() {

  //there are 10 different intensity, from 0 to 9, the default value is 9
  motor1.setIntensity(0);

  //frequencies are set in Hertz and accept float values. For example, a value of 5 will result in 5 Hz meaning 1 buzz every 200 ms
  motor2.setFrequency(1); //1 Hz -> 1 buzz every second

  //Duration is how long the motor is on when buzzing. Default is 200 ms
  //motor3 will wait for 200 ms and then vibrate for 1 second.
  motor3.setFrequency(5);
  motor3.setDuration(1000);

  //turn on the 3 motors, to turn them off just use .off()
  motor1.on();
  motor2.on();
  motor3.on();
}

void loop() {
  //the update function for each motor has to be in the loop, this function is responsible of managing the motors
  motor1.update();
  motor2.update();
  motor3.update();

  // every 2 seconds increase the intensity of motor 1
  if (millis() - lastIntensityTime > 2000) {
    lastIntensityTime = millis();
    intensity++;
    if (intensity > 9) intensity = 0;
    motor1.setIntensity(intensity);
  }

  // every 5 seconds increase the frequency of motor 2
  if ((millis() - lastHzTime) > 5000) {
    lastHzTime = millis();
    Hz++;
    if (Hz > 4) Hz = 0;
    motor2.setFrequency(frequency[Hz]);
  }
  
}
