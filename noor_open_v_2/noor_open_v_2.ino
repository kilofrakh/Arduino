#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

int sensor_pin = 4;
int val;

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();



void setup() {
  pwm.begin();
  pwm.setPWMFreq(60);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(sensor_pin,INPUT);
}


void loop() {
  val = digitalRead(sensor_pin);

  if (val==0) {
  pwm.setPWM(0, 0, 125);
  pwm.setPWM(1, 0, 125);
  delay(500);
}

  if (val==1) {
  pwm.setPWM(0, 0, 300);
  pwm.setPWM(1, 0, 300);
  delay(500);
}

  ////////////////////////////////////////////////
  if (val==0)
  {digitalWrite(LED_BUILTIN, HIGH);
  }
  if (val==1)
  {digitalWrite(LED_BUILTIN, LOW);
  }  
}
