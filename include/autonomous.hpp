#pragma once
#include "main.h"
#include "globals.hpp"

double angleDifference(double angle1, double angle2);
void setMoveTargetDistance(double distance);
void setMoveTargetUnits(int encoderUnits);
void setAngleTargetRelative(double degrees);
void setAngleTargetAbsolute(double degrees);
void setFourBarPosition(int encoderUnits);
void wait(int percentComplete);
void ball_awp();
void close_awp();
void far_awp();
void close_elim();
void prog();