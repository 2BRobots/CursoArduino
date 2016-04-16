#include <EEPROM.h>

void setup()
{
pinMode(3, INPUT_PULLUP);
Serial.begin(9600);

}

void loop() 
{
if (digitalRead(3) == 0)
{
  Serial.println(char(EEPROM.read(0)));
  delay(1000);
}

if (Serial.available() != 0)
{
  
  EEPROM.put(0, char(Serial.read()));
  delay(1000);
}

}
