#include "AdeHaptic.h"

//initialize each motor, to use different intensity, use PWM pins
Haptic motor1(9);
Haptic motor2(10);
Haptic motor3(11);


unsigned long lastTime, lastTime2,intensityTime;
byte Hz=0;
float frequency[] = {1.5, 3, 5, 10, 0};
byte intensity;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //there are 10 different intensity, from 0 to 9, the default value is 9
  motor1.setIntensity(0);
  //frequencies are set in Hertz and accept float values. For example, a value of 5 will result in 5 Hz meaning 1 buzz every 200 ms
  motor2.setFrequency(1); //1 Hz -> 1 buzz every second
  //Duration is how long the motor is on when buzzing. Default is 200 ms
  //motor3 will wait for 200 ms and then vibrate for 1 second.
  motor3.setFrequency(5);
  motor3.setDuration(1000); 

  //turn on the 3 motors
  motor1.on();
  //motor2.on();
  //motor3.on();
}

void loop() {
  //the update function for each motor has to be in the loop function, this function is responsible of managing the motors
  motor1.update();
  motor2.update();
  motor3.update();

  //every 2 seconds increase the intensity of motor 1
  if(millis()-intensityTime > 2000) {
    intensityTime=millis();
    intensity++;
    if(intensity>9) intensity = 0;
    Serial.println(intensity);
    motor1.setIntensity(intensity);
  }
  
  //every 10 seconds turn the motor1 on or off
//  if((millis()/10000) % 2) {
//    motor1.on();
//  } else {
//    motor1.off();
//  }

  

if((millis()-lastTime)>5000) {
  lastTime=millis();
  //Serial.println("change");
  Hz++;
  if(Hz>4) Hz=0;
  motor2.setFrequency(frequency[Hz]);
}

//if((millis()-lastTime2)>20000) {
//  lastTime2=millis();
//  //Serial.println("ramp");
//  motor1.off();
//}
/*for (int i = 0;i<1000;i++) {
  if((i/100)%10) {
    int val = i/100;
    motor1.setIntensity(val);
    motor1.update();
    Serial.println(val);
  }
}*/
}
