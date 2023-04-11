bool readIR(){
  return !digitalRead(IR);
}

long ultrassonicRead(){
  long duracao;
  long distancia;
  digitalWrite(ultrassonic_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrassonic_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrassonic_trig, LOW);
  duracao = pulseIn(ultrassonic_echo, HIGH);
  distancia = duracao/58;  
  
  return distancia;
} 
