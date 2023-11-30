#pragma once
#include "main.h"
#include "globals.hpp"

constexpr double kP = 0.0;
constexpr double kD = 0.0;
constexpr double kI = 0.0;
constexpr double INTEGRAL_BOUND = 0.0;

double angleDifference(double angle1, double angle2);
void setMoveTargetDistance(double distance);
void setMoveTargetUnits(int encoderUnits);
void setAngleTargetRelative(double degrees);
void setAngleTargetAbsolute(double degrees);
void wait(int percentComplete);
void ball_awp();
void match_awp();
void ball1turn_awp();