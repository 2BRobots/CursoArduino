#include <LiquidCrystal.h>
#include <Servo.h>
#include <EEPROM.h>

Servo servo1;
LiquidCrystal lcd(7,8,9,10,11,12);

byte angulo = EEPROM.read(0);

void setup() 
{
if(EEPROM.read(0) > 180)  
{  
 EEPROM.write(0,90); 
 angulo = EEPROM.read(0);
}
pinMode(9,OUTPUT);  
pinMode(3, INPUT_PULLUP);
pinMode(4, INPUT_PULLUP);
lcd.begin(16,2);
servo1.attach(9);
servo1.write(angulo);
delay(100);
}

void loop() 
{
lcd.clear();
lcd.print("El servo esta en: ");
lcd.setCursor(0,1);
lcd.print(angulo);
lcd.print(" grados");
servo1.write(angulo);

if(digitalRead(3) == 0)
{
  angulo = angulo + 5;
  if( angulo >= 180)
  {
    angulo = 180;
  }
  EEPROM.write(0,angulo);
  delay(500);
}

if(digitalRead(4) == 0)
{
  angulo = angulo - 5;
  if( angulo > 180)
  {
    angulo = 0;
  }
  EEPROM.write(0,angulo);
  delay(500);
}

delay(500);
}
