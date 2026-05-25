#include <Modulino.h>

ModulinoVibro vibro;

void setup() {
  Serial.begin(9600);
  Modulino.begin();
  vibro.begin();
  
  Serial.println("Haptic Pattern Demo");
}

void loop() {
  // Pattern 1: Quick double pulse
  Serial.println("Double Pulse");
  vibro.on(100, INTENSE);
  delay(150);
  vibro.on(100, INTENSE);
  delay(1000);
  
  // Pattern 2: Escalating intensity
  Serial.println("Escalating");
  vibro.on(200, GENTLE);
  delay(250);
  vibro.on(200, MODERATE);
  delay(250);
  vibro.on(200, POWERFUL);
  delay(1000);
  
  // Pattern 3: Long gentle pulse
  Serial.println("Gentle Wave");
  vibro.on(500, GENTLE);
  delay(1000);
  
  // Pattern 4: Alert pattern
  Serial.println("Alert");
  for (int i = 0; i < 3; i++) {
    vibro.on(150, MAXIMUM);
    delay(200);
  }
  delay(2000);
}