#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,11);

void setup() 
{
  pinMode(3, OUTPUT);
  pinMode(4, INPUT_PULLUP);
  mySerial.begin(9600);

}

void loop() 
{
if (mySerial.available() != 0)
{
  char data = (char)mySerial.read();
  switch (data)
  {
  case 'D':
  delay(10);
  Serial.print(digitalRead(3));
  break;
  case 'C':
  digitalWrite(3,!(digitalRead(3)));
  break;
  case 'B':
  digitalWrite(3,LOW);
  break;
  case 'A':
  digitalWrite(3,HIGH);
  break;
  }
}

if (digitalRead(4) == 0)
{
  digitalWrite(3,!(digitalRead(3)));
  delay(300);
}

}
