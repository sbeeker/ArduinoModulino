#include "Modulino.h"

ModulinoDistance distance;

// Distance thresholds in cm
const int DANGER_ZONE = 10;    // Less than 10cm
const int WARNING_ZONE = 30;   // 10-30cm
const int CAUTION_ZONE = 50;   // 30-50cm
const int SAFE_ZONE = 100;     // 50-100cm

void setup() {
  Serial.begin(115200);
  Modulino.begin();
  distance.begin();
  
  Serial.println("Parking Sensor Active");
  Serial.println("===================");
}

void loop() {
  if (distance.available()) {
    int measure = distance.get();
    
    // Determine zone and provide feedback
    if (measure < DANGER_ZONE) {
      Serial.print("🔴 STOP! Distance: ");
      Serial.print(measure);
      Serial.println(" cm - TOO CLOSE!");
    }
    else if (measure < WARNING_ZONE) {
      Serial.print("🟠 WARNING - Distance: ");
      Serial.print(measure);
      Serial.println(" cm - Very close");
    }
    else if (measure < CAUTION_ZONE) {
      Serial.print("🟡 CAUTION - Distance: ");
      Serial.print(measure);
      Serial.println(" cm - Getting close");
    }
    else if (measure < SAFE_ZONE) {
      Serial.print("🟢 SAFE - Distance: ");
      Serial.print(measure);
      Serial.println(" cm - Good distance");
    }
    else {
      Serial.print("✓ Clear - Distance: ");
      Serial.print(measure);
      Serial.println(" cm");
    }
  }
  
  delay(1000);  // Update 10 times per second
}