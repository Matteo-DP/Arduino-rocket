#include <Arduino.h>
#include <config.h>

class Controller {
    public:
        void init() {
            // Initialize controller
        };
        void stabilize() {
            // Stabilize using servo fins
        };
        class Buzzer {
            void buzz() {
                // Buzz for each test
                // Buzz for calibration
                // Buzz for initialisation complete
            };
        } buzzer;
        class Camera {
            public:
                void init() {
                    // Initialize camera
                };
                void test() {
                    // Test camera
                    // Not sure if this is possible
                };
                void capture() {
                    // Capture image
                };
                int record() {
                    // Record video
                    return 0;
                    return 1;
                };
        } camera;
    private:
        class Servo1 {
            public:
                void move(int angle) {
                    // Move opposite servos to angle
                };
        } servo1;
        class Servo2 {
            public:
                void move(int angle) {
                    // Move opposite servos to angle
                };
        } servo2;
} controller;