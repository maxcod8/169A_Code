#include "globals.hpp"
#include "autonomous.hpp"

// VEX definitons
pros::Controller controller(CONTROLLER_MASTER);
pros::Motor leftWheelsFront(LEFT_WHEELS_PORT);
pros::Motor leftWheelsBack(LEFT_WHEELS_PORT2);
pros::Motor leftWheelsMiddle(LEFT_WHEELS_PORT3);
pros::Motor rightWheelsFront(RIGHT_WHEELS_PORT);
pros::Motor rightWheelsBack(RIGHT_WHEELS_PORT2);
pros::Motor rightWheelsMiddle(RIGHT_WHEELS_PORT3);
pros::Motor cataMotor(CATA_MOTOR_PORT);
pros::Motor intakeMotor(INTAKE_MOTOR_PORT);
pros::Motor fourBarMotorRight(FOUR_BAR_MOTOR_PORT);
pros::Motor fourBarMotorLeft(FOUR_BAR_MOTOR_PORT2);
pros::ADIDigitalOut flap_forward(FLAP_FORWARD_PORT);
pros::ADIDigitalOut flap_backward(FLAP_BACKWARD_PORT);
pros::IMU imu(IMU_PORT);

PID movePID(kP, 0, kD, 0);
PID turnPID(2, 0.0, 1.5, 0);

// Robot variable definitions
double orientation, previousOrientation, position, previousPosition = 0.0;
double fourBarPos, previousFourBarPos = 0.0;
double targetMove = 0.0;
double targetAngle = 0.0;
double targetFourBar = 0.0;
int autoDriveState = 0;
bool opControl = true;