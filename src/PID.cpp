#include "PID.hpp"

PID::PID(double kP, double kI, double kD) {
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
}

double PID::calculate(double target, double current) {
    // Update error, derivative, integral
    error = target - current;
    derivative = error - prevError;
    //integral += error;
    
    prevError = error;
    
    // Calculate motor output using PID
    return (error * kP) + (derivative * kD) + (integral * kI);
}