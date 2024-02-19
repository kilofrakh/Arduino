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
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver mutrs = Adafruit_PWMServoDriver();

#define servo1 0
#define servo2 1


#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 59 bytes
  { 255,2,0,0,0,52,0,16,203,1,2,0,21,23,22,11,2,26,31,31,
  79,78,0,79,70,70,0,129,0,24,13,15,7,24,110,111,111,114,0,129,
  0,25,44,10,6,24,98,97,98,0,1,0,25,59,12,12,2,31,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t button_1; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



void setup() 
{
  pinMode(11, OUTPUT);
  RemoteXY_Init (); 
  
  Serial.begin(9600);
  mutrs.begin();
  mutrs.setPWMFreq(60);
  mutrs.setPWM(servo1, 0, 500);
  mutrs.setPWM(servo2, 0, 330);  
}

void loop() 
{ 
  RemoteXY_Handler ();

if (RemoteXY.switch_1 == 1) {
    mutrs.setPWM(servo1, 0, 150);
        mutrs.setPWM(servo2, 0, 520);
} else {
    mutrs.setPWM(servo1, 0, 330),
        mutrs.setPWM(servo2, 0, 150);
}

  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 

}
