#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include <config.h>
#include <I2Cdev.h>
#include <MPU6050.h>

class Sensor {
    public:
        void init() {
            mpu.init();
        };
        class RTC {
            public:
                void init() {
                    // Initialize RTC
                };
                void getTime() {
                    // Get time from RTC
                };
                int test() {
                    // Test RTC
                    return 0;
                    return 1;
                };
        } rtc;
        class MPU {
            public:
                MPU6050 _mpu;
                int16_t aX, aY, aZ;
                int16_t gX, gY, gZ;
                void init() {
                    // Initialize MPU6050
                    _mpu.initialize();
                    setFreeFall();
                };
                void calibrate() {
                    // Calibrate MPU6050
                };
                void read() {
                    // Read MPU6050
                    _mpu.getMotion6(&aX, &aY, &aZ, &gX, &gY, &gZ);
                    #ifdef MPU_DEBUG
                        Serial.print("aX:");
                        Serial.print(aX);
                        Serial.print(",");
                        Serial.print("aY:");
                        Serial.print(aY);
                        Serial.print("\n");
                    #endif
                };
                int test() {
                    // Test MPU6050 connection
                    if(_mpu.testConnection()) {
                        return 0;
                    } else {
                        return 1;
                    }
                };
                void checkFreeFallAndDeployParachute() {
                    // Check if free fall is detected
                    if(_mpu.getIntFreefallStatus() == 1) {
                        // Free fall detected
                        logger.log("Free fall detected", LOG_INFO);
                        #ifndef DONT_DEPLOY_PARACHUTE
                            logger.log("Deploying parachute", LOG_INFO);
                            parachute.deploy();
                        #endif
                        #ifdef DONT_DEPLOY_PARACHUTE
                            logger.log("Parachute deployment disabled (DONT_DEPLOY_PARACHUTE)", LOG_INFO);
                        #endif
                    };
                };
                void setFreeFall() {
                    // Set free fall detection values
                    _mpu.setFreefallDetectionThreshold(FREEFALL_DETECTION_THRESHOLD);
                    _mpu.setFreefallDetectionDuration(FREEFALL_DETECTION_DURATION);
                };
                void saveQuaternion() {
                    // Save quaternion to SD card
                };
        } mpu;
} sensor;

#endif