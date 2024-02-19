int sensor_pin = 4;
int val;

void setup(){
  pinMode(sensor_pin,INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop(){
  val = digitalRead(sensor_pin);
  
  if (val==0)
  {digitalWrite(LED_BUILTIN, HIGH);
  }
  if (val==1)
  {digitalWrite(LED_BUILTIN, LOW);
  }
  delay(10);
  
}
