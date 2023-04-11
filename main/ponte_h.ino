void driveMotor(char wheel, char direction){
  if(wheel == 'L'){
    if(direction == 'F'){
      digitalWrite(LB, LOW);
      digitalWrite(LF, HIGH);
    }
    else if(direction == 'B'){
      digitalWrite(LF, LOW);
      digitalWrite(LB, HIGH); 
    }
    else{
      digitalWrite(LF, LOW);
      digitalWrite(LB, LOW);
    }
  }
  if(wheel == 'R'){
    if(direction == 'F'){
      digitalWrite(RB, LOW);
      digitalWrite(RF, HIGH);
    }
    else if(direction == 'B'){
      digitalWrite(RF, LOW);
      digitalWrite(RB, HIGH); 
    }
    else{
      digitalWrite(RF, LOW);
      digitalWrite(RB, LOW);
    }
  }  
}

void setSpeed(int speed){
  analogWrite(LV, speed);
  analogWrite(RV, speed);
}

void forward(){
  driveMotor('L','F');
  driveMotor('R','F');
}

void backward(){
  driveMotor('L','B');
  driveMotor('R','B');
}

void turnRight(int turnSpeed){
  analogWrite(LV, turnSpeed);
  driveMotor('L','F');
  driveMotor('R','F');
}

void turnLeft(int turnSpeed){
  analogWrite(RV, turnSpeed);
  driveMotor('L','F');
  driveMotor('R','F');
}

void rotateLeft(){
  driveMotor('L','B');
  driveMotor('R','F');
}

void rotateRight(){
  driveMotor('L','B');
  driveMotor('R','F');
}

void StopLeft(){
  driveMotor('L','S');
}

void StopRight(){
  driveMotor('R','S');
}

void Stop(){
  driveMotor('L','S');
  driveMotor('R','S');
}
  
