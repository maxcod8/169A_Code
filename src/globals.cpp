#include "globals.hpp"

// VEX definitons
pros::Controller controller(CONTROLLER_MASTER);
pros::Motor leftWheelsFront(LEFT_WHEELS_PORT);
pros::Motor leftWheelsBack(LEFT_WHEELS_PORT2);
pros::Motor rightWheelsFront(RIGHT_WHEELS_PORT);
pros::Motor rightWheelsBack(RIGHT_WHEELS_PORT2);
pros::Motor cataMotor(CATA_MOTOR_PORT);
pros::Motor intakeMotor(INTAKE_MOTOR_PORT);
pros::Motor fourBarMotorRight(FOUR_BAR_MOTOR_PORT);
pros::Motor fourBarMotorLeft(FOUR_BAR_MOTOR_PORT2);
pros::ADIDigitalOut piston(PISTON_PORT, false);
pros::IMU imu(IMU_PORT);

// Robot variable definitions
double orientation, previousOrientation, position, previousPosition = 0.0;
double targetMove = 0.0;
double targetAngle = 0.0;
int autoDriveState = 0;
bool opControl = true;