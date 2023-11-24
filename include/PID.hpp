#pragma once
#include "globals.hpp"
#include "main.h"

class PID {
private:
    double kP, kI, kD, integral_bound;
    double error, prevError, integral, derivative = 0.0;
public:
    PID (double kP, double kI, double kD, double integralBound);
    double calculate(double target, double current);
};