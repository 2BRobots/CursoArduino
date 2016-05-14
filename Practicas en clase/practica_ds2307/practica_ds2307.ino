#include <Wire.h>
#include "RTClib.h"
#include <Servo.h>

Servo servo1;
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

void setup() 
{
Serial.begin(9600);
pinMode(7,INPUT_PULLUP);
pinMode(9, OUTPUT);
servo1.attach(9);
servo1.write(90);

if (! rtc.isrunning()) 
  {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

}

void loop() 
{
 DateTime now = rtc.now();

 if (digitalRead(7) == 0)
 {
  Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    delay(500);
 }

 int hora = now.hour();
 int minu = now.minute();

 if(hora == 13 && minu == 15)
 {
   servo1.write(150);
   delay(1000);
   servo1.write(90);
   delay(60000);
 }
 
  
}


