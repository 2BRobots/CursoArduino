#include <Servo.h>
Servo servo1;

void setup()
{
pinMode(9, OUTPUT);
servo1.attach(9);
servo1.write(90);
delay(500);

}

void loop()
{
for(byte i = 20; i<= 160; i++)
{
 servo1.write(i);
 delay(50);  
}

for(byte i = 160; i>= 20; i--)
{
  servo1.write(i);
  delay(50);
}
}
