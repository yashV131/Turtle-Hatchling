#include <Arduino.h>
#include <TurtleReceiver.h>
#include "motorutils.h"
// --------- L298N pins ----------
#define IN1 26   // RIGHT motor
#define IN2 27
#define IN3 14   // LEFT motor
#define IN4 12
#define ENB 25
float deadzone = 0.15;

// --------- Motor ----------
// void setMotor(int in1, int in2, int dir) {
//   if (dir > 0) {
//     digitalWrite(in1, HIGH);
//     digitalWrite(in2, LOW);
//   } 
//   else if (dir < 0) {
//     digitalWrite(in1, LOW);
//     digitalWrite(in2, HIGH);
//   } 
//   else {
//     digitalWrite(in1, LOW);
//     digitalWrite(in2, LOW);
//   }
// }

// --------- Setup ----------
void wheelsSetup() {
    pinMode(ENB, OUTPUT);
  digitalWrite(ENB, LOW); // motor disabled at start


  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // FORCE STOP on boot/reset
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}

// --------- Loop ----------
void wheelsLoop(NetController &controller) {

  float x = controller.getJoy2X(); // left/right
  float y = controller.getJoy2Y(); // forward/back

  // deadzone
  if (abs(x) < deadzone) x = 0;
  if (abs(y) < deadzone) y = 0;

  // --------- STOP ----------
  if (x == 0 && y == 0) {
    digitalWrite(ENB, LOW);
    setMotor(IN1, IN2, 0);
    setMotor(IN3, IN4, 0);
    return;
  }
  else{
    digitalWrite(ENB, HIGH);
  }

  // --------- FORWARD / BACKWARD ----------
  if (abs(y) > abs(x)) {

    int dir = (y > 0) ? 1 : -1;

    setMotor(IN1, IN2, dir);
    setMotor(IN3, IN4, dir);
  }

  // --------- SIDEWAYS TURN ----------
  else {

    if (x > 0) {
      // RIGHT turn → left motor forward
      setMotor(IN1, IN2, 0);
      setMotor(IN3, IN4, 1);
    } 
    else {
      // LEFT turn → right motor forward
      setMotor(IN1, IN2, 1);
      setMotor(IN3, IN4, 0);
    }
  }
}