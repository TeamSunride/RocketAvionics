//
// Created by Tom Danvers on 27/12/2021.
// 2021 TeamSunride.
//

#include "ApogeeDetector.h"
#include "VirtualSensor.h"

ApogeeDetector::ApogeeDetector() {
    name = "ApogeeDetector";
}

void ApogeeDetector::setup() {
    log("Setting up");
    apogeeDetected = false;
    FIFO.clear();
}

void ApogeeDetector::run(float newPressure) {
    insertNewPressure(newPressure);
    VirtualSensor::logValue("bufferSize", (float) FIFO.count());
    if (!FIFO.isFull()) return; // do not process apogee if the buffer is not full yet
    float p1 = calculateAverageFromBuffer(0, APOGEE_SAMPLE_SIZE - 1);
    float p2 = calculateAverageFromBuffer(APOGEE_TOTAL_BUFFER_SIZE - 1 - APOGEE_SAMPLE_SIZE,
                                          APOGEE_TOTAL_BUFFER_SIZE - 1);
    VirtualSensor::logValue("p1", p1);
    VirtualSensor::logValue("p2", p2);
    if (p1 > p2 && !apogeeDetected) {
        apogeeDetected = true;
        VirtualSensor::broadcastEvent("APOGEE");
    }
}

void ApogeeDetector::insertNewPressure(float value) {
    FIFO.push(value);
}

float ApogeeDetector::calculateAverageFromBuffer(int index_1, int index_2) {
    float total = 0;
    int i;
    int count = 0;
    for (i = index_1; i <= index_2; i++) {
        total += FIFO.get(i);
        count++;
    }
    return total / (float)count;
}

