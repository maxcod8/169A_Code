#include "globals.hpp"

pros::Controller controller(CONTROLLER_MASTER);
pros::Motor leftWheelsOne(LEFT_WHEELS_PORT);
pros::Motor leftWheelsTwo(LEFT_WHEELS_PORT2);
pros::Motor rightWheelsOne(RIGHT_WHEELS_PORT);
pros::Motor rightWheelsTwo(RIGHT_WHEELS_PORT2);

pros::Rotation leftRotationSensor(LEFT_ROTATION_PORT);
pros::Rotation rightRotationSensor(RIGHT_ROTATION_PORT);
pros::Rotation sideRotationSensor(SIDE_ROTATION_PORT);
pros::Rotation cataRotationSensor(CATA_ROTATION_PORT);

double x, y, orientation;
double goalX, goalY, goalAngle;
double lastLeftRot, lastRightRot, lastSideRot;
int autoDriveState;