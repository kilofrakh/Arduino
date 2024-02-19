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
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver mutrs = Adafruit_PWMServoDriver();



#define servo1 0
#define servo2 1


void setup() 
{
  RemoteXY_Init (); 
  #define servo1 0
  Serial.begin(9600);
  mutrs.begin();
  mutrs.setPWMFreq(60);
  mutrs.setPWM(servo1, 0, 250);
  mutrs.setPWM(servo2, 0, 250);

}

void loop() 
{ 
  RemoteXY_Handler ();
int barke = RemoteXY.button_1;



if (barke == HIGH) {
  mutrs.setPWM(servo2, 0, 250);
  delay(10);
  mutrs.setPWM(servo2, 0, 240);
  delay(10);  
  mutrs.setPWM(servo1, 0, 250);
  delay(10);
  mutrs.setPWM(servo1, 0, 240);  
  delay(10);
}
else{
  mutrs.setPWM(servo2, 0, 360);
  mutrs.setPWM(servo1, 0, 360);
  };
}     
