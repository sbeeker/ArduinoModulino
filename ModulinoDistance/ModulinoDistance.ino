#include "Modulino.h"

// Create object instance
ModulinoDistance distance;

void setup() {
  Serial.begin(9600);

  // Initialize the Modulino system and distance sensor
  Modulino.begin();
  distance.begin();
}

void loop() {
  if (distance.available()) {
    int measure = distance.get();
    Serial.println(measure);
  }
  delay(10);
}