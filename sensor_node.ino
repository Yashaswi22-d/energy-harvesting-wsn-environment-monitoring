#include <Arduino.h>
#include <Wire.h>

// -------- PIN DEFINITIONS --------
#define TEMP_PIN 34
#define HUMID_PIN 35
#define SOLAR_VOLT_PIN 32

// -------- SETUP --------
void setup() {
  Serial.begin(9600);
  analogReadResolution(12);
  Serial.println("Energy Harvesting WSN - Sensor Node Initialized");
}

// -------- LOOP --------
void loop() {

  // Simulated environmental data
  float temperature = random(200, 350) / 10.0;  // °C
  float humidity = random(400, 800) / 10.0;     // %
  
  // Solar energy voltage
  int solarRaw = analogRead(SOLAR_VOLT_PIN);
  float solarVoltage = (solarRaw / 4095.0) * 3.3 * 2;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Solar Voltage: ");
  Serial.print(solarVoltage);
  Serial.println(" V");

  // Energy-aware operation
  if (solarVoltage < 2.5) {
    Serial.println("⚠️ Low Energy Mode Activated");
    delay(10000);  // sleep longer
  } else {
    Serial.println("Normal Operation Mode");
    delay(3000);
  }
}
