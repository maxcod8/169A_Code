#pragma once
#include "main.h"

constexpr int LEFT_WHEELS_PORT = 18;//8;
constexpr int LEFT_WHEELS_PORT2 = 19;//10;
constexpr int RIGHT_WHEELS_PORT = 13;//1;
constexpr int RIGHT_WHEELS_PORT2 = 5;//4;

constexpr int LEFT_ROTATION_PORT = 15;
constexpr int RIGHT_ROTATION_PORT = 16;
constexpr int SIDE_ROTATION_PORT = 17;
constexpr int CATA_ROTATION_PORT = 0;

constexpr int TASK_DELAY = 20;
constexpr double PI = 3.14159265358979323846;
constexpr double DEG_TO_RAD = PI/180;
constexpr double RAD_TO_DEG = 180/PI;

constexpr double WHEEL_RADIUS = 3.25/2;
constexpr double DST_SIDE = 2.0;
constexpr double DST_BACK = 5.0;

constexpr double CATA_DRAWBACK = 0;
constexpr double CATA_POWER = 0;

extern pros::Controller controller;
extern pros::Motor leftWheelsOne;
extern pros::Motor leftWheelsTwo;
extern pros::Motor rightWheelsOne;
extern pros::Motor rightWheelsTwo;
   
extern pros::Rotation leftRotationSensor;
extern pros::Rotation rightRotationSensor;
extern pros::Rotation sideRotationSensor;
extern pros::Rotation cataRotationSensor;

extern double x, y, orientation;
extern double goalX, goalY, goalAngle;
extern double lastLeftRot, lastRightRot, lastSideRot;
extern int autoDriveState;

