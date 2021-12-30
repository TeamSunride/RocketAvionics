//
// Created by Tom Danvers on 27/12/2021.
// 2021 TeamSunride.
//

#include "EventDetector.h"
#include <Arduino.h>

void EventDetector::log(const String& msg) const {
    Serial.println("[" + name + "] " + msg);
}
