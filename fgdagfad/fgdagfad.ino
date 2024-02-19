//================================(define right motor control pins)===================
int right_motor_A=8;
int right_motor_B=9;
int right_motor_speed=11; //enable pin

//================================(define left motor control pins)====================
int left_motor_A=6;
int left_motor_B=7;
int left_motor_speed=10; //enable p


//=======================(define two arrays with a list of pins for each motor)=======
uint8_t RightMotor[3] = {right_motor_A, right_motor_B, right_motor_speed};
uint8_t LeftMotor[3] = {left_motor_A, left_motor_B, left_motor_speed};

/////////////////////////////////////////================================================////////////////////////////////////////

int sensor_pin = 4;
int val; 
byte mask=1;



void setup() {
  Serial.begin(9600);
  pinMode(sensor_pin,INPUT);
  pinMode (right_motor_A, OUTPUT);
  pinMode (right_motor_B, OUTPUT);
  pinMode (right_motor_speed, OUTPUT);
  pinMode (left_motor_A, OUTPUT);
  pinMode (left_motor_B, OUTPUT);
  pinMode (left_motor_speed, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  digitalWrite(right_motor_A, LOW);  
  digitalWrite(right_motor_speed, LOW); 
  digitalWrite(right_motor_B, LOW);

  digitalWrite(left_motor_A, LOW);  
  digitalWrite(left_motor_speed, LOW); 
  digitalWrite(left_motor_B, LOW);   

  
}

void loop() {

  
 val = digitalRead(sensor_pin);

 
 if (val == HIGH) {
  digitalWrite(right_motor_A, HIGH);  
  digitalWrite(right_motor_speed, HIGH); 
  digitalWrite(right_motor_B, LOW);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(left_motor_A, HIGH);  
  digitalWrite(left_motor_speed, HIGH); 
  digitalWrite(left_motor_B, LOW);
  if(mask==1){
  Serial.println("seen"); 
  }
  }
else if (val == LOW) { 

  
  digitalWrite(right_motor_A, LOW);  
  digitalWrite(right_motor_speed, LOW); 
  digitalWrite(right_motor_B, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(left_motor_A, LOW);  
  digitalWrite(left_motor_speed, LOW); 
  digitalWrite(left_motor_B, LOW); 
  

}

  
}
