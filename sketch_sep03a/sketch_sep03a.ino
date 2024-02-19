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
uint8_t RemoteXY_CONF[] =   // 26 bytes
  { 255,1,0,0,0,19,0,16,24,1,130,1,20,38,20,20,17,1,0,24,
  43,12,12,2,31,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t button_1; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////


int right_motor_A=8;
int right_motor_B=9;
int right_motor_speed=11; //enable pin

uint8_t RightMotor[3] = {right_motor_A, right_motor_B, right_motor_speed};

void setup() 
{
  RemoteXY_Init (); 

  Serial.begin(9600);
  pinMode (right_motor_A, OUTPUT);
  pinMode (right_motor_B, OUTPUT);
  pinMode (right_motor_speed, OUTPUT);
}

void loop() 
{ 
  RemoteXY_Handler ();
int barke = RemoteXY.button_1;


Serial.println(barke);


if (barke == HIGH) {
  digitalWrite(right_motor_A, HIGH);  
  digitalWrite(right_motor_speed, HIGH); 
  digitalWrite(right_motor_B, LOW);
}
else if (barke == LOW){
  digitalWrite(right_motor_B, HIGH);
  digitalWrite(right_motor_speed, HIGH);  
  digitalWrite(right_motor_A, LOW);  
  };
}
