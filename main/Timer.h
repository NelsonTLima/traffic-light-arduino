class Timer {
  public:
    int secondsLeft;

    Timer() {
      this -> secondsLeft = 0;
    }

    void set(int seconds) {
      this -> secondsLeft = seconds;
    }

    void run(){
      delay(1000);
      secondsLeft --;
    }
};
