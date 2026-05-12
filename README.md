# Turtle-Hatchling Robotics

## Overview

Turtle-Hatchling is an ESP32-based robotics project designed for a robot that collects balls and drops them into a mothership. The robot is controlled wirelessly using a network controller and features motorized wheels for movement, servo-controlled arms for ball collection, and a latch mechanism for releasing balls into the mothership.

## Features

- **Wireless Control**: Uses TurtleReceiver library for network-based control via controller inputs.
- **Movement**: Differential drive system with two motors controlled by joystick input.
- **Ball Collection**: Servo-operated arms that can be adjusted to collect balls.
- **Latch Mechanism**: Servo-controlled latch to open and close for dropping balls into the mothership.
- **ESP32 Platform**: Built on ESP32 microcontroller with Arduino framework.

## Hardware Requirements

- ESP32 development board (upesy_wroom)
- L298N motor driver module
- Two DC motors for wheels
- Four servo motors (two for arms, two for latch)
- TurtleReceiver-compatible controller for wireless input
- Power supply suitable for motors and ESP32

### Pin Configuration

- **Servos**:
  - Arms: Servo1 (GPIO 18), Servo2 (GPIO 19)
  - Latch: Servo3 (GPIO 22), Servo4 (GPIO 23)
- **Motors**:
  - Right Motor: IN1 (GPIO 26), IN2 (GPIO 27)
  - Left Motor: IN3 (GPIO 14), IN4 (GPIO 12)
  - Enable: ENB (GPIO 25)

## Software Setup

### Prerequisites

- [PlatformIO](https://platformio.org/) installed
- ESP32 board support in PlatformIO

### Installation

1. Clone the repository:
   ```
   git clone https://github.com/yashV131/Turtle-Hatchling.git
   cd Turtle-Hatchling/TurtleHatchlingRobotics
   ```

2. Open the project in PlatformIO:
   ```
   platformio init --board upesy_wroom
   ```

3. Install dependencies:
   ```
   platformio lib install
   ```

4. Build the project:
   ```
   platformio run
   ```

5. Upload to ESP32:
   ```
   platformio run --target upload
   ```

### Usage

1. Power on the robot and ensure the controller is connected.
2. Use the controller's joystick for movement:
   - Left joystick: Controls robot movement (forward/backward, left/right)
3. Use buttons to control arms and latch:
   - Left/Right buttons: Adjust arm angles for ball collection
   - B button: Open latch to drop balls
   - X button: Close latch

## Project Structure

- `src/`: Source code files
  - `main.cpp`: Main program loop and setup
  - `arms.cpp/h`: Arm control with servos
  - `wheels.cpp/h`: Wheel motor control
  - `latch.cpp/h`: Latch mechanism control
  - `motorutils.cpp/h`: Motor utility functions
- `lib/TurtleReceiver/`: Custom library for network controller
- `include/`: Header files
- `platformio.ini`: PlatformIO configuration

## Dependencies

- [ESP32Servo](https://github.com/madhephaestus/ESP32Servo): Servo control library
- TurtleReceiver: Custom network controller library

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request.
