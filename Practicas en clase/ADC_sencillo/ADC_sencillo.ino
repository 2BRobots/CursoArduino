int adc,pwm;

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(A0, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  adc = analogRead(A0);
  pwm = map(adc,0,1023,0,255);
  analogWrite(9, pwm);
  delay(20);

}
