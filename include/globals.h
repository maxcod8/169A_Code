#include "main.h"

constexpr int LEFT_WHEELS_PORT = 1;
constexpr int RIGHT_WHEELS_PORT = 10;

pros::Controller controller(CONTROLLER_MASTER);
pros::Motor leftWheels(LEFT_WHEELS_PORT);
pros::Motor rightWheels(RIGHT_WHEELS_PORT);
