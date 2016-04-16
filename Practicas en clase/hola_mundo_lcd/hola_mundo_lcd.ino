#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);


void setup() {
lcd.begin(16,2);
delay(100);
}

void loop() 
{
lcd.clear();
lcd.print("Encendido hace: ");
lcd.setCursor(0,1);
lcd.print((millis()/1000));
lcd.print(" seg.");
delay(1000);
}
