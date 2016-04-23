#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7); 

byte luz =0;

void setup() 
{
lcd.begin(16,2);
lcd.setBacklightPin(3, POSITIVE);
lcd.setBacklight(HIGH);

pinMode(8, INPUT_PULLUP);

}

void loop()
{
lcd.clear();
lcd.home();
lcd.print("Holis :)");
lcd.setCursor(0,1);
lcd.print((millis()/1000));
lcd.print("seg.");
delay(250);

if(digitalRead(8) == 0)
{
  if(luz == 0)
  {
    lcd.setBacklight(LOW);
    luz = 1;
  }
  else
  {
    lcd.setBacklight(HIGH);
    luz = 0;
  }
 delay(500); 
}
}
