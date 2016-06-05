#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  irrecv.enableIRIn(); // Start the receiver
  pinMode(13,OUTPUT);
}

void loop() 
{
  if (irrecv.decode(&results)) 
  {
    
    long int decCode = results.value;
    String hexCode = String(decCode, HEX);
    String decodedSignal = decodeSignal(hexCode);

    
    if(decodedSignal == "UP    ")
    {
      digitalWrite(13, HIGH);
    }

    if(decodedSignal == "LEFT  ")
    {
      digitalWrite(13, LOW);
    }

     if(decodedSignal == "DOWN  ")
    {
      digitalWrite(13, HIGH);
      delay(5000);
      digitalWrite(13, LOW);
    }

    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

String decodeSignal(String hex) //Interpreta el codigo de los botones y devuelve el boton presionado. 
{
  hex.toUpperCase();
  //if(hex == "FFA25D") return "power";
  if(hex == "FF629D") return "UP    ";
  //if(hex == "FFE21D") return "mute";

  if(hex == "FF22DD") return "LEFT  ";
  if(hex == "FF02FD") return "OK    ";
  if(hex == "FFC23D") return "RIGHT ";

  //if(hex == "FFE01F") return "eq";
  if(hex == "FFA857") return "DOWN  ";
  //if(hex == "FF906F") return "+";

  if(hex == "FF6897") return "1     ";
  if(hex == "FF9867") return "2     ";
  if(hex == "FFB04F") return "3     ";

  if(hex == "FF30CF") return "4     ";
  if(hex == "FF18E7") return "5     ";
  if(hex == "FF7A85") return "6     ";

  if(hex == "FF10EF") return "7     ";
  if(hex == "FF38C7") return "8     ";
  if(hex == "FF5AA5") return "9     ";

  if(hex == "FF42BD") return "*     ";
  if(hex == "FF4AB5") return "0     ";
  if(hex == "FF52AD") return "#     ";
  return "unknown";


}
