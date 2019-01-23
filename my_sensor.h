int measureDistance(){
  checkButton();
  long duration;
  long distance = 0;
    
  for (int i = 0; i < 3; i++){
    digitalWrite(PIN_SENSOR_TRIGGER, LOW); 
    delayMicroseconds(2); 
    digitalWrite(PIN_SENSOR_TRIGGER, HIGH);
    delayMicroseconds(10); 
    digitalWrite(PIN_SENSOR_TRIGGER, LOW);
    duration = pulseIn(PIN_SENSOR_ECHO, HIGH);
    
    distance += (duration / 2) / 29.1; 
    }

  distance = distance/3;
  return distance;
}

void manageRisk(){  
  stop();
  moveServo(LEFT_SIDE_SERVO);
  delay(200);
  int leftDist = measureDistance();
  moveServo(RIGHT_SIDE_SERVO);
  delay(500);
  int rightDist = measureDistance();
  moveServo(FRONT_SIDE_SERVO);

  if (leftDist <= RISK_DIST && rightDist <= RISK_DIST){
    //change state
    robotModeIndicator = LOW;
    lastButtonState = HIGH;
  } else if (leftDist >= rightDist){
    turn(LEFT);        
  } else {
    turn(RIGHT);
  }
}

int lookAround(int distance){
   moveServo(60);
   int lDist = measureDistance();
   if (lDist <= RISK_DIST){
    return lDist;
   }

   moveServo(123);
   int rDist = measureDistance();
   if (rDist <= RISK_DIST){
      return rDist;
    }
    
   return distance;
}

int processReadSensor(int state){
 checkButton();
 moveServo(FRONT_SIDE_SERVO);
 long distance = measureDistance();
 
 if (state == STATE_IDLE){
    if (distance < RISK_DIST){
        moveBack();
      } else if (distance >= VERY_FAR_DIST){
         //change state
        robotModeIndicator = HIGH;
        lastButtonState = LOW;        
      } else {
        stop();
      }
  } else if (state == STATE_MOVING){     
    
    if (distance > RISK_DIST){
      distance = lookAround(distance);  
    }
        
    if (distance > FAR_DIST){
      return REGIME_FAST;
    } else if (distance <= FAR_DIST && distance > MEDIUM_DIST){
      return REGIME_MEDIUM;
    } else if (distance <= MEDIUM_DIST && distance > RISK_DIST){
      return REGIME_SLOW;
    } else if (distance <= RISK_DIST){
      return REGIME_RISK;
    } 
  }  
}
