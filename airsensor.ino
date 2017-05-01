
// ----- Include for Cayenne
#include "CayenneDefines.h"
#include "BlynkSimpleEsp8266.h"
#include "CayenneWiFiClient.h"
// -------------------------

#include "AirSensors.h"

// ------------------ 
// -- Display Oled --
// ------------------
#include<stdlib.h>
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library
#define PIN_RESET 255
#define DC_JUMPER 0
MicroOLED display(PIN_RESET, DC_JUMPER);
byte stepSize = 2;
char test[20];

// ------------------ 
// -- Cayenne Send Data --
// ------------------
#define CAYENNE_DEBUG         // Uncomment to show debug messages
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "mbufsz0tja";
// Your network name and password.
char ssid[] = "GlobuleVertBiot";
char password[] = "Valentin&Camille?";



AirSensors airSensors(2);
void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  airSensors.initialize();
  // Init Oled
  display.begin();
  display.clear(ALL);
  display.clear(PAGE);
  display.display();
  // Init Cayenne 
  Cayenne.begin(token, ssid, password);

  
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
 
  ;
  airSensors.readSensorValues();
   Serial.print("Humidity :");
   Serial.print(airSensors.getHumidity());
   Serial.print(" Temperature :");
   Serial.println(airSensors.getTemperature());

 display.setFontType(0);
  display.setCursor(0, 0);
  display.print("T=");
  display.print(dtostrf(airSensors.getTemperature(),5,2,test));
  display.println("c");
  display.print("H=");
  display.print(dtostrf(airSensors.getHumidity(),5,2,test));
  display.println("%");
  display.display(); 
   Cayenne.run();
  
}
CAYENNE_OUT(V2){
   Cayenne.virtualWrite(V2, airSensors.getHumidity());
}
CAYENNE_OUT(V1)
{
 Cayenne.celsiusWrite(V1, airSensors.getTemperature());
}

