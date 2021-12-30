//
// Created by Tom Danvers on 27/12/2021.
// 2021 TeamSunride.
//

#ifndef TEAMSUNRIDE_EVENTDETECT0R_H
#define TEAMSUNRIDE_EVENTDETECT0R_H

#include <Arduino.h>

class EventDetector {
public:
    String name = "Unnamed EventDetector";
    void log(const String& msg) const;
};


#endif //TEAMSUNRIDE_EVENTDETECT0R_H
