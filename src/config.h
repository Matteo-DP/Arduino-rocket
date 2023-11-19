// Serial
#define SERIAL_BAUD 115200

// SD card module
#define WARN_ALMOST_FULL 2

// Servo
#define SERVOX_PIN 9
#define SERVOY_PIN 10

// Logger
#define LOG_ERROR 0
#define LOG_WARN 1
#define LOG_INFO 2
#define LOG_SENSOR 3
#define LOG_MODE LOG_SENSOR

// Debug modes (uncomment to enable)
//#define MPU_DEBUG
//#define SERVO_DEBUG

// MPU6050
// TODO: TEST THIS TO MAKE SURE IT DOESNST EXCEED THE TERMINAL VELOCITY
// 1s of freefall will be detected as freefall
#define FREEFALL_DETECTION_THRESHOLD 0x14 // 500mg
#define FREEFALL_DETECTION_DURATION 0x01 // 500ms

// Miscellanious
// Used to calculate time to reach free fall detection threshold <sensor.h>
#define ROCKET_WEIGHT_GRAMS 500

// Parachute
// Uncomment to disable parachute deployment
#define DONT_DEPLOY_PARACHUTE