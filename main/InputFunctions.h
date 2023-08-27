int chooseSeconds(int color, int maxSeconds = 9){
  int choice = 0;

  while (true){
    delay(80);
    digitalWrite(color, LOW);
    delay(80);
    digitalWrite(color, HIGH);

    setDisplay(choice);

    if (digitalRead(LESS_BUTTON) == HIGH){
      if (choice <= 0){
        choice = 0;
      }
      else {
        choice--;
      }
    }
    else if (digitalRead(MORE_BUTTON) == HIGH){
      if (choice >= maxSeconds){
        choice = maxSeconds;
      }
      else{
        choice++;
      }
    }
    else if (digitalRead(OK_BUTTON) == HIGH) {
      digitalWrite(color, LOW);
      return choice;
    }
  }
}

int chooseState(){
  int choice = 0;

  while (true){
    delay(150);
    digitalWrite(choice, HIGH);
    setDisplay(choice + 1);

    if (digitalRead(LESS_BUTTON) == HIGH){
      if (choice <= 0){
        choice = 0;
      }
      else{
        digitalWrite(choice, LOW);
        choice--;
      }
    }
    else if (digitalRead(MORE_BUTTON) == HIGH){
      if (choice >= 2){
        choice = 2;
      }
      else {
        digitalWrite(choice, LOW);
        choice++;
      }
    }
    else if (digitalRead(OK_BUTTON) == HIGH) {
      digitalWrite(choice, LOW);
      return choice;
    }
  }
}
