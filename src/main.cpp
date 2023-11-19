#include <Arduino.h>
#include <config.h>
#include <controller.h>
#include <logger.h>
#include <sensor.h>
#include <Wire.h>

void stopInitialisation(String error) {
    // Buzz 3 times
    // Stop program
    logger.log("Fatal error: " + error);
    while (1) {}
};

void setup() {
    Wire.begin();
    Serial.begin(SERIAL_BAUD);
    // Initialize controller
    controller.init();
    // Initialize logger
    // Initialize sensor
    if(sensor.init() == 1) { stopInitialisation("Sensor initialisation error");}

    // Buzz
    // MPU6050 test
    if(sensor.mpu.test() == 1) { stopInitialisation("MPU not found"); };
    // Buzz twice
    // Buzz
    // SD card module test
    // SD card almost full warning: Buzz 3 times and abort
    // Buzz twice
    // Buzz
    // RTC test
    // Buzz twice
    // Calibration of MPU6050? External signal dependant? Should not be done every time
    // Tests successful (return values of both test functions = 0) --> move to main loop
    #ifdef DONT_DEPLOY_PARACHUTE
        logger.log("Parachute deployment disabled", LOG_WARN);
    #endif
    logger.log("Initialisation complete", LOG_INFO);
};

void loop() {
    // Controller stabilization: read gyroscope, adjust servo angle accordingly
    sensor.mpu.read();
    controller.stabilize();
    // Check parachute deployment: check if free fall is detected, deploy parachute if so
    sensor.mpu.checkFreeFallAndDeployParachute();
    // Data logging: stream gyroscopic quaternion data to SD card
};