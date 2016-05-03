#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>
#include <EEPROM.h>

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
/*
EEPROM.write(1,255);
EEPROM.write(2,255);
EEPROM.write(3,255);
EEPROM.write(4,255);
*/

if (EEPROM.read(1) == 255)
{
  EEPROM.write(1,char(contra[0]));
}
if (EEPROM.read(2) == 255)
{
  EEPROM.write(2,char(contra[1]));
}
if (EEPROM.read(3) == 255)
{
  EEPROM.write(3,char(contra[2]));
}
if (EEPROM.read(4) == 255)
{
  EEPROM.write(4,char(contra[3]));
}

contra[0] = char(EEPROM.read(1));
contra[1] = char(EEPROM.read(2));
contra[2] = char(EEPROM.read(3));
contra[3] = char(EEPROM.read(4));

/*
Serial.begin(9600);
Serial.println(char(EEPROM.read(1)));
Serial.println(char(EEPROM.read(2)));
Serial.println(char(EEPROM.read(3)));
Serial.println(char(EEPROM.read(4)));


Serial.println(char(contra[0]));
Serial.println(char(contra[1]));
Serial.println(char(contra[2]));
Serial.println(char(contra[3]));
*/
}


void loop()
{
char key = keypad.getKey();

if(key == '*')
{
  lcd.clear();
  lcd.print("Clave anterior:");
  lcd.setCursor(6,1);
  delay(1000);
  byte completar = 0;
  while(completar <=3)
  {
   char tecla = keypad.getKey();
   if (tecla != NO_KEY)
   {
    temp[i] = (char(tecla));
    lcd.print(char(tecla));
    i = i + 1;
    completar++;
   }
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
  lcd.print("Clave nueva:"); 
  lcd.setCursor(6,1);
  delay(2000);
  i = 0;
  j = 0;
  completar = 0;
  while(completar <=3)
  {
   char tecla1 = keypad.getKey();
   if (tecla1 != NO_KEY)
   {
    temp[i] = (char(tecla1));
    lcd.print(char(tecla1));
    i = i + 1;
    completar++;
   }
  }
  EEPROM.write(1,temp[0]);
  EEPROM.write(2,temp[1]);
  EEPROM.write(3,temp[2]);
  EEPROM.write(4,temp[3]);
  lcd.clear();
  lcd.print("Cambio aceptado"); 
  delay(2000);
  lcd.clear();
  contra[0] = char(EEPROM.read(1));
  contra[1] = char(EEPROM.read(2));
  contra[2] = char(EEPROM.read(3));
  contra[3] = char(EEPROM.read(4));
  lcd.print("Introduce clave:");
  lcd.setCursor(6,1); 
  key = keypad.getKey(); 
}
else
{
  lcd.clear();
  lcd.print("Cambio denegado");
  delay(2000);
  lcd.clear();
  lcd.print("Introduce clave:");
  lcd.setCursor(6,1); 
  key = keypad.getKey(); 
}   
i = 0;
j = 0;
}
 
  

  
}
 
if (key != NO_KEY)
{
lcd.print(char(key));
delay(300);
lcd.setCursor((6+i),1);
lcd.print("*");

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
