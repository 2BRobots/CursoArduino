void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

}

int contador = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if (contador < 2)
  {
   for(int i = 1; i<=5;i++)
   {
    digitalWrite(12,HIGH);
    delay(3000);
    digitalWrite(12,LOW);
    delay(3000);
   } 
   for(int i = 1; i<=10;i++)
   {
    digitalWrite(11,HIGH);
    delay(1000);
    digitalWrite(11,LOW);
    delay(1000);
   } 
   for(int i = 1; i<=3;i++)
   {
    digitalWrite(10,HIGH);
    delay(250);
    digitalWrite(10,LOW);
    delay(250);
   } 
   for(int i = 1; i<=2;i++)
   {
    digitalWrite(9,HIGH);
    delay(5000);
    digitalWrite(9,LOW);
    delay(5000);
   } 
  }
  else
  {
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    
  }
  while(contador <=2)
  {
  contador = contador + 1;
  }
  

}
