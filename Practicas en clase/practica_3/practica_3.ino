void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
     
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(8) == 1)
  {
    digitalWrite(12, HIGH);
  }
  else
  {
    digitalWrite(12, LOW);
  }
  
   if(digitalRead(7) == 1)
  {
    digitalWrite(11, HIGH);
  }
  else
  {
    digitalWrite(11, LOW);
  }

   if(digitalRead(6) == 1)
  {
    digitalWrite(10, HIGH);
  }
  else
  {
    digitalWrite(10, LOW);
  }

   if(digitalRead(5) == 1)
  {
    digitalWrite(9, HIGH);
  }
  else
  {
    digitalWrite(9, LOW);
  }
}
