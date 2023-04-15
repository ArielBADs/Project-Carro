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

void turnRight(){
  stopRight();
  driveMotor('L','F');
}

void turnLeft(){
  stopLeft();
  driveMotor('R','F');
}

void rotateLeft(){
  driveMotor('L','B');
  driveMotor('R','F');
}

void rotateRight(){
  driveMotor('R','B');
  driveMotor('L','F');
}

void stopLeft(){
  driveMotor('L','S');
}

void stopRight(){
  driveMotor('R','S');
}

void stop(){
  driveMotor('L','S');
  driveMotor('R','S');
}
