# RPM-monitoring-brushlessDC
This code is used to monitor and set the RPM of a brushed DC motor, using an optical encoder and Adafruit motorshield

# Motor and Encoder Control with Adafruit Motor Shield

This repository contains Arduino code that controls a DC motor using the Adafruit Motor Shield and reads encoder data to calculate RPM and frequency. The motor speed can be adjusted through serial input, and the encoder provides feedback for the motor's rotational position.

## Features

- Controls a DC motor with adjustable speed using the Adafruit Motor Shield.
- Reads encoder data to determine the motor's position.
- Calculates and outputs RPM and frequency at predefined intervals.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno)
- Adafruit Motor Shield
- DC motor
- Rotary encoder
- Wires and connectors

## Getting Started

### Prerequisites

- Arduino IDE
- Adafruit Motor Shield Library
- Encoder Library

### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/motor-encoder-control.git
   cd motor-encoder-control

2. Open the motor_encoder_control.ino file in the Arduino IDE.

3. Ensure the necessary libraries are installed:

    - Adafruit Motor Shield Library
   - Encoder Library


### Hardware Setup
1. Connect the DC motor to Motor 3 on the Adafruit Motor Shield.
2. Connect the encoder to the Arduino pins (adjust the pin numbers if necessary):
    - Encoder Channel A to pin 2
    - Encoder Channel B to pin 3
3. Stack the Adafruit Motor Shield on the Arduino board.
4. Connect the Arduino to your computer via USB.


### Usage
1. Upload the code to your Arduino board.
2. Open the Serial Monitor in the Arduino IDE.
3. Enter a speed value (0 to 255) in the Serial Monitor to adjust the motor speed.

### Code Overview
- Initialization: Sets up the motor shield, motor, and encoder, and initializes serial communication.
- Main Loop:
   - Runs the motor continuously at the specified speed.
   - Reads the encoder position.
   - Calculates and outputs RPM and frequency at predefined intervals.
   - Adjusts the motor speed based on serial input.

### Key Variables
- encoderPinA, encoderPinB: Pins connected to the encoder channels.
- encoderResolution: Encoder resolution (cycles per revolution).
- predefinedDuration: Duration in milliseconds for calculating RPM.
