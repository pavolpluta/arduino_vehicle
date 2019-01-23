int checkButton() {
 int readButtonPin = digitalRead(PIN_BUTTON);

  if (readButtonPin != lastButtonState){
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (readButtonPin != buttonState){
       buttonState = readButtonPin;
        
      if (buttonState == HIGH){
        robotModeIndicator = !robotModeIndicator;
      }
    }
  } 

   digitalWrite(PIN_LED,robotModeIndicator);
   lastButtonState = readButtonPin;

   return robotModeIndicator;    
}
