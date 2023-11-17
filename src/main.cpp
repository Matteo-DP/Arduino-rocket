#include <Arduino.h>
#include <config.h>
#include <controller.h>
#include <logger.h>
#include <sensor.h>

void setup() {
    Serial.begin(SERIAL_BAUD);
    // Initialize controller
    // Initialize logger
    // Initialize sensor

    // Buzz
    // SD card module test
    // SD card almost full warning:
    //     Test enivornment: buzz 3 times
    //     Production: buzz 3 times and abort
    // Buzz twice
    // Buzz
    // RTC test
    // Buzz twice
    // Calibration of MPU6050? External signal dependant? Should not be done every time
    // Tests successful (return values of both test functions = 0) --> move to main loop
};

void loop() {
    // Controller stabilization
    // Data logging
};