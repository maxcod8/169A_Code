#include "tasks.hpp"


using namespace pros;

void updateOrientation(void* args) {
    int imuCalibrationThreshold = 100;
    int timerTime = 0;

    while (true) {
        // Wait for IMUs to calibrate
        if (timerTime <= imuCalibrationThreshold){ 
            timerTime++; 
            continue; 
        }

        // Update robot orientation with average of IMU values
        previousOrientation = orientation;
        orientation = (imuOne.get_rotation() + imuTwo.get_rotation()) / 2.0;
    }
}

void move(void* args){
    PID pid = PID(0, 0, 0, 40);

    while (true) {
        // Get average position for all drive-train wheels
        double motorRightPos = (rightWheelsFront.get_position() + rightWheelsBack.get_position()) / 2.0;
        double motorLeftPos = (leftWheelsFront.get_position() + leftWheelsBack.get_position()) / 2.0;
        double averagePosition = (motorRightPos + motorLeftPos) / 2.0;
        
        // Calculate motor output with PID
        double output = pid.calculate(targetMove, averagePosition);

        leftWheelsFront.move(output);
        leftWheelsBack.move(output);
        rightWheelsFront.move(output);
        rightWheelsBack.move(output);

        delay(TASK_DELAY);
    }
}

void turn(void* args){
    PID pid = PID(0, 0, 0, 0);

    while (true) {
        double output = pid.calculate(targetAngle, orientation);

        leftWheelsFront.move(output);
        leftWheelsBack.move(output);
        rightWheelsFront.move(-output);
        rightWheelsBack.move(-output);

        delay(TASK_DELAY);
    }
}