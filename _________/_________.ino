#include <Servo.h>


Servo tap_servo;

int sensor_pin = 4;
int tap_servo_pin = 5;
int val;

void setup(){
  Serial.begin(9600);
  pinMode(sensor_pin,INPUT);
  tap_servo.attach(tap_servo_pin);

}

void loop(){
  val = digitalRead(sensor_pin);
  
  
  if (val==1) {
Serial.println("عيد سعيد");
delay(1000);
} else if (val==0){
Serial.println('.') ;
delay(100);
};

  
}
    
