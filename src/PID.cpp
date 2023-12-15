#include "PID.hpp"

PID::PID(double kP, double kI, double kD, double integral_bound) {
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

    // Stop integral from growing too large (remove if using PID for lifting)
    if (error == 0 || abs(current) > abs(target) || integral > integral_bound) {
        integral = 0;
    }
    
    prevError = error;
    
    // Calculate motor output using PID
    return (error * kP) + (derivative * kD) + (integral * kI);
}

void PID::set_kP(double newkP) {
    this->kP = newkP;
}
void PID::set_kD(double newkD) {
    this->kD = newkD;
}
void PID::set_kI(double newkI) {
    this->kI = newkI;
}