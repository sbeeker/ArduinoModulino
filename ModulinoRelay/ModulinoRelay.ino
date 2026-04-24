#include <Modulino.h>

ModulinoRelay relay;

void setup() {
  Serial.begin(9600);
  Modulino.begin();
  relay.begin();
  
  Serial.println("Relay Control Started");
}

void loop() {
  // Turn relay on
  Serial.println("Relay ON");
  relay.on();
  delay(2000);
  
  // Turn relay off
  Serial.println("Relay OFF");
  relay.off();
  delay(2000);
}