class Light {
  public:
  int currentState, secondsRed, secondsYellow, secondsGreen;
  int seconds[3];

  Light(
      int currentState = YELLOW,
      int secondsRed = 9,
      int secondsYellow = 2,
      int secondsGreen = 7
      )
  {
    this -> currentState = currentState;
    this -> seconds[0] = secondsGreen + secondsYellow;
    this -> seconds[1] = secondsYellow;
    this -> seconds[2] = secondsRed;
  }

  void switchStage(){
    if (currentState < RED){
      currentState++;
    }
    else {
      currentState = GREEN;
    }
  }

  void start(Timer *timer) {
    timer -> set(seconds[currentState]);

    while (true) {

      setLeds(currentState);
      setDisplay(timer->secondsLeft);
      timer->run();

      if (timer->secondsLeft < 0 || (currentState == GREEN && timer->secondsLeft <= seconds[YELLOW])){
        this -> switchStage();
        timer -> set(seconds[currentState]);
      }
    }
  }
};
