#include "Wire.h"
#include <MPU6050_light.h>

MPU6050 mpu(Wire);
unsigned long timer = 0;

// Variables for step counting
int stepCount = 0;
bool stepDetected = false;
float stepThreshold = 1.0;  // Lower the threshold for more sensitivity
float lowerThreshold = 0.5; // Lower threshold to detect step end

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status != 0) { } // stop everything if could not connect to MPU6050
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");
}

void loop() {
  mpu.update();
  
  if((millis() - timer) > 10) { // check data every 10ms
    float ax = mpu.getAccX();
    float ay = mpu.getAccY();
    float az = mpu.getAccZ();

    // Calculate magnitude of the acceleration vector
    float magnitude = sqrt(ax * ax + ay * ay + az * az);

    // Step detection based on peak detection algorithm
    if (magnitude > stepThreshold && !stepDetected) {
      stepDetected = true;
      stepCount++;
    } else if (magnitude < lowerThreshold && stepDetected) {
      stepDetected = false;
    }

    // Print step count to serial monitor
    Serial.print("Steps: ");
    Serial.println(stepCount);

    timer = millis();
  }
}
