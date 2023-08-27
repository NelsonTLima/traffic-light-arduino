/*
  Triffic Light

  Chooses for how long each led will be lit and then, it will function just like
  a traffic light.

  by Nelson Lima
*/

#include "Dependencies.h"

void setup() {
  // INPUT PINS:
  // 0-2 -> red, yellow and green leds.
  // 3-6 -> CD4511 -> DISPLAY.
  for (int pin = 0; pin < 7; pin ++){
    pinMode(pin, OUTPUT);
  }
  // OUTPUT PINS: 7-9 -> BUTTONS.
  for (int pin = 0; pin < 3; pin ++){
    pinMode(LESS_BUTTON + pin, INPUT);
  }
};

void loop() {
  //Display only shows 0 - 9. 
  //Yellow light must not last more than green light.
  int state, secondsYellow, secondsGreen, secondsRed, maxYellow = 4, maxDisplaySeconds = 9;

  // Get User's input.
  secondsYellow = chooseSeconds(YELLOW, maxYellow);
  secondsGreen = chooseSeconds(GREEN, maxDisplaySeconds - secondsYellow);
  secondsRed = chooseSeconds(RED);
  state = chooseState();

  //Start Traffic light.
  Timer timer;
  Light light(state, secondsRed, secondsYellow, secondsGreen);
  light.start(&timer);
};
