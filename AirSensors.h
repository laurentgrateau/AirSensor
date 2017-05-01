/*
  AirSensors - Library for aggregating  code.
  Created by Laurent Grateau, May 1, 2017.
  GPL.
*/
#ifndef AirSensors_H
#define AirSensors_H

#include "Arduino.h"
//#include "DHT.h"

 
class AirSensors{

  public:
    AirSensors(int pindht);
    void readSensorValues();
    float getHumidity();
    float getTemperature();
    void initialize();
  private:
    int _pindht;
    float _humitidty;
    float _temperature;
};

#endif
