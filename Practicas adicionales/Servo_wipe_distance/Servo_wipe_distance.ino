// *---------------------------------------------------------------------------------------------------------*
// *Ejemplo para mover servo en funcion de la distancia leida por un sensor ultrasonico de distancia.        *
// *Requiere la libreria NewPing, puede descargarse aqui: http://playground.arduino.cc/Code/NewPing#Download *
// *Escrito por: Daniel Arturo Fernández Raygoza para DAFR Electronics. Licencia creative commons CC-BY-NC-SA*
// *---------------------------------------------------------------------------------------------------------*

#include <NewPing.h>
#include <Servo.h>

#define TRIGGER_PIN  12  // pin de Arduino conectado al pin TRIGGER del sensor ultrasonico. 
#define ECHO_PIN     11  // pin de Arduino conectado al pin ECHO del sensor ultrasonico. 
#define MAX_DISTANCE 200 // distancia maxima que deseamos medir con el sensor (en centimetros). Distancia maxima del sensor es de 400cm aproximadamente. 
#define SERVO_PIN 9 // pin de Arduino conectado al pin de control del servo.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // configuracion e inicializacion de la libreria NewPing.
Servo SG90; //crea el objeto para controlar el servo a travez de la libreria. 

float distancia = 0;
float angulo = 180;

void setup() 
{
  Serial.begin(9600); // abrir puerto serial para visualizar la distancia y el angulo. 
  SG90.attach(SERVO_PIN); //inicia el servo en el pin seleccionado.
  SG90.write(angulo); // pone el servo a 180°.
  delay(250);
  Serial.println("Arduino listo! :)");
  
}

void loop() 
{  
  distancia = sonar.ping_cm();  
  Serial.print("Distancia: ");
  Serial.print(distancia); // enviar distancia leida, "0" significa fuera de rango. Recordar que la distancia minima que puede leer el sensor es de 2cm.
  Serial.print("cm. - Angulo: ");
  angulo = map(distancia, 0, MAX_DISTANCE, 0, 180); //calcula el angulo del servo en base a la distancia minima y maxima. 
  if (distancia == 0) //si la distancia esta fuera de rango pone el servo a 180°. 
  {
    angulo = 180; 
   }
  Serial.print(angulo); //enviar angulo en en cual se posicinara el servo. 
  Serial.print(" grados. ");
  if (distancia == 0) //si la distancia esta fuera de rango envia mensaje. 
  {
    Serial.print(" La distancia se encuentra fuera de rango.");
  }
  SG90.write(angulo);
  delay(100);  
  Serial.println(""); //salto de linea. 
}
