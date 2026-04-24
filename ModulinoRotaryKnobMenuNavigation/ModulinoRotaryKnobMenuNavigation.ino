#include <Modulino.h>

ModulinoKnob knob;

// Menu configuration
const int MENU_ITEMS = 5;
String menuOptions[] = {"Settings", "Display", "Audio", "Network", "Exit"};
int currentSelection = 0;
int lastPosition = 0;
bool lastButtonState = false;

void setup() {
  Serial.begin(9600);
  Modulino.begin();
  knob.begin();
  
  // Set initial position to 0
  knob.set(0);
  lastPosition = 0;
  
  displayMenu();
}

void displayMenu() {
  Serial.println("\n======= MENU =======");
  for (int i = 0; i < MENU_ITEMS; i++) {
    if (i == currentSelection) {
      Serial.print("> ");  // Selection indicator
    } else {
      Serial.print("  ");
    }
    Serial.println(menuOptions[i]);
  }
  Serial.println("==================");
  Serial.println("Rotate to navigate, press to select");
}

void selectMenuItem() {
  Serial.print("\n✓ Selected: ");
  Serial.println(menuOptions[currentSelection]);
  
  // Handle selection
  switch(currentSelection) {
    case 0:
      Serial.println("Opening Settings...");
      break;
    case 1:
      Serial.println("Opening Display options...");
      break;
    case 2:
      Serial.println("Opening Audio settings...");
      break;
    case 3:
      Serial.println("Opening Network configuration...");
      break;
    case 4:
      Serial.println("Exiting menu...");
      break;
  }
  
  delay(1000);
  displayMenu();
}

void loop() {
  int currentPosition = knob.get();
  bool buttonPressed = knob.isPressed();
  
  // Check for rotation
  int rotation = currentPosition - lastPosition;
  
  if (rotation != 0) {
    // Update selection based on rotation direction
    if (rotation > 0) {
      currentSelection++;
      if (currentSelection >= MENU_ITEMS) {
        currentSelection = 0;  // Wrap around
      }
    } else {
      currentSelection--;
      if (currentSelection < 0) {
        currentSelection = MENU_ITEMS - 1;  // Wrap around
      }
    }
    
    lastPosition = currentPosition;
    displayMenu();
  }
  
  // Check for button press (on release to avoid multiple triggers)
  if (!buttonPressed && lastButtonState) {
    selectMenuItem();
  }
  
  lastButtonState = buttonPressed;
  
  delay(50);  // Small delay for debouncing
}