void setup() 
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), interrupcion, FALLING);

}

void loop()
{
digitalWrite(12, HIGH);
delay(1000);
digitalWrite(12, LOW);
delay(1000);
}

void interrupcion()
{
digitalWrite(11, !(digitalRead(11)));  
}

