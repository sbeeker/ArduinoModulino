#include <Modulino.h>

// Create object instance
ModulinoThermo thermo;

// Global Variables
float celsius = 0;
float humidity = 0;

void setup(){
  // Initialization of the serial port, modulino object and thermo one
  Serial.begin(115200);
  Modulino.begin();
  thermo.begin();
}

void loop(){
  celsius = thermo.getTemperature();
  humidity = thermo.getHumidity();

  Serial.print("Temperature (C) is: ");
  Serial.println(celsius);

  Serial.print("Humidity (rH) is: ");
  Serial.println(humidity);

  delay(1000);
}