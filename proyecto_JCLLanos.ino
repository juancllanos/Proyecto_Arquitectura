#include <Servo.h>
#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  

SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
Servo servoMotor1;
Servo servoMotor2;
char dato = 0;

 
void setup()
{
  Serial.begin(9600);   // Inicializamos  el puerto serie  
  BT.begin(38400);
  servoMotor1.attach(3);
  servoMotor2.attach(5);
}
 
void loop()
{
  if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    dato = BT.read();
    Serial.println("Leido BT");
    Serial.println(dato);
    if(dato == '1'){
      //servoMotor1.write(180);
      servoMotor2.write(0);
    }
    if(dato == '0'){
      //servoMotor1.write(0);
      servoMotor2.write(39);
      
    }
     
  }
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BT.write(Serial.read());
  }
}

//Nombre = SMRT_BULB
//Password = 1209

// -5 el de abajo
// -3 el de arriba
