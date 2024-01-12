#pragma once
#include "main.h"
#include "PID.hpp"

// Controller Bindings
constexpr auto FLAP_FORWARD_TOGGLE_BUTTON = pros::E_CONTROLLER_DIGITAL_Y;
constexpr auto FLAP_BACKWARD_TOGGLE_BUTTON = pros::E_CONTROLLER_DIGITAL_X;
constexpr auto INTAKE_FOWARD_MANUAL_BUTTON = pros::E_CONTROLLER_DIGITAL_R2;
constexpr auto INTAKE_BACKWARD_MANUAL_BUTTON = pros::E_CONTROLLER_DIGITAL_R1;
//constexpr auto FOUR_BAR_MANUAL_UP = pros::E_CONTROLLER_DIGITAL_L1;
//constexpr auto FOUR_BAR_MANUAL_DOWN = pros::E_CONTROLLER_DIGITAL_L2;
constexpr auto CATAPULT_TOGGLE_BUTTON = pros::E_CONTROLLER_DIGITAL_RIGHT;

// VEX Ports
constexpr int LEFT_WHEELS_PORT = 17;
constexpr int LEFT_WHEELS_PORT2 = 3;
constexpr int RIGHT_WHEELS_PORT = 1;
constexpr int RIGHT_WHEELS_PORT2 = 4;
constexpr int CATA_MOTOR_PORT = 11;
constexpr int INTAKE_MOTOR_PORT = 2;
constexpr int FOUR_BAR_MOTOR_PORT = 8;
constexpr int FOUR_BAR_MOTOR_PORT2 = 13;
constexpr char FLAP_FORWARD_PORT = 'G';
constexpr char FLAP_BACKWARD_PORT = 'H';
constexpr int IMU_PORT = 11;

// Utility variables
constexpr int TASK_DELAY = 20;
constexpr double PI = 3.14159265358979323846;
constexpr double DEG_TO_RAD = PI/180;
constexpr double RAD_TO_DEG = 180/PI;
constexpr double WHEEL_DIAMETER = 3.25;
// VEX declarations
//extern pros::Controller controller;
extern pros::Controller controller;
extern pros::Motor leftWheelsFront;
extern pros::Motor leftWheelsBack;
extern pros::Motor rightWheelsFront;
extern pros::Motor rightWheelsBack;
extern pros::Motor cataMotor;
extern pros::Motor intakeMotor;
extern pros::Motor fourBarMotorRight;
extern pros::Motor fourBarMotorLeft;
extern pros::IMU imu;

extern pros::ADIDigitalOut flap_forward;
extern pros::ADIDigitalOut flap_backward;

//extern PID movePID;
//xtern PID turnPID;

// Robot variable declarations
extern double orientation, previousOrientation, position, previousPosition, fourBarPos, previousFourBarPos; 
extern double targetMove, targetAngle, targetFourBar;
extern int autoDriveState;
extern bool opControl;