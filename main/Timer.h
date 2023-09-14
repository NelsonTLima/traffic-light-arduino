class Timer {
  public:
    char secondsLeft;

    Timer() {
      this -> secondsLeft = 0;
    }

    void set(char seconds) {
      this -> secondsLeft = seconds;
    }

    void run(){
      delay(1000);
      secondsLeft--;
    }
};
