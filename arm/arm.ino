



#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver mutrs = Adafruit_PWMServoDriver();

#define servo1 0
#define servo2 1
#define servo3 2
#define servo4 3


void setup() {
  Serial.begin(9600);
  mutrs.begin();
  mutrs.setPWMFreq(60);
  mutrs.setPWM(servo1, 0, 330);
  mutrs.setPWM(servo2, 0, 350);
  mutrs.setPWM(servo3, 0, 300);
  mutrs.setPWM(servo4, 0, 410);
  delay(3000);
}

void loop() {

  for (int S1value = 330; S1value >= 250; S1value--) {
    mutrs.setPWM(servo1, 0, S1value);
    delay(10);
  }

  for (int S2value = 350; S2value >= 150; S2value--) {
    mutrs.setPWM(servo2, 0, S2value);
    delay(10);
  }

  for (int S3value = 300; S3value <= 380; S3value++) {
    mutrs.setPWM(servo3, 0, S3value);
    delay(10);
  }

  for (int S4value = 410; S4value <= 510; S4value++) {
    mutrs.setPWM(servo4, 0, S4value);
    delay(10);
  }
  ////////////////////////
  delay(2000);
  for (int S4value = 510; S4value > 410; S4value--) {
    mutrs.setPWM(servo4, 0, S4value);
    delay(10);
  }

  for (int S3value = 380; S3value > 300; S3value--) {
    mutrs.setPWM(servo3, 0, S3value);
    delay(10);
  }

  for (int S2value = 150; S2value < 350; S2value++) {
    mutrs.setPWM(servo2, 0, S2value);
    delay(10);
  }

  for (int S1value = 250; S1value < 450; S1value++) {
    mutrs.setPWM(servo1, 0, S1value);
    delay(10);
  }
  //////////////////////
  for (int S2value = 350; S2value >= 150; S2value--) {
    mutrs.setPWM(servo2, 0, S2value);
    delay(10);
  }

  for (int S3value = 300; S3value <= 380; S3value++) {
    mutrs.setPWM(servo3, 0, S3value);
    delay(10);
  }

  for (int S4value = 410; S4value <= 510; S4value++) {
    mutrs.setPWM(servo4, 0, S4value);
    delay(10);
  }

  for (int S4value = 510; S4value > 410; S4value--) {
    mutrs.setPWM(servo4, 0, S4value);
    delay(10);
  }
  ///////////////////
  for (int S3value = 380; S3value > 300; S3value--) {
    mutrs.setPWM(servo3, 0, S3value);
    delay(10);
  }

  for (int S2value = 150; S2value < 350; S2value++) {
    mutrs.setPWM(servo2, 0, S2value);
    delay(10);
  }

  for (int S1value = 450; S1value > 330; S1value--) {
    mutrs.setPWM(servo1, 0, S1value);
    delay(10);
  }
}
