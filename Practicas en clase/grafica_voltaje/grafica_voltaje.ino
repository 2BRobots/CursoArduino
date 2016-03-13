void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  Serial.begin(250000);  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  float adc = 0;
  float v = 0;


  Serial.println(analogRead(A1));
  delay(100);

}
