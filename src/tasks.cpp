#include "tasks.h"

using namespace pros;

void trackPosition(){
    // Read rotation sensor values
    double leftRot = leftRotationSensor.get_position() / 100;
    double rightRot = rightRotationSensor.get_position() / -100;
    double sideRot = sideRotationSensor.get_position() / -100;
    
    // Convert rotation to linear distance
    double deltaL = (leftRot-lastLeftRot) * WHEEL_RADIUS * DEG_TO_RAD;
    double deltaR = (rightRot-lastRightRot) * WHEEL_RADIUS * DEG_TO_RAD;
    double deltaS = (sideRot-lastSideRot) * WHEEL_RADIUS * DEG_TO_RAD;

    lastLeftRot = leftRot;
    lastRightRot = rightRot;
    lastSideRot = sideRot;

    // Absolute oreintation and change in orientation
    double newRot = (deltaL - deltaR) / (DST_SIDE * 2.0);
    double deltaRot = newRot - orientation;

    // Relative position since last movement
    double h, h2;
    if (deltaRot == 0) {
        h = deltaS;
        h2 = deltaR;
    }
    else {
        double i = 2 * sin(newRot / 2);
        h = ((deltaS / deltaRot) + DST_BACK) * i;
        h2 = ((deltaR / deltaRot) + DST_SIDE) * i;
    }

    // Calculate average rotation
    double avgRot = orientation + (deltaRot / 2.0);
    orientation = newRot;

    // Convert to polar coordiantes
    double r = sqrt(h*h + h2*h2);
    double theta = atan(h2/h);
    // Rotate by -(average rotation)
    theta -= avgRot;

    // Convert back to cartesian coordinates
    double newX = r * cos(theta);
    double newY = r * sin(theta);

    // Update absolute position
    x += newX;
    y += newY;
}

void updateOdometry(void* args){
    leftRotationSensor.reset_position();
    rightRotationSensor.reset_position();
    sideRotationSensor.reset_position();

    while (true){
        trackPosition();
        delay(TASK_DELAY);
    }
}

void moveTo(void* args){
    delay(TASK_DELAY);
}

void turnTo(void* args){
    delay(TASK_DELAY);
}

void lookAt(void* args){
    delay(TASK_DELAY);
}

void stationaryCheck(void* args){
    delay(TASK_DELAY);
}