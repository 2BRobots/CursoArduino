#include "SevSeg.h"
SevSeg sevseg;

void setup() {
pinMode(A6, INPUT);  
Serial.begin(9600);

byte numDigits = 4;   
byte digitPins[] = {2, 3, 4, 5};
byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};

sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
sevseg.setBrightness(100);

}

void loop() {
float t;
float adc = analogRead(A6);
t = (((adc)*500)/1023);  
//Serial.print("La temperatura es de: ");
//Serial.print(t);
//Serial.println(" C.");
int c = t*10;
sevseg.setNumber(c,1);
sevseg.refreshDisplay();
}
