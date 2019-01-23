void processRegimes(int regime){
  switch (regime){
    case REGIME_FAST:
      moveForward(FAST);
      break;
    case REGIME_MEDIUM:
      moveForward(MEDIUM_SPEED);
      break;
    case REGIME_SLOW:
      moveForward(SLOW);
      break;
    case REGIME_RISK:
      manageRisk();
      break;      
  }
}
