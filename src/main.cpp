#include <Arduino.h>
#include "../lib/event_detectors/ApogeeDetector.h"
#include "VirtualBarometer.h"

ApogeeDetector apogee = ApogeeDetector();

const unsigned long SERIAL_BAUD_RATE = 2000000;

VirtualBarometer barometer = VirtualBarometer();

void VirtualSensor::setup() {
    barometer.allowTesting();
    apogee.setup();
}

// TODO: LOOK AT C++ CLASS TEMPLATING! https://www.geeksforgeeks.org/templates-cpp/

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);

    Wire.begin();

    barometer.connect();

    VirtualSensor::setup();
}

void loop() {
    float pressure = barometer.getPressure();
    apogee.run(pressure);
}