#include <Arduino.h>
#include <config.h>

class Sensor {
    public:
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
        class MPU6050 {
            public:
                void init() {
                    // Initialize MPU6050
                };
                void calibrate() {
                    // Calibrate MPU6050
                };
                void read() {
                    // Read MPU6050
                };
        } mpu6050;
} sensor;