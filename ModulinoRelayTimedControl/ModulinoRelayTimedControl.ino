#include <Modulino.h>

ModulinoLatchRelay relay;

// Timing configuration
const unsigned long ON_DURATION = 5000;   // 5 seconds on
const unsigned long OFF_DURATION = 10000; // 10 seconds off

// State tracking
unsigned long lastChangeTime = 0;
bool relayState = false;

void setup() {
  Serial.begin(9600);
  Modulino.begin();
  relay.begin();
  
  Serial.println("Timed Relay Control System");
  Serial.println("ON: 5 seconds, OFF: 10 seconds");
  
  // Start with relay off
  relay.reset();
  lastChangeTime = millis();
}

void loop() {
  unsigned long currentTime = millis();
  unsigned long elapsed = currentTime - lastChangeTime;
  
  // Check if it's time to change state
  if (relayState) {
    // Relay is ON, check if on-duration has elapsed
    if (elapsed >= ON_DURATION) {
      relay.reset();
      relayState = false;
      lastChangeTime = currentTime;
      
      Serial.println("=== Relay switched OFF ===");
      Serial.print("Next cycle in: ");
      Serial.print(OFF_DURATION / 1000);
      Serial.println(" seconds");
    }
  } else {
    // Relay is OFF, check if off-duration has elapsed
    if (elapsed >= OFF_DURATION) {
      relay.set();
      relayState = true;
      lastChangeTime = currentTime;
      
      Serial.println("=== Relay switched ON ===");
      Serial.print("Active for: ");
      Serial.print(ON_DURATION / 1000);
      Serial.println(" seconds");
    }
  }
  
  // Display status every second
  static unsigned long lastStatusTime = 0;
  if (currentTime - lastStatusTime >= 1000) {
    lastStatusTime = currentTime;
    
    Serial.print("Status: ");
    Serial.print(relayState ? "ON " : "OFF");
    Serial.print(" | Time remaining: ");
    
    if (relayState) {
      Serial.print((ON_DURATION - elapsed) / 1000);
    } else {
      Serial.print((OFF_DURATION - elapsed) / 1000);
    }
    Serial.println(" s");
  }
  
  delay(100);
}