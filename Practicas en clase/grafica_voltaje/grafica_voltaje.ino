void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  Serial.begin(9600);  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  float adc = 0;
  float v = 0;

  adc = analogRead(A0);

  v = (5*adc)/1023;
  Serial.println(v);
  delay(5);

}
