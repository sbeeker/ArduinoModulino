#include <Modulino.h>

ModulinoPixels leds;

// Color definitions for rainbow
const int NUM_LEDS = 8;
int colors[][3] = {
  {255, 0, 0},     // Red
  {255, 127, 0},   // Orange
  {255, 255, 0},   // Yellow
  {0, 255, 0},     // Green
  {0, 0, 255},     // Blue
  {75, 0, 130},    // Indigo
  {148, 0, 211},   // Violet
  {255, 0, 0}      // Back to Red
};

void setup() {
  Serial.begin(9600);
  Modulino.begin();
  leds.begin();
  
  Serial.println("Rainbow Animation Started");
}

void rainbowCycle() {
  static int offset = 0;
  
  for (int i = 0; i < NUM_LEDS; i++) {
    int colorIndex = (i + offset) % NUM_LEDS;
    
    // Custom color setting using RGB values
    // Since the library uses predefined colors, we'll use 
    // the closest match or cycle through available colors
    switch(colorIndex) {
      case 0:
      case 7:
        leds.set(i, RED, 50);
        break;
      case 1:
      case 2:
        leds.set(i, GREEN, 50);
        break;
      case 3:
      case 4:
        leds.set(i, BLUE, 50);
        break;
      case 5:
      case 6:
        leds.set(i, VIOLET, 50);
        break;
    }
  }
  
  leds.show();
  offset = (offset + 1) % NUM_LEDS;
}

void breathingEffect() {
  static int brightness = 0;
  static int direction = 1;
  
  // Update brightness
  brightness += direction * 5;
  
  if (brightness >= 100 || brightness <= 0) {
    direction = -direction;
  }
  
  // Set all LEDs to same color with varying brightness
  for (int i = 0; i < NUM_LEDS; i++) {
    leds.set(i, BLUE, brightness);
  }
  leds.show();
}

void chaseEffect() {
  static int position = 0;
  
  // Turn off all LEDs
  for (int i = 0; i < NUM_LEDS; i++) {
    leds.set(i, WHITE, 0);
  }
  
  // Light up current position and trailing LEDs
  leds.set(position, WHITE, 100);
  if (position > 0) {
    leds.set(position - 1, WHITE, 30);
  } else {
    leds.set(NUM_LEDS - 1, WHITE, 30);
  }
  
  leds.show();
  position = (position + 1) % NUM_LEDS;
}

void loop() {
  // Cycle through different effects
  for (int i = 0; i < 50; i++) {
    rainbowCycle();
    delay(100);
  }
  
  for (int i = 0; i < 100; i++) {
    breathingEffect();
    delay(30);
  }
  
  for (int i = 0; i < 30; i++) {
    chaseEffect();
    delay(80);
  }
}