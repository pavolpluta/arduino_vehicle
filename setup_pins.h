void setup_pins(){
  myservo.attach(PIN_SERVO);
  Serial.begin (9600);

  pinMode(PIN_SENSOR_TRIGGER, OUTPUT);
  pinMode(PIN_SENSOR_ECHO, INPUT);

  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED, OUTPUT);

  pinMode(R_MOTOR_PIN, OUTPUT);
  pinMode(R_MOTOR_PIN_DIR, OUTPUT);
  pinMode(L_MOTOR_PIN, OUTPUT);
  pinMode(L_MOTOR_PIN_DIR, OUTPUT);


  //SET DEFAULT STATE
  digitalWrite(R_MOTOR_PIN_DIR, FORWARD_DIR);
  digitalWrite(L_MOTOR_PIN_DIR, FORWARD_DIR); 
  analogWrite(R_MOTOR_PIN, LOW);
  analogWrite(L_MOTOR_PIN, LOW);  
}
