#include "VirtualBarometer.h"

VirtualBarometer::VirtualBarometer()
{
    manufacturer = "UNKNOWN";
    name = "BME280";
}

void VirtualBarometer::connect()
{
    return 0;
}

// Returns temperature in a range between -40 and 85°C
float VirtualBarometer::getTemperature()
{
    if (isTesting()) {
        return getFloatSimulated("air_temperature");
    }
    return 0;
};

// Returns pressure in Pascals between a range of 30000 and 110000
float VirtualBarometer::getPressure()
{
    if (isTesting()) {
        return getFloatSimulated("air_pressure");
    }
    return 0;
};

// Returns relative humidity as a percentage between 0 and 100
float VirtualBarometer::getHumidity()
{
    if (isTesting()) {
        return getFloatSimulated("humidity");
    }
    return 0;
};