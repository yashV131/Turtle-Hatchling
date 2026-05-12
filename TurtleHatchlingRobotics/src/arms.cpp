#include <Arduino.h>
#include <TurtleReceiver.h>
#include <ESP32Servo.h>

// --------- Servo ----------
Servo servo1;
Servo servo2;
#define SERVO1_PIN 18
 #define SERVO2_PIN 19

int angle = 0;
int increment = 25;
bool prevLt = false;
bool prevRt = false;

// --------- Setup ----------
void armsSetup() {
  // Servo
  servo1.attach(SERVO1_PIN);
  
  servo1.write(angle);
  
  servo2.attach(SERVO2_PIN);
   servo2.write(angle);
}

// --------- LOOP ----------

void armsLoop(NetController &controller) {

  bool lt = controller.getLt();
  bool rt = controller.getRt();

  // LEFT button (increase)
  if (lt && !prevLt) {

    angle += increment;
    if(angle>180) angle = 180;
    servo1.write(angle);
    servo2.write(angle);

    Serial.println("INCREASE: " + String(angle));
  }

  // RIGHT button (decrease)
  if (rt && !prevRt) {
    angle -= increment;
    if(angle < 0) angle = 0;
    servo1.write(angle);
    servo2.write(angle);

    Serial.println("DECREASE: " + String(angle));
  }

  prevLt = lt;
  prevRt = rt;
}