#include <Arduino.h>

// Simulated base station receiving data

void setup() {
  Serial.begin(9600);
  Serial.println("WSN Base Station Initialized");
}

void loop() {
  Serial.println("Receiving data from sensor nodes...");
  delay(5000);
}
