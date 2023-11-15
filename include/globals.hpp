#pragma once
#include "main.h"

constexpr auto FLAP_TOGGLE_BUTTON = pros::E_CONTROLLER_DIGITAL_RIGHT;
constexpr auto INTAKE_FOWARD_TOGGLE_BUTTON = pros::E_CONTROLLER_DIGITAL_R1;
constexpr auto INTAKE_BACKWARD_TOGGLE_BUTTON = pros::E_CONTROLLER_DIGITAL_R2;
constexpr auto FOUR_BAR_TOGGLE_BUTTON = pros::E_CONTROLLER_DIGITAL_L1;
constexpr auto CATAPULT_TOGGLE_BUTTON = pros::E_CONTROLLER_DIGITAL_L2;

constexpr int LEFT_WHEELS_PORT = 1;
constexpr int LEFT_WHEELS_PORT2 = 16;
constexpr int RIGHT_WHEELS_PORT = 13;
constexpr int RIGHT_WHEELS_PORT2 = 14;
constexpr int CATA_MOTOR_PORT = 6;
constexpr int INTAKE_MOTOR_PORT = 4;
constexpr int FOUR_BAR_MOTOR_PORT = 5;

//constexpr int LEFT_ROTATION_PORT = 15;
//constexpr int RIGHT_ROTATION_PORT = 16;
//constexpr int SIDE_ROTATION_PORT = 17;
//constexpr int CATA_ROTATION_PORT = 0;

constexpr char PISTON_PORT = 'B';

constexpr int TASK_DELAY = 20;
constexpr double PI = 3.14159265358979323846;
constexpr double DEG_TO_RAD = PI/180;
constexpr double RAD_TO_DEG = 180/PI;

constexpr double WHEEL_RADIUS = 2.75/2;
constexpr double DST_SIDE = 3;
constexpr double DST_BACK = 5.5;

constexpr double CATA_ANGLE = 0;
constexpr double CATA_POWER = 0;

extern pros::Controller controller;
extern pros::Motor leftWheelsFront;
extern pros::Motor leftWheelsBack;
extern pros::Motor rightWheelsFront;
extern pros::Motor rightWheelsBack;
extern pros::Motor cataMotor;
extern pros::Motor intakeMotor;
extern pros::Motor fourBarMotor;
   
//extern pros::Rotation leftRotationSensor;
//extern pros::Rotation rightRotationSensor;
//extern pros::Rotation sideRotationSensor;
//extern pros::Rotation cataRotationSensor;

extern pros::ADIDigitalOut piston;

extern double x, y, theta, odomHeading;
extern double goalX, goalY, goalAngle;
extern double lastLeftRot, lastRightRot, lastSideRot;
extern int autoDriveState;

double degrees_to_position(double degrees);