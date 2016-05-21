#define f1  A0
#define f2  A1 
#define f3  A2 
#define f4  A3 
#define f5  A4 
#define f6  A5 
#define f7  2
#define f8  3

#define c1  4
#define c2  5
#define c3  6
#define c4  7
#define c5  8
#define c6  9
#define c7  10
#define c8  11

int pincol[8] = {c1,c2,c3,c4,c5,c6,c7,c8};
int pinfil[8] = {f1,f2,f3,f4,f5,f6,f7,f8};

boolean matriz[8][8] = 
{
{1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0}
};


void setup() 
{
pinMode(f1,OUTPUT);
pinMode(f2,OUTPUT);
pinMode(f3,OUTPUT);
pinMode(f4,OUTPUT);
pinMode(f5,OUTPUT);
pinMode(f6,OUTPUT);
pinMode(f7,OUTPUT);
pinMode(f8,OUTPUT);

pinMode(c1,OUTPUT);
pinMode(c2,OUTPUT);
pinMode(c3,OUTPUT);
pinMode(c4,OUTPUT);
pinMode(c5,OUTPUT);
pinMode(c6,OUTPUT);
pinMode(c7,OUTPUT);
pinMode(c8,OUTPUT);

OCR0A = 0xAF; 
TIMSK0 |= _BV(OCIE0A);
}

void loop() 
{
  

}


SIGNAL(TIMER0_COMPA_vect) 
{
for(byte c=0 ;c<=7;c++)
{ 
  digitalWrite(c1, HIGH);
  digitalWrite(c2, HIGH);
  digitalWrite(c3, HIGH);
  digitalWrite(c4, HIGH);
  digitalWrite(c5, HIGH);
  digitalWrite(c6, HIGH);
  digitalWrite(c7, HIGH);
  digitalWrite(c8, HIGH);
  digitalWrite(pincol[c], LOW);
  
  for(byte f=0;f<=0;f++)
  {
    if(f>0)
    {
    digitalWrite(pinfil[f-1], LOW); 
    }
    
    digitalWrite(pinfil[f], matriz[f][c]); 
    delayMicroseconds(800);
  } 
  digitalWrite(f8, LOW);
}
  digitalWrite(c1, HIGH);
  digitalWrite(c2, HIGH);
  digitalWrite(c3, HIGH);
  digitalWrite(c4, HIGH);
  digitalWrite(c5, HIGH);
  digitalWrite(c6, HIGH);
  digitalWrite(c7, HIGH);
  digitalWrite(c8, HIGH);

}
