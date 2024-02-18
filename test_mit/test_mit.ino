#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver mutrs = Adafruit_PWMServoDriver();

#define servo1 0
#define servo2 1


char Incoming_value = 0;
                
void setup() 
{
  Serial.begin(9600);         
  pinMode(13, OUTPUT);   
  mutrs.begin();
  mutrs.setPWMFreq(60);
  mutrs.setPWM(servo1, 0, 500);
  mutrs.setPWM(servo2, 0, 330);      
}

void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.print(Incoming_value);        
    Serial.print("\n");    

        
    if(Incoming_value == '1') {            
    mutrs.setPWM(servo1, 0, 150);
    mutrs.setPWM(servo2, 0, 520);
    digitalWrite(13, HIGH);
    Serial.println("ON");
    
    }  
    else if(Incoming_value == '0') {      
    mutrs.setPWM(servo1, 0, 330);
    mutrs.setPWM(servo2, 0, 150);
    digitalWrite(13, LOW); 
    Serial.println("OFF");
    }  
  }                            
} 
