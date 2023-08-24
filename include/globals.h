#include "main.h"

constexpr int LEFT_WHEELS_PORT = 1;
constexpr int RIGHT_WHEELS_PORT = 10;
constexpr int LEFT_ROTATION_PORT = 0;
constexpr int RIGHT_ROTATION_PORT = 0;
constexpr int SIDE_ROTATION_PORT = 0;

constexpr int TASK_DELAY = 20;
constexpr double PI = 3.14159265358979323846;
constexpr double DEG_TO_RAD = PI/180;

constexpr double WHEEL_RADIUS = 3.25/2;
constexpr double DST_SIDE = 0.0;
constexpr double DST_BACK = 0.0;

pros::Controller controller(CONTROLLER_MASTER);
pros::Motor leftWheels(LEFT_WHEELS_PORT);
pros::Motor rightWheels(RIGHT_WHEELS_PORT);

pros::Rotation leftRotationSensor(LEFT_ROTATION_PORT);
pros::Rotation rightRotationSensor(RIGHT_ROTATION_PORT);
pros::Rotation sideRotationSensor(SIDE_ROTATION_PORT);

bool odom = false;
int autoDriveState;

double x;
double y;
double orientation;

double lastLeftRot;
double lastRightRot;
double lastSideRot;

double goalAngle;
double goalX;
double goalY;
