#include <rgb_matrix.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <NewPing.h>
int BH1750address = 0x23; //setting i2c address

#define N_X 1
#define N_Y 1

//Hardware SPI Matriz de 8x8
#define DATA_PIN  11
#define CLK_PIN   13
#define LATCH_PIN 7

#define TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

//Inicializacion de variables
rgb_matrix M = rgb_matrix(N_X, N_Y, DATA_PIN, CLK_PIN, LATCH_PIN);
String cmd="";
int myChar ; 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup()
{
  //Inicializaciones seriales
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void hook()
{
  int d = status();
  if (myChar != -1){
    if (myChar == 'H'){
      M.clear();
      M.plot(0,0,3,TOP_LAYER);
      M.plot(1,0,3,TOP_LAYER);
      M.plot(2,0,3,TOP_LAYER);
      M.plot(3,0,3,TOP_LAYER);
      M.plot(4,0,3,TOP_LAYER);
      M.plot(5,0,3,TOP_LAYER);
      M.plot(6,0,3,TOP_LAYER);
      M.plot(7,0,3,TOP_LAYER);
      M.plot(0,1,3,TOP_LAYER);
      M.plot(7,1,3,TOP_LAYER);
      M.plot(0,2,3,TOP_LAYER);
      M.plot(2,2,3,TOP_LAYER);
      M.plot(5,2,3,TOP_LAYER);
      M.plot(7,2,3,TOP_LAYER);
      M.plot(0,3,3,TOP_LAYER);
      M.plot(7,3,3,TOP_LAYER);
      M.plot(0,4,3,TOP_LAYER);
      M.plot(2,4,3,TOP_LAYER);
      M.plot(3,4,3,TOP_LAYER);
      M.plot(4,4,3,TOP_LAYER);
      M.plot(5,4,3,TOP_LAYER);
      M.plot(7,4,3,TOP_LAYER);
      M.plot(0,5,3,TOP_LAYER);
      M.plot(3,5,3,TOP_LAYER);
      M.plot(4,5,3,TOP_LAYER);
      M.plot(7,5,3,TOP_LAYER);
      M.plot(0,6,3,TOP_LAYER);
      M.plot(7,6,3,TOP_LAYER);
      M.plot(0,7,3,TOP_LAYER);
      M.plot(1,7,3,TOP_LAYER);
      M.plot(2,7,3,TOP_LAYER);
      M.plot(3,7,3,TOP_LAYER);
      M.plot(4,7,3,TOP_LAYER);
      M.plot(5,7,3,TOP_LAYER);
      M.plot(6,7,3,TOP_LAYER);
      M.plot(7,7,3,TOP_LAYER);
    }
    if (myChar == 'S'){
      M.clear();
      M.plot(0,0,4,TOP_LAYER);
      M.plot(1,0,4,TOP_LAYER);
      M.plot(2,0,4,TOP_LAYER);
      M.plot(3,0,4,TOP_LAYER);
      M.plot(4,0,4,TOP_LAYER);
      M.plot(5,0,4,TOP_LAYER);
      M.plot(6,0,4,TOP_LAYER);
      M.plot(7,0,4,TOP_LAYER);
      M.plot(0,1,4,TOP_LAYER);
      M.plot(7,1,4,TOP_LAYER);
      M.plot(0,2,4,TOP_LAYER);
      M.plot(2,2,4,TOP_LAYER);
      M.plot(5,2,4,TOP_LAYER);
      M.plot(7,2,4,TOP_LAYER);
      M.plot(0,3,4,TOP_LAYER);
      M.plot(7,3,4,TOP_LAYER);
      M.plot(0,5,4,TOP_LAYER);
      M.plot(2,5,4,TOP_LAYER);
      M.plot(3,5,4,TOP_LAYER);
      M.plot(4,5,4,TOP_LAYER);
      M.plot(5,5,4,TOP_LAYER);
      M.plot(7,5,4,TOP_LAYER);
      M.plot(0,4,4,TOP_LAYER);
      M.plot(3,4,4,TOP_LAYER);
      M.plot(4,4,4,TOP_LAYER);
      M.plot(7,4,4,TOP_LAYER);
      M.plot(0,6,4,TOP_LAYER);
      M.plot(7,6,4,TOP_LAYER);
      M.plot(0,7,4,TOP_LAYER);
      M.plot(1,7,4,TOP_LAYER);
      M.plot(2,7,4,TOP_LAYER);
      M.plot(3,7,4,TOP_LAYER);
      M.plot(4,7,4,TOP_LAYER);
      M.plot(5,7,4,TOP_LAYER);
      M.plot(6,7,4,TOP_LAYER);
      M.plot(7,7,4,TOP_LAYER);
    }
    if (myChar == 'L'){
      M.clear();
      M.plot(1,1,1,TOP_LAYER);
      M.plot(2,1,1,TOP_LAYER);
      M.plot(5,1,1,TOP_LAYER);
      M.plot(6,1,1,TOP_LAYER);
      M.plot(0,2,1,TOP_LAYER);
      M.plot(1,2,1,TOP_LAYER);
      M.plot(2,2,1,TOP_LAYER);
      M.plot(3,2,1,TOP_LAYER);
      M.plot(4,2,1,TOP_LAYER);
      M.plot(5,2,1,TOP_LAYER);
      M.plot(6,2,1,TOP_LAYER);
      M.plot(7,2,1,TOP_LAYER);
      M.plot(0,3,1,TOP_LAYER);
      M.plot(1,3,1,TOP_LAYER);
      M.plot(2,3,1,TOP_LAYER);
      M.plot(3,3,1,TOP_LAYER);
      M.plot(4,3,1,TOP_LAYER);
      M.plot(5,3,1,TOP_LAYER);
      M.plot(6,3,1,TOP_LAYER);
      M.plot(7,3,1,TOP_LAYER);
      M.plot(1,4,1,TOP_LAYER);
      M.plot(2,4,1,TOP_LAYER);
      M.plot(3,4,1,TOP_LAYER);
      M.plot(4,4,1,TOP_LAYER);
      M.plot(5,4,1,TOP_LAYER);
      M.plot(6,4,1,TOP_LAYER);
      M.plot(2,5,1,TOP_LAYER);
      M.plot(3,5,1,TOP_LAYER);
      M.plot(4,5,1,TOP_LAYER);
      M.plot(5,5,1,TOP_LAYER);
      M.plot(3,6,1,TOP_LAYER);
      M.plot(4,6,1,TOP_LAYER);
    }
    if (myChar == 'A'){
      M.clear();
      M.plot(0,0,1,TOP_LAYER);
      M.plot(1,0,1,TOP_LAYER);
      M.plot(2,0,1,TOP_LAYER);
      M.plot(3,0,1,TOP_LAYER);
      M.plot(4,0,1,TOP_LAYER);
      M.plot(5,0,1,TOP_LAYER);
      M.plot(6,0,1,TOP_LAYER);
      M.plot(7,0,1,TOP_LAYER);
      M.plot(0,1,1,TOP_LAYER);
      M.plot(7,1,1,TOP_LAYER);
      M.plot(0,2,1,TOP_LAYER);
      M.plot(2,2,1,TOP_LAYER);
      M.plot(5,2,1,TOP_LAYER);
      M.plot(7,2,1,TOP_LAYER);
      M.plot(0,3,1,TOP_LAYER);
      M.plot(7,3,1,TOP_LAYER);
      M.plot(0,5,1,TOP_LAYER);
      M.plot(2,5,1,TOP_LAYER);
      M.plot(3,5,1,TOP_LAYER);
      M.plot(4,5,1,TOP_LAYER);
      M.plot(5,5,1,TOP_LAYER);
      M.plot(7,5,1,TOP_LAYER);
      M.plot(0,4,1,TOP_LAYER);
      M.plot(3,4,1,TOP_LAYER);
      M.plot(4,4,1,TOP_LAYER);
      M.plot(7,4,1,TOP_LAYER);
      M.plot(0,6,1,TOP_LAYER);
      M.plot(7,6,1,TOP_LAYER);
      M.plot(0,7,1,TOP_LAYER);
      M.plot(1,7,1,TOP_LAYER);
      M.plot(2,7,1,TOP_LAYER);
      M.plot(3,7,1,TOP_LAYER);
      M.plot(4,7,1,TOP_LAYER);
      M.plot(5,7,1,TOP_LAYER);
      M.plot(6,7,1,TOP_LAYER);
      M.plot(7,7,1,TOP_LAYER);
    }
    if (myChar == 1){
      M.clear();
      M.plot(0,0,2,TOP_LAYER);
      M.plot(1,0,2,TOP_LAYER);
      M.plot(2,0,2,TOP_LAYER);
      M.plot(3,0,2,TOP_LAYER);
      M.plot(4,0,2,TOP_LAYER);
      M.plot(5,0,2,TOP_LAYER);
      M.plot(6,0,2,TOP_LAYER);
      M.plot(7,0,2,TOP_LAYER);
      M.plot(0,1,2,TOP_LAYER);
      M.plot(7,1,2,TOP_LAYER);
      M.plot(0,2,2,TOP_LAYER);
      M.plot(2,2,2,TOP_LAYER);
      M.plot(5,2,2,TOP_LAYER);
      M.plot(7,2,2,TOP_LAYER);
      M.plot(0,3,2,TOP_LAYER);
      M.plot(7,3,2,TOP_LAYER);
      M.plot(0,5,2,TOP_LAYER);
      M.plot(2,5,2,TOP_LAYER);
      M.plot(3,5,2,TOP_LAYER);
      M.plot(4,5,2,TOP_LAYER);
      M.plot(5,5,2,TOP_LAYER);
      M.plot(7,5,2,TOP_LAYER);
      M.plot(0,4,2,TOP_LAYER);
      M.plot(7,4,2,TOP_LAYER);
      M.plot(0,6,2,TOP_LAYER);
      M.plot(7,6,2,TOP_LAYER);
      M.plot(0,7,2,TOP_LAYER);
      M.plot(1,7,2,TOP_LAYER);
      M.plot(2,7,2,TOP_LAYER);
      M.plot(3,7,2,TOP_LAYER);
      M.plot(4,7,2,TOP_LAYER);
      M.plot(5,7,2,TOP_LAYER);
      M.plot(6,7,2,TOP_LAYER);
      M.plot(7,7,2,TOP_LAYER);
    }
    if (myChar == 'T'){
      M.clear();
      M.plot(0,0,6,TOP_LAYER);
      M.plot(1,0,6,TOP_LAYER);
      M.plot(2,0,6,TOP_LAYER);
      M.plot(3,0,6,TOP_LAYER);
      M.plot(4,0,6,TOP_LAYER);
      M.plot(5,0,6,TOP_LAYER);
      M.plot(6,0,6,TOP_LAYER);
      M.plot(7,0,6,TOP_LAYER);
      M.plot(0,1,6,TOP_LAYER);
      M.plot(7,1,6,TOP_LAYER);
      M.plot(0,2,6,TOP_LAYER);
      M.plot(7,2,6,TOP_LAYER);
      M.plot(0,3,6,TOP_LAYER);
      M.plot(3,3,6,TOP_LAYER);
      M.plot(4,3,6,TOP_LAYER);
      M.plot(7,3,6,TOP_LAYER);
      M.plot(0,4,6,TOP_LAYER);
      M.plot(3,4,6,TOP_LAYER);
      M.plot(4,4,6,TOP_LAYER);
      M.plot(7,4,6,TOP_LAYER);
      M.plot(0,5,6,TOP_LAYER);
      M.plot(7,5,6,TOP_LAYER);
      M.plot(0,6,6,TOP_LAYER);
      M.plot(7,6,6,TOP_LAYER);
      M.plot(0,7,6,TOP_LAYER);
      M.plot(1,7,6,TOP_LAYER);
      M.plot(2,7,6,TOP_LAYER);
      M.plot(3,7,6,TOP_LAYER);
      M.plot(4,7,6,TOP_LAYER);
      M.plot(5,7,6,TOP_LAYER);
      M.plot(6,7,6,TOP_LAYER);
      M.plot(7,7,6,TOP_LAYER);
    }
    if (myChar == 3){
      M.clear();
      M.plot(0,0,3,TOP_LAYER);
      M.plot(1,0,3,TOP_LAYER);
      M.plot(2,0,3,TOP_LAYER);
      M.plot(3,0,3,TOP_LAYER);
      M.plot(4,0,3,TOP_LAYER);
      M.plot(5,0,3,TOP_LAYER);
      M.plot(6,0,3,TOP_LAYER);
      M.plot(7,0,3,TOP_LAYER);
      M.plot(0,1,3,TOP_LAYER);
      M.plot(7,1,3,TOP_LAYER);
      M.plot(0,2,3,TOP_LAYER);
      M.plot(7,2,3,TOP_LAYER);
      M.plot(0,3,3,TOP_LAYER);
      M.plot(3,3,3,TOP_LAYER);
      M.plot(4,3,3,TOP_LAYER);
      M.plot(7,3,3,TOP_LAYER);
      M.plot(0,4,3,TOP_LAYER);
      M.plot(3,4,3,TOP_LAYER);
      M.plot(4,4,3,TOP_LAYER);
      M.plot(7,4,3,TOP_LAYER);
      M.plot(0,5,3,TOP_LAYER);
      M.plot(7,5,3,TOP_LAYER);
      M.plot(0,6,3,TOP_LAYER);
      M.plot(7,6,3,TOP_LAYER);
      M.plot(0,7,3,TOP_LAYER);
      M.plot(1,7,3,TOP_LAYER);
      M.plot(2,7,3,TOP_LAYER);
      M.plot(3,7,3,TOP_LAYER);
      M.plot(4,7,3,TOP_LAYER);
      M.plot(5,7,3,TOP_LAYER);
      M.plot(6,7,3,TOP_LAYER);
      M.plot(7,7,3,TOP_LAYER);
    }
    if (myChar == 2){
      M.clear();
      M.plot(0,0,1,TOP_LAYER);
      M.plot(1,0,1,TOP_LAYER);
      M.plot(2,0,1,TOP_LAYER);
      M.plot(3,0,1,TOP_LAYER);
      M.plot(4,0,1,TOP_LAYER);
      M.plot(5,0,1,TOP_LAYER);
      M.plot(6,0,1,TOP_LAYER);
      M.plot(7,0,1,TOP_LAYER);
      M.plot(0,1,1,TOP_LAYER);
      M.plot(7,1,1,TOP_LAYER);
      M.plot(0,2,1,TOP_LAYER);
      M.plot(7,2,1,TOP_LAYER);
      M.plot(0,3,1,TOP_LAYER);
      M.plot(3,3,1,TOP_LAYER);
      M.plot(4,3,1,TOP_LAYER);
      M.plot(7,3,1,TOP_LAYER);
      M.plot(0,4,1,TOP_LAYER);
      M.plot(3,4,1,TOP_LAYER);
      M.plot(4,4,1,TOP_LAYER);
      M.plot(7,4,1,TOP_LAYER);
      M.plot(0,5,1,TOP_LAYER);
      M.plot(7,5,1,TOP_LAYER);
      M.plot(0,6,1,TOP_LAYER);
      M.plot(7,6,1,TOP_LAYER);
      M.plot(0,7,1,TOP_LAYER);
      M.plot(1,7,1,TOP_LAYER);
      M.plot(2,7,1,TOP_LAYER);
      M.plot(3,7,1,TOP_LAYER);
      M.plot(4,7,1,TOP_LAYER);
      M.plot(5,7,1,TOP_LAYER);
      M.plot(6,7,1,TOP_LAYER);
      M.plot(7,7,1,TOP_LAYER);
    }
    if (myChar == 0){
      if (d > 20){
        myChar = 'S';
      }else{
        myChar = 'H';
      }
    }
  }
  
  
  //Lectura Serial
  if(Serial.available()){
    myChar = Serial.read();
  }
  Serial.println(d);
 
}

int status(){
  //int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  //return uS / US_ROUNDTRIP_CM;
  
}

void loop()
{
  myChar = 'T';
  M.set_cur(0,0);   
  M.display(hook);
}
