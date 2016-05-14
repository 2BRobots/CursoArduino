int x = 0;

void setup()
{
pinMode(13, OUTPUT);
OCR0A = 0xAF; //valor en hexadecimal en el cual se llevara   a cabo la interrupción, en este caso cada 0.7ms
TIMSK0 |= _BV(OCIE0A); //crea el evento de comparación  para la interrupción
}

void loop() 
{


}

SIGNAL(TIMER0_COMPA_vect) 
{
if (x >= 2000) //cada 1.4 segundos se cumple
{
x = 0;
digitalWrite(13, !(digitalRead(13)));
}
x++;
}

