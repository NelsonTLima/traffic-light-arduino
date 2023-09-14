/*
  Triffic Light

  Chooses for how long each led will be lit and then, it will function just like
  a traffic light.

  by Nelson Lima
*/
#pragma once
#include "Dependencies.h"

void setup() {
  // INPUT PINS:
  // 0-2 -> red, yellow and green leds.
  // 3-6 -> CD4511 -> DISPLAY.
  for (char pin = 0; pin < 7; pin ++){
    pinMode(pin, OUTPUT);
  }
  // OUTPUT PINS: 7-9 -> BUTTONS.
  for (char pin = 0; pin < 3; pin ++){
    pinMode(LESS_BUTTON + pin, INPUT);
  }
};

void loop() {
  //Display only shows 0 - 9.
  //Yellow light must not last more than green light.
  char state, secondsYellow, secondsGreen, secondsRed, maxYellow = 4, maxDisplaySeconds = 9;

  // Get User's input.
  secondsYellow = selectTimeInSeconds(YELLOW, maxYellow);
  secondsGreen = selectTimeInSeconds(GREEN, maxDisplaySeconds - secondsYellow);
  secondsRed = selectTimeInSeconds(RED);
  state = selectState();

  //Start Traffic light.
  Timer timer;
  Light light(state, secondsRed, secondsYellow, secondsGreen);
  light.start(&timer);
};
