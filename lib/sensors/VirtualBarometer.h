#include <Arduino.h>
#include "VirtualSensor.h"


class VirtualBarometer : public VirtualSensor {
    public:
        void connect();             // method to connect to the sensor using BME280 library
        VirtualBarometer();         // constructor method

        float getTemperature();     // method to get temperature
        float getPressure();        // method to get pressure
        float getHumidity();        // method to get humidity
};