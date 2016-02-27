void setup() {
  // put your setup code here, to run once:
  pinMode(5, INPUT_PULLUP);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

}

byte boton = 1;

void loop() {
  // put your main code here, to run repeatedly:

  
  if(digitalRead(5) == 0)
  {
     boton = !(digitalRead(5)) + boton;
     delay(500);
  }
  

  switch(boton)
  {
    case 1:
     digitalWrite(12, HIGH);
     digitalWrite(11, LOW);
     digitalWrite(10, LOW);
     digitalWrite(9, LOW);
     break;
     case 2:
     digitalWrite(12, LOW);
     digitalWrite(11, HIGH);
     digitalWrite(10, LOW);
     digitalWrite(9, LOW);
     break;
     case 3:
     digitalWrite(12, LOW);
     digitalWrite(11, LOW);
     digitalWrite(10, HIGH);
     digitalWrite(9, LOW);
     break;
     case 4:
     digitalWrite(12, LOW);
     digitalWrite(11, LOW);
     digitalWrite(10, LOW);
     digitalWrite(9, HIGH);
     break;
     default:
     boton = 1;
     break;
  }

  

}
