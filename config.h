#define INTERVAL_SERVO 300
#define INTERVAL_SENSOR 300

#define PIN_SERVO 10
#define PIN_SENSOR_ECHO 4
#define PIN_SENSOR_TRIGGER 2

#define PIN_BUTTON 7
#define PIN_LED 13

#define R_MOTOR_PIN 6
#define R_MOTOR_PIN_DIR 8
#define L_MOTOR_PIN 11
#define L_MOTOR_PIN_DIR 12 

//CONSTANTS AND GLOBAL VARIABLES
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
int buttonState;
int robotModeIndicator = LOW; // LOW = idle, HIGH = moving
int lastButtonState = HIGH;

#define STATE_MOVING HIGH
#define STATE_IDLE LOW

#define FORWARD_DIR LOW
#define BACKWARDS_DIR HIGH

//speeds
#define BACKWARDS_DIR_SPEED 30
#define SLOW 160
#define MEDIUM_SPEED 190
#define FAST 240

//distances
#define RISK_DIST 35
#define VERY_FAR_DIST 350
#define FAR_DIST 250
#define MEDIUM_DIST 125

#define TURN_DIST 100

//sides
#define LEFT_SIDE_SERVO 0
#define RIGHT_SIDE_SERVO 180
#define FRONT_SIDE_SERVO 90
#define LEFT 'L'
#define RIGHT 'R'

//regimes
#define REGIME_FAST 1
#define REGIME_MEDIUM 2
#define REGIME_SLOW 3
#define REGIME_RISK 4
