#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>
#include <config.h>

class Logger {
    public:
        void log(String message, int16_t level = LOG_INFO) {
            // Log data to serial monitor
            Serial.println(message);
        };
        void save(String message) {
            // Save timestamped string to SD card
            sdCard.save(message);
        };
    private:
        class SdCard {
            public:
                void init() {
                    // Initialize SD card
                }
                void save(String message) {
                    // Save timestamped string to SD card
                };
                int test() {
                    // Test SD card
                    // Check if enough space is available
                    return 0;
                    // return WARN_ALMOST_FULL;
                    // return 1;
                };
        } sdCard;
} logger;

#endif