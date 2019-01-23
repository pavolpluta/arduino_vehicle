 void stop() {
 
  digitalWrite(R_MOTOR_PIN_DIR, LOW);
  digitalWrite(L_MOTOR_PIN_DIR, LOW);
  
  analogWrite(R_MOTOR_PIN, LOW);
  analogWrite(L_MOTOR_PIN, LOW); 
}


//DIRECTION: FORWARD_DIR = SET DIR TO 'LOW'
//DIRECTION: BACKWARDS_DIR = SET DIR TO 'HIGH'
  
//GOING FORWARD_DIR: 0 (80) - SLOWEST, 255 - FASTEST
//GOING BACKWARDS_DIR: 255 (170) - SLOWEST, 0 - FASTEST

//STOPPING
//FORWARD_DIR: SET SPEED TO 0
//BACKWARDS_DIR: SET SPEED TO 255

void moveBack(){
   checkButton();
   digitalWrite(R_MOTOR_PIN_DIR, BACKWARDS_DIR);
   digitalWrite(L_MOTOR_PIN_DIR, BACKWARDS_DIR);
 
   analogWrite(R_MOTOR_PIN, BACKWARDS_DIR_SPEED);
   analogWrite(L_MOTOR_PIN, BACKWARDS_DIR_SPEED);
   delay(800);
   
   stop();
 }

void moveForward(int speed){
    checkButton();
   digitalWrite(R_MOTOR_PIN_DIR, FORWARD_DIR);
   digitalWrite(L_MOTOR_PIN_DIR, FORWARD_DIR);
 
   analogWrite(R_MOTOR_PIN, speed);
   analogWrite(L_MOTOR_PIN, speed);
}

void turn(char dir){
  checkButton();
  if (dir == LEFT){
   digitalWrite(R_MOTOR_PIN_DIR, FORWARD_DIR);
   digitalWrite(L_MOTOR_PIN_DIR, BACKWARDS_DIR);

   analogWrite(R_MOTOR_PIN, 0);
   analogWrite(L_MOTOR_PIN, BACKWARDS_DIR_SPEED);   
  } else if (dir == RIGHT){   
   digitalWrite(R_MOTOR_PIN_DIR, BACKWARDS_DIR);
   digitalWrite(L_MOTOR_PIN_DIR, FORWARD_DIR);

   analogWrite(R_MOTOR_PIN, BACKWARDS_DIR_SPEED);
   analogWrite(L_MOTOR_PIN, 0);
   }
   
   delay(1100);   
   stop();
}
