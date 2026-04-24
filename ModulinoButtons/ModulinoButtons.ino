#include <Modulino.h>

// Create object instance
ModulinoButtons buttons;

void setup() {
  Serial.begin(9600);
  Modulino.begin();
  buttons.begin();
  
  // Function to control the LEDs on top of each button
  buttons.setLeds(false, false, false);
}

void loop() {
  // Request new data from the Modulino Buttons
  if (buttons.update()) {
    // Check if any button has been pressed
    if (buttons.isPressed(0)) {
      Serial.println("Button A pressed!");
      buttons.setLeds(true, false, false);
    } else if (buttons.isPressed(1)) {
      Serial.println("Button B pressed!");
      buttons.setLeds(false, true, false);
    } else if (buttons.isPressed(2)) {
      Serial.println("Button C pressed!");
      buttons.setLeds(false, false, true);
    }
    buttons.setLeds(false, false, false);
  }
  delay(500);
}