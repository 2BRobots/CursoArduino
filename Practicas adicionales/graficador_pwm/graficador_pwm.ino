float adc,pwm, g;

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  adc = analogRead(A0);
  pwm = map(adc,0,1023,0,255);
  analogWrite(9, pwm);
  g = (5 * (analogRead(A1)))/1023;
  Serial.println(g);
  delay(1);
  

}
