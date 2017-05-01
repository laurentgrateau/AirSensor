
#include "Arduino.h"
#include "AirSensors.h"
#include <DHT.h>

#define DHTPIN D4  
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

AirSensors::AirSensors(int pindht){
  _pindht = pindht;
  
}


void AirSensors::initialize(){
    dht.begin();
}
void AirSensors::readSensorValues(){
  _temperature = dht.readTemperature();
  _humitidty = dht.readHumidity(); 
  Serial.print("Debug Humidity :");
   Serial.print(_temperature);
   Serial.print(_humitidty);
}

float AirSensors::getHumidity(){
  return _humitidty;
}

float AirSensors::getTemperature(){
  return _temperature;
}
