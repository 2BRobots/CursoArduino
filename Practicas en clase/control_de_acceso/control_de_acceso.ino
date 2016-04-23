#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {2,3,4,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7); 
Servo servo1;


char contra[4] = {'1','2','3','4'};
char temp[4];
byte i = 0;
byte j = 0;

void setup() 
{
lcd.begin(16,2);
lcd.setBacklightPin(3, POSITIVE);
lcd.setBacklight(HIGH);
servo1.attach(9);
delay(500);
lcd.print("Introduce clave:");
lcd.setCursor(6,1);
servo1.write(90);
}


void loop()
{
char key = keypad.getKey();
 
if (key != NO_KEY)
{
lcd.print(char(key));
temp[i] = (char(key));
i = i + 1;
}

if (i == 4)
{
delay(250);
for(byte x=0;x<4;x++)
{
  if((temp[x]) == (contra[x]))
  {
    j = j + 1; 
  }
}

if(j == 4)
{
  lcd.clear();
  lcd.print("Bienvenido"); 
  servo1.write(140);
  delay(1500);
  servo1.write(90);
}
else
{
  lcd.clear();
  lcd.print("Incorrecto"); 
}

delay(2000);
lcd.clear();
lcd.print("Introduce clave:");
lcd.setCursor(6,1);
i = 0;
j = 0;
}

}
