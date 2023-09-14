char chooseMore(char choice, char max){
  if (choice >= max){
    choice = max;
  }
  else {
    choice++;
  }
  return choice;
}

char chooseLess(char choice, char min = 0){
  if (choice <= min){
    choice = min;
  }
  else{
    choice--;
  }
  return choice;
}

char selectTimeInSeconds(char color, char maxSeconds = 9){
  char choice = 0;

  while (true){
    blink(color, 80);
    setDisplay(choice);

    if (digitalRead(LESS_BUTTON) == HIGH){
      choice = chooseLess(choice);
    }
    else if (digitalRead(MORE_BUTTON) == HIGH){
      choice = chooseMore(choice, maxSeconds);
    }
    else if (digitalRead(OK_BUTTON) == HIGH) {
      return choice;
    }
  }
}

char selectState(){
  char choice = 0;

  while (true){
    digitalWrite(choice, HIGH);
    delay(150);
    setDisplay(choice + 1);
    digitalWrite(choice, LOW);

    if (digitalRead(LESS_BUTTON) == HIGH){
      choice = chooseLess(choice);
    }
    else if (digitalRead(MORE_BUTTON) == HIGH){
      choice = chooseMore(choice, 2);
    }
    else if (digitalRead(OK_BUTTON) == HIGH) {
      digitalWrite(choice, LOW);
      return choice;
    }
  }
}
