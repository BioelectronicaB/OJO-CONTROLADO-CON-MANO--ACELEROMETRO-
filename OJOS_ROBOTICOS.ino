#include <Servo.h>
#include <MPU6050.h>//Libreria acelerometro
Servo myServo1; //Servo 1 HORIZONTAL
Servo myServo2; //Servo 2 VERTICAL
MPU6050 mpu;        //declaramos el sensor

int16_t ax, ay, az, gx, gy, gz; //variables del sensor

void setup() 
{
Serial.begin(9600); //iniciamos comunicacion serial
myServo1.attach(7); //
myServo2.attach(8); //
myServo1.write(100);   //
myServo2.write(100);   //
mpu.initialize();   //Iniciamos acelerometro
if (!mpu.testConnection()) { while (1); }
delay(1000);
}

void loop() 
{
 mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); //obtenemos variables del sensor
 ax=-(ax/1000);    //ariba - abajo mapear monitor
 ay=(ay/1000);    //izquierda - derecha mapear monitor
 Serial.print(ax); 
 Serial.print(",");
 Serial.print(ay); 
    
///HORIZONTAL    
int x= map(ay ,-10, 10, 10,170);
myServo1.write(x);   //horizontal
delay(5);
  Serial.print(",");
 Serial.print(x); 
////VERTICAL
int y= map(ax ,-10, 10, 150,50);
myServo2.write(y);   //horizontal
delay(5);
    Serial.print(",");
 Serial.println(y);     
//     for (int x=100; x <=150; x++) 
//     {
//      myServo2.write(x);   //base
//
//     delay(10);
//     }
//     ///HORIZONTAL    
//       for (int x=120; x >=20; x--) 
//     {
//     myServo1.write(x);   //griper
//    delay(10);
//     }
//////VERTICAL
//     for (int x=150; x >=100; x--) 
//     {
//      myServo2.write(x);   //base
//
//     delay(10);
//     }
//     ////COMBINADO
//     for (int x=150; x >=100; x--) 
//     {
//      myServo1.write(x);   //griper
//      myServo2.write(x);   //base
//
//     delay(15);
//     }
}
