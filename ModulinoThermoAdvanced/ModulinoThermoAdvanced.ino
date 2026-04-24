#include <Modulino.h>

ModulinoThermo thermo;
const float TEMP_THRESHOLD = 25.0;  // Alert above 25°C
const float HUMIDITY_THRESHOLD = 70.0;  // Alert above 70% humidity

void setup(){
  Serial.begin(115200);
  Modulino.begin();
  thermo.begin();
  
  Serial.println("Environmental Monitor Started");
}

void loop(){
  float temp = thermo.getTemperature();
  float hum = thermo.getHumidity();
  
  // Check temperature threshold
  if(temp > TEMP_THRESHOLD) {
    Serial.print("⚠️ HIGH TEMPERATURE: ");
    Serial.print(temp);
    Serial.println("°C");
  }
  
  // Check humidity threshold
  if(hum > HUMIDITY_THRESHOLD) {
    Serial.print("⚠️ HIGH HUMIDITY: ");
    Serial.print(hum);
    Serial.println("%");
  }
  
  // Normal readings
  if(temp <= TEMP_THRESHOLD && hum <= HUMIDITY_THRESHOLD) {
    Serial.print("Normal - Temp: ");
    Serial.print(temp);
    Serial.print("°C, Humidity: ");
    Serial.print(hum);
    Serial.println("%");
  }
  
  delay(5000);  // Check every 5 seconds
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
