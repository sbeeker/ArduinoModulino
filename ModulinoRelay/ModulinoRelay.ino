#include <Modulino.h>

ModulinoLatchRelay relay;

void setup() {
  Serial.begin(9600);
  Modulino.begin();
  relay.begin();
  
  Serial.println("Relay Control Started");
}

void loop() {
  // Turn relay on
  Serial.println("Relay ON");
  relay.set();
  delay(2000);
  
  // Turn relay off
  Serial.println("Relay OFF");
  relay.reset();
  delay(2000);
}