
#include <Arduino.h>

void setMotor(int in1, int in2, int dir) {
  if (dir > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } 
  else if (dir < 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } 
  else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}