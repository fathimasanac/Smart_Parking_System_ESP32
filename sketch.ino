#include <Arduino.h>

// Ultrasonic pins
#define TRIG_PIN 5
#define ECHO_PIN 18

// LED pins
#define GREEN_LED 2
#define RED_LED 4

long duration;
int distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo time
  duration = pulseIn(ECHO_PIN, HIGH);

  // Convert to distance (cm)
  distance = duration * 0.034 / 2;

  // Parking logic (threshold = 150 cm)
  if (distance < 150) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    Serial.println("🚗 Slot Occupied");
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    Serial.println("🅿️ Slot Available");
  }

  delay(500);
}

