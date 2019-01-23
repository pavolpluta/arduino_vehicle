#include "config.h"
#include <Servo.h>
#include "check_button.h"
#include "my_servo.h"
#include "movement_management.h"
#include "my_sensor.h"
#include "regimes.h"
#include "setup_pins.h"
#include "idle_functionality.h"
#include "moving_functionality.h"

void setup() {  
  setup_pins(); 
}

void loop() {

  if(checkButton() == STATE_MOVING){
    movingFunctionality();
  } else if (checkButton() == STATE_IDLE) {
    idleFunctionality();
  }
}
