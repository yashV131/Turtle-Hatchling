#include <Arduino.h>
#include <TurtleReceiver.h>
#include <ESP32Servo.h>

// --------- Servo ----------
Servo servo3;
Servo servo4;
#define SERVO1_PIN 22
 #define SERVO2_PIN 23

// --------- Setup ----------
void latchSetup() {
  // Servo
  servo3.attach(SERVO1_PIN);
  
  // servo3.write(0);
  
  servo4.attach(SERVO2_PIN);
  // servo4.write(0);
}

// --------- LOOP ----------
void latchLoop(NetController &controller) {
  // ===== SERVO CONTROL (SAFE) =====
  if (controller.getB()) {
    Serial.println("Open latch");
    servo3.write(90);
    servo4.write(90);
  }
  else if (controller.getX()) {
    Serial.println("Close latch");
    servo3.write(0);
    servo4.write(0);
  }

  // delay(20);
}