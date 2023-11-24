#include "PID.hpp"

PID::PID(double kP, double kI, double kD, double integralBound) {
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
    this->integral_bound = integral_bound;
}

double PID::calculate(double target, double current) {
    // Update error, derivative, integral
    error = target - current;
    derivative = error - prevError;
    integral += error;
       
    // Apply anti-integral windup
    if (abs(error) < integral_bound){
        integral += error;
    } else {
        integral = 0;
    }
    
    prevError = error;
    
    // Calculate motor output using PID
    return (error * kP) + (derivative * kD) + (integral * kI);
}