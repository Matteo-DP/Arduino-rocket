#include <Arduino.h>
#include <config.h>

class Logger {
    public:
        void log(String message) {
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
                    return 0;
                    return 1;
                };
        } sdCard;
} logger;