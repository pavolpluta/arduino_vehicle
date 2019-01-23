void idleFunctionality(){
  int regime = processReadSensor(STATE_IDLE);  
  processRegimes(regime);
}
