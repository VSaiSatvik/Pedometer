# Pedometer

Overview

This project utilizes an MPU6050 accelerometer and gyroscope sensor to create a simple and efficient step counter. The step counter is designed to be sensitive and accurate, making it ideal for various applications, including fitness tracking and motion detection.

Components

Arduino Board: The microcontroller to run the code.
MPU6050: Accelerometer and gyroscope sensor to detect motion and count steps.
Breadboard and Jumper Wires: For connecting the components.
Features

Step Counting: Counts the number of steps taken by the user and displays the count on the serial monitor.
Real-Time Monitoring: Continuously monitors and updates the step count.
Usage

Setup: Connect the MPU6050 sensor to the Arduino as described in the circuit diagram. Ensure the MPU6050 is calibrated and properly connected to the Arduino.
Upload Code: Upload the provided Arduino code to the Arduino board.
Monitor Steps: Open the serial monitor to view the step count in real-time.
Circuit Diagram

MPU6050:
VCC to 3.3V or 5V on Arduino
GND to GND on Arduino
SCL to A5 on Arduino
SDA to A4 on Arduino
