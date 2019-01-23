Servo myservo;  // create servo object to control a servo
//boolean upwards = true;
//int pos_start = 0;    // variable to store the servo position
//int pos_last = 20;
//int pos = 0;

void moveServo(int side){
    checkButton();
    myservo.write(side);
    delay(400);
}
