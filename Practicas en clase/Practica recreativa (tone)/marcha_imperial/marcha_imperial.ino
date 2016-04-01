#define pin 5

#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880


void setup() 
{
  pinMode(pin, OUTPUT);

}

void loop() 
{


play();
delay(5000);

}
void play()
{
    tone(pin,a, 500);
    delay(500);
    tone(pin,a, 500);
    delay(500);
    tone(pin,a, 500);
    delay(500);
    tone(pin,f, 350);
    delay(350);
    tone(pin,cH, 150);
    delay(150);
    tone(pin,a, 500);
    delay(500);
    tone(pin,f, 350);
    delay(350);
    tone(pin,cH, 150);
    delay(150);
    tone(pin,a, 650);
    delay(650);
 
    delay(150);
    //end of first bit
 
    tone(pin,eH, 500);
    delay(500);
    tone(pin,eH, 500);
    delay(500);
    tone(pin,eH, 500);
    delay(500);
    tone(pin,fH, 350);
    delay(350);
    tone(pin,cH, 150);
    delay(150);
    tone(pin,gS, 500);
    delay(500);
    tone(pin,f, 350);
    delay(350);
    tone(pin,cH, 150);
    delay(150);
    tone(pin,a, 650);
    delay(650);
 
    delay(150);
    //end of second bit...
 
    tone(pin,aH, 500);
    delay(500);
    tone(pin,a, 300);
    delay(300);
    tone(pin,a, 150);
    delay(150);
    tone(pin,aH, 400);
    delay(400);
    tone(pin,gSH, 200);
    delay(200);
    tone(pin,gH, 200);
    delay(200);
    tone(pin,fSH, 125);
    delay(125);
    tone(pin,fH, 125);
    delay(125);
    tone(pin,fSH, 250);
    delay(250);
 
    delay(250);
 
    tone(pin,aS, 250);
    delay(250);
    tone(pin,dSH, 400);
    delay(400);
    tone(pin,dH, 200);
    delay(200);
    tone(pin,cSH, 200);
    delay(200);
    tone(pin,cH, 125);
    delay(125);
    tone(pin,b, 125);
    delay(125);
    tone(pin,cH, 250);
    delay(250);
 
    delay(250);
 
    tone(pin,f, 125);
    delay(125);
    tone(pin,gS, 500);
    delay(500);
    tone(pin,f, 375);
    delay(375);
    tone(pin,a, 125);
    delay(125);
    tone(pin,cH, 500);
    delay(500);
    tone(pin,a, 375);
    delay(375);
    tone(pin,cH, 125);
    delay(125);
    tone(pin,eH, 650);
    delay(650);
    
    //end of third bit... (Though it doesn't play well)
    //let's repeat it
 
    tone(pin,aH, 500);
    delay(500);
    tone(pin,a, 300);
    delay(300);
    tone(pin,a, 150);
    delay(150);
    tone(pin,aH, 400);
    delay(400);
    tone(pin,gSH, 200);
    delay(200);
    tone(pin,gH, 200);
    delay(200);
    tone(pin,fSH, 125);
    delay(125);
    tone(pin,fH, 125);
    delay(125);
    tone(pin,fSH, 250);
    delay(250);
 
    delay(250);
 
    tone(pin,aS, 250);
    delay(250);
    tone(pin,dSH, 400);
    delay(400);
    tone(pin,dH, 200);
    delay(200);
    tone(pin,cSH, 200);
    delay(200);
    tone(pin,cH, 125);
    delay(125);
    tone(pin,b, 125);
    delay(125);
    tone(pin,cH, 250);
    delay(250);
 
    delay(250);
 
    tone(pin,f, 250);
    delay(250);
    tone(pin,gS, 500);
    delay(500);
    tone(pin,f, 375);
    delay(375);
    tone(pin,cH, 125);
    delay(125);
    tone(pin,a, 500);
    delay(500);
    tone(pin,f, 375);
    delay(375);
    tone(pin,cH, 125);
    delay(125);
    tone(pin,a, 650);
    delay(650);
    //end of the song
 
}


