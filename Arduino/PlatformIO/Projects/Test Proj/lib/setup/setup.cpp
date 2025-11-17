#include "setup.h"

void setupInit() {
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);
}

void migalc() {
    static uint32_t nextTimeTask = 0;

    if(millis() >= nextTimeTask) {
        if ((millis() - nextTimeTask) >= LED_BLINK_TIME) {
            digitalWrite(BLUE_LED_PIN, !digitalRead(BLUE_LED_PIN));
            digitalWrite(RED_LED_PIN, !digitalRead(BLUE_LED_PIN));
            nextTimeTask = millis() + LED_BLINK_TIME;
            
        }
    }
}
