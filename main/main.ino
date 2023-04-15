/**********************************************************
* UNIVERSIDADE FEDERAL DE PERNAMBUCO - UFPE
* CENTRO DE INFORMARICA - CIN
* INTRODUCAO A PROGRAMACAO COM GALILEO - IF668 EC
********************************************************/

//pino do sensor
int IR = 2; 
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

// Controlar tempo
const unsigned long duracaoManobra = 1500;

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
  setSpeed(60);
   if (ultrassonicRead() < 6) {
    stop();
    delay(1000);
    rotateLeft();
    delay(350);
    forward();
    delay(800);
    unsigned long tempoInicioManobra = millis();
    if (millis() - tempoInicioManobra >= duracaoManobra) {
      tempoInicioManobra = millis();
      rotateRight();
      delay(200);
      forward();
      delay(1000);
    }
  }else if(linhaBranca()){
    turnLeft();
  }
  else if(linhaPreta()){
    turnRight();
  }
}
