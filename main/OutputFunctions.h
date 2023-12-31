void setDisplay(char second){
  for (char b = 0; b < 4; b++){
    bool bit = (second >> b) & 1;

    if (bit) {
      digitalWrite(START_CI + b, HIGH);
    }
    else {
      digitalWrite(START_CI + b, LOW);
    }
  }
};

void setLeds(char sign){
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);

  if (sign == GREEN) {
    digitalWrite(GREEN, HIGH);
  }
  else if (sign == YELLOW) {
    digitalWrite(YELLOW, HIGH);
  }
  else if (sign == RED){
    digitalWrite(RED, HIGH);
  }
}

void blink(char color, unsigned char miliseconds){
  delay(miliseconds);
  digitalWrite(color, HIGH);
  delay(miliseconds);
  digitalWrite(color, LOW);
}
