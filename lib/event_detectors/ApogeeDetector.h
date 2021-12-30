//
// Created by Tom Danvers on 27/12/2021.
// 2021 TeamSunride.
//

#ifndef TEAMSUNRIDE_APOGEEDETECTOR_H
#define TEAMSUNRIDE_APOGEEDETECTOR_H

#include "EventDetector.h"
#include "FIFObuffer.h"

const int APOGEE_SAMPLE_GAP = 64;
const int APOGEE_SAMPLE_SIZE = 32;
const int APOGEE_TOTAL_BUFFER_SIZE = APOGEE_SAMPLE_GAP + (2 * APOGEE_SAMPLE_SIZE);

class ApogeeDetector : EventDetector {
public:
    ApogeeDetector();
    void setup();
    void run(float newPressure);
    bool apogeeDetected = false;
    FIFObuffer<float, APOGEE_TOTAL_BUFFER_SIZE> FIFO;
private:
    void insertNewPressure(float value);
    float calculateAverageFromBuffer(int index_1, int index_2);
};


#endif //TEAMSUNRIDE_APOGEEDETECTOR_H
