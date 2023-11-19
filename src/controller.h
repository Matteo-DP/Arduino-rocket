#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Arduino.h>
#include <config.h>
#include <Servo.h>
#include <sensor.h>

class Controller {
    public:
        void init() {
            // Initialize controller
            servoX.init(SERVOX_PIN);
            servoY.init(SERVOY_PIN);
        };
        void stabilize() {
            // Stabilize using servo fins
            //servoX.angle = map(sensor.mpu.aX, -17000, 17000, 179, 0); // 179 = 0 degrees, 0 = 180 degrees
            //servoY.angle = map(sensor.mpu.aY, -17000, 17000, 179, 0);
            servoX.angle = sensor.mpu.euler[1];
            servoY.angle = sensor.mpu.euler[2];
            servoX.move();
            servoY.move();
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
        class Parachute {
            public:
                void deploy() {
                    // Deploy parachute
                };
        } parachute;
    private:
        class Servos {
            public:
                Servo servo;
                int angle;
                int prevAngle;
                void init(uint8_t pin) {
                    // Initialize servo
                    servo.attach(pin);
                }
                void move() {
                    // Move opposite servos to angle
                    if(angle == prevAngle) { return; };
                    #ifdef SERVO_DEBUG
                        Serial.print("Servo:");
                        Serial.print(angle);
                        Serial.print("\n");
                    #endif
                    servo.write(angle);
                    prevAngle = angle;
                    delay(15);
                };
        } servoX, servoY;
} controller;

#endif