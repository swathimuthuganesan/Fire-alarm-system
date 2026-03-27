#include <Arduino.h>

// Pin definitions
#define FIRE_SENSOR_PIN 3   // Fire alarm sensor connected to D3
#define BUZZER_PIN 5        // Buzzer connected to D5

void setup() {
  pinMode(FIRE_SENSOR_PIN, INPUT);   // Set fire sensor as input
  pinMode(BUZZER_PIN, OUTPUT);        // Set buzzer as output

  digitalWrite(BUZZER_PIN, LOW);      // Buzzer OFF initially
}

void loop() {
  int fireDetected = digitalRead(FIRE_SENSOR_PIN);

  // Most fire sensors are ACTIVE LOW
  if (fireDetected == LOW) {
    digitalWrite(BUZZER_PIN, HIGH);   // Fire detected → buzzer ON
  } else {
    digitalWrite(BUZZER_PIN, LOW);    // No fire → buzzer OFF
  }
}
