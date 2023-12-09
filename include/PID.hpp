#pragma once
#include "globals.hpp"
#include "main.h"

class PID {
private:
    double kP, kI, kD;
    double error, prevError, integral, derivative = 0.0;
public:
    PID (double kP, double kI, double kD);
    double calculate(double target, double current);
};