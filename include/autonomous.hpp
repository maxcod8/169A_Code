#pragma once
#include "main.h"
#include "globals.hpp"

constexpr double kP = 0.0;
constexpr double kD = 0.0;
constexpr double kI = 0.0;
constexpr double INTEGRAL_BOUND = 0.0;

double angleDifference(double angle1, double angle2);
void setMoveTarget(double distance);
void setMoveTarget(int encoderUnits);
void setAngleTargetRelative(double degrees);
void setAngleTargetAbsolute(double degrees);
void wait(int percentComplete);