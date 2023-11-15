#include "globals.hpp"

pros::Controller controller(CONTROLLER_MASTER);
pros::Motor leftWheelsFront(LEFT_WHEELS_PORT);
pros::Motor leftWheelsBack(LEFT_WHEELS_PORT2);
pros::Motor rightWheelsFront(RIGHT_WHEELS_PORT);
pros::Motor rightWheelsBack(RIGHT_WHEELS_PORT2);
pros::Motor cataMotor(CATA_MOTOR_PORT);
pros::Motor intakeMotor(INTAKE_MOTOR_PORT);
pros::Motor fourBarMotor(FOUR_BAR_MOTOR_PORT);

//pros::Rotation leftRotationSensor(LEFT_ROTATION_PORT);
//pros::Rotation rightRotationSensor(RIGHT_ROTATION_PORT);
//pros::Rotation sideRotationSensor(SIDE_ROTATION_PORT);
//pros::Rotation cataRotationSensor(CATA_ROTATION_PORT);

pros::ADIDigitalOut piston(PISTON_PORT, true);

double x, y, theta, odomHeading;
double goalX, goalY, goalAngle;
double lastLeftRot, lastRightRot, lastSideRot;
int autoDriveState;

double degrees_to_position(double degrees) {
    return degrees * (5/6);
}