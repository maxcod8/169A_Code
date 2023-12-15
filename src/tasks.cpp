#include "tasks.hpp"
using namespace pros;

void move(void* args){
    while (true) {
        // Get average position for all drive-train wheels
        double motorRightPos = (rightWheelsFront.get_position() + rightWheelsBack.get_position()) / 2.0;
        double motorLeftPos = (leftWheelsFront.get_position() + leftWheelsBack.get_position()) / 2.0;
        position = (motorRightPos - motorLeftPos) / 2.0;

        pros::lcd::print(1, "Pos: %f", position);
        
        // Calculate motor output with PID
        double output = movePID.calculate(targetMove, position);

        pros::lcd::print(2, "Move output: %f", output);
        pros::lcd::print(5, "Move target: %f", targetMove);

        if (!opControl && autoDriveState == 0) {
            leftWheelsFront.move(-output);
            leftWheelsBack.move(-output);
            rightWheelsFront.move(output);
            rightWheelsBack.move(output);
        }

        previousPosition = position;
    
        delay(TASK_DELAY);
    }
}

void turn(void* args){
    int imuCalibrationThreshold = 100;
    int timerTime = 0;

    while (true) {
        // Wait for IMUs to calibrate
        if (timerTime <= imuCalibrationThreshold){ 
            timerTime++; 
            continue; 
        }

        // Update robot orientation
        orientation = imu.get_rotation();
        
        controller.print(1, 0, "IMU: %f", orientation);
        pros::lcd::print(3, "Orientation: %f", orientation);

        // Calcuate turn PID
        double output = -turnPID.calculate(targetAngle, orientation);

        pros::lcd::print(4, "Turn output: %f", output);
        pros::lcd::print(6, "Turn target: %f", targetAngle);

        if (!opControl && autoDriveState == 1) {
            leftWheelsFront.move(output);
            leftWheelsBack.move(output);
            rightWheelsFront.move(output);
            rightWheelsBack.move(output);
        }
        
        previousOrientation = orientation;
        delay(TASK_DELAY);
    }
}