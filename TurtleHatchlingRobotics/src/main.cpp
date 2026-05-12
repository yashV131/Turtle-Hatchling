#include <Arduino.h>
#include <TurtleReceiver.h>

#include "arms.h"
#include "wheels.h"
#include "latch.h"

// -------- CONTROLLER ----------
NetController controller;

// // --------- Setup ----------
void setup() {
  Serial.begin(115200);

  controller.controllerSetup();

  latchSetup();
  wheelsSetup();
  armsSetup();
}

// // --------- LOOP ----------
void loop() {
  latchLoop(controller); 
  wheelsLoop(controller);
  armsLoop(controller);
}
