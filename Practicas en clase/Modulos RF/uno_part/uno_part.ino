#include <SoftwareSerial.h>

SoftwareSerial serial(7,8);

void setup()
{
serial.begin(9600);

}

void loop() 
{
serial.write('a');
delay(2000);
}
