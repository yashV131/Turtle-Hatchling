#include <ESP32Servo.h>

// --------- L298N pins ----------
#define IN1 26
#define IN2 27
#define IN3 14
#define IN4 12
#define ENA 25
#define ENB 33

// --------- Servos ----------
Servo servo1;
Servo servo2;

#define SERVO1_PIN 18
#define SERVO2_PIN 13

// PWM setup for motors
const int pwmFreq = 5000;
const int pwmResolution = 8;
const int pwmChannelA = 0;
const int pwmChannelB = 1;

void setup() {
  // Motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // PWM setup for ESP32
  ledcSetup(pwmChannelA, pwmFreq, pwmResolution);
  ledcSetup(pwmChannelB, pwmFreq, pwmResolution);

  ledcAttachPin(ENA, pwmChannelA);
  ledcAttachPin(ENB, pwmChannelB);

  // Servos
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);

  // Initial positions
  servo1.write(90);
  servo2.write(90);
}

// --------- Motor control functions ----------
void forward(int speedVal) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  ledcWrite(pwmChannelA, speedVal);
  ledcWrite(pwmChannelB, speedVal);
}

void backward(int speedVal) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  ledcWrite(pwmChannelA, speedVal);
  ledcWrite(pwmChannelB, speedVal);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  ledcWrite(pwmChannelA, 0);
  ledcWrite(pwmChannelB, 0);
}

void loop() {

  // -------- MOTORS FORWARD --------
  forward(200);
  delay(2000);

  stopMotors();
  delay(1000);

  // -------- MOTORS BACKWARD --------
  backward(200);
  delay(2000);

  stopMotors();
  delay(1000);

  // -------- SERVOS MOVE --------
  servo1.write(0);
  servo2.write(0);
  delay(1000);

  servo1.write(90);
  servo2.write(90);
  delay(1000);

  servo1.write(180);
  servo2.write(180);
  delay(1000);

  servo1.write(90);
  servo2.write(90);
  delay(2000);
}