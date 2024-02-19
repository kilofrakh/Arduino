/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 59 bytes
  { 255,5,0,0,0,52,0,16,8,0,5,37,56,14,38,38,2,26,31,130,
  1,0,0,40,63,17,4,0,6,23,7,18,2,26,4,0,22,23,7,18,
  2,26,2,0,10,3,18,10,2,26,31,31,79,78,0,79,70,70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t joystick_1_x; // from -100 to 100  
  int8_t joystick_1_y; // from -100 to 100  
  int8_t slider_1; // =0..100 slider position 
  int8_t slider_2; // =0..100 slider position 
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver mutrs = Adafruit_PWMServoDriver();

#define servo1 0
#define servo2 1



//================================(define right motor control pins)===================
int right_motor_A=8;
int right_motor_B=9;
int right_motor_speed=11; //enable pin

//================================(define left motor control pins)====================
int left_motor_A=6;
int left_motor_B=7;
int left_motor_speed=10; //enable pin

//=======================(define two arrays with a list of pins for each motor)=======
uint8_t RightMotor[3] = {right_motor_A, right_motor_B, right_motor_speed};
uint8_t LeftMotor[3] = {left_motor_A, left_motor_B, left_motor_speed};

//========================(speed control of motors)==================================
void Wheel (uint8_t * motor, int v) // v = motor speed, motor = pointer to an array of pins 
{
  if (v > 100) v=100;
  if (v < -100) v=-100;
  if (v > 0){

    digitalWrite (motor [0], HIGH);
    digitalWrite (motor [1], LOW);
    analogWrite (motor [2], v * 2.55);
  }
  else if ( v<0 ){

    digitalWrite (motor [0], LOW);
    digitalWrite (motor [1], HIGH);
    analogWrite (motor [2], (-v) * 2.55);
  }
  else{
    digitalWrite (motor [0], LOW);
    digitalWrite (motor [1], LOW);
    analogWrite (motor [2], 0);
  }
}

  //===================================================================================
void setup() 
{

  mutrs.setPWM(servo1, 0, 225);
  mutrs.setPWM(servo2, 0, 225);
  RemoteXY_Init ();  
  
  //===============================(initialization pins)==============================
  pinMode (right_motor_A, OUTPUT);
  pinMode (right_motor_B, OUTPUT);
  pinMode (right_motor_speed, OUTPUT);
  pinMode (left_motor_A, OUTPUT);
  pinMode (left_motor_B, OUTPUT);
  pinMode (left_motor_speed, OUTPUT);
  pinMode (servo1, OUTPUT);
  pinMode (servo2, OUTPUT);
  pinMode (13, OUTPUT);
  Serial.begin(9600);
  mutrs.begin();
  mutrs.setPWMFreq(60);
  RemoteXY.slider_1=100;
  RemoteXY.slider_2=100;

;
 
  //===================================================================================

   
}

void loop() 
{
   int s1value = RemoteXY.slider_1*20+100; 
   int s2value = RemoteXY.slider_2*20+100;


 
  RemoteXY_Handler ();
  //============================(manage motors direction & speed)======================
  Wheel (RightMotor, RemoteXY.joystick_1_y - RemoteXY.joystick_1_x);
  Wheel (LeftMotor, RemoteXY.joystick_1_y + RemoteXY.joystick_1_x);


  mutrs.setPWM(servo1, 0, s1value);
  mutrs.setPWM(servo2, 0, s2value);


}
