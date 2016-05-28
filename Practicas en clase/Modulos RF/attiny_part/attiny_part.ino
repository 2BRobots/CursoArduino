#include <SoftwareSerial.h>

SoftwareSerial serial(0,1);

void setup() 
{
pinMode(4, OUTPUT);
serial.begin(9600);

}

void loop() 
{
if (serial.available())
{
if(serial.read() == 'a')
{
digitalWrite(4, !digitalRead(4));    
}
}
}
