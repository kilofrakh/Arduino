int motor = 9; 
int speed = 0; 
int speedAmount = 5; 

void setup() { 
  pinMode(motor, OUTPUT); 
  } 

void loop() { 
  analogWrite(motor, speed); 
  speed = speed + speedAmount; 
  if (speed <= 0 || speed >= 255) { 
    speedAmount = -speedAmount; 
  } 
  delay(30); 
}
