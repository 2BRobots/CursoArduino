byte pin = 5;

void setup() {
 pinMode(pin, OUTPUT);

}

void loop() 
{
int re = 500;
int re1 = 900;


tone(pin, 262, 400);
delay(re);
tone(pin, 262, 400);
delay(re);
tone(pin, 294, 800);
delay(re1);
tone(pin, 262, 800);
delay(re1);
tone(pin, 349, 800);
delay(re1);
tone(pin, 330, 1000);
delay(re1);
delay(re1);

tone(pin, 262, 400);
delay(re);
tone(pin, 262, 400);
delay(re);
tone(pin, 294, 800);
delay(re1);
tone(pin, 262, 800);
delay(re1);
tone(pin, 392, 800);
delay(re1);
tone(pin, 349, 1000);
delay(re1);
delay(re1);

tone(pin, 262, 400);
delay(re);
tone(pin, 262, 400);
delay(re);
tone(pin, 523, 700);
delay(re1);
tone(pin, 440, 800);
delay(re1);
tone(pin, 349, 800);
delay(re1);
tone(pin, 330, 800);
delay(re1);
tone(pin, 394, 700);
delay(re1);
delay(re1);

tone(pin, 466, 400);
delay(re);
tone(pin, 466, 400);
delay(re);
tone(pin, 440, 700);
delay(re1);
tone(pin, 440, 800);
delay(re1);
tone(pin, 349, 800);
delay(re1);
tone(pin, 392, 800);
delay(re1);
tone(pin, 349, 1600);
delay(re1);


delay(5000);


}
