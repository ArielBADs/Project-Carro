#include <Ultrasonic.h>

/**********************************************************
* UNIVERSIDADE FEDERAL DE PERNAMBUCO - UFPE
* CENTRO DE INFORMARICA - CIN
* INTRODUCAO A PROGRAMACAO COM GALILEO - IF668 EC
********************************************************/

//pino do sensor
int IR = 2; 
int teste = 0;
int rodou = 0;
//Pinagem da placa
int LF = 7;
int LB = 6;
int RF = 4;
int RB = 5;
int LV = 9;
int RV = 3;
// Pino do sensor d
int ultrassonic_echo = 10;
int ultrassonic_trig = 8;

void setup() {
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LV, OUTPUT);
  pinMode(RV, OUTPUT);
  pinMode(IR, INPUT);
  pinMode(ultrassonic_echo, INPUT);
  pinMode(ultrassonic_trig, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if(ultrassonicRead() < 10){
    Stop();
    setSpeed(30);
    rotateLeft();
    forward();
    delay(500);
    rotateRight();
  }
  else if(readIR()){
    turnRight(60);
    StopLeft();
  }
  else if(!readIR()){
    turnLeft(60);
    StopRight();
  }
}
