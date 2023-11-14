#include "tasks.hpp"

using namespace pros;

void trackPosition(){
    // Read rotation sensor values
    double leftRot = leftRotationSensor.get_position() / 100;
    double rightRot = rightRotationSensor.get_position() / -100;
    double sideRot = sideRotationSensor.get_position() / 100;
    
    // Convert rotation to linear distance
    double deltaL = (leftRot-lastLeftRot) * WHEEL_RADIUS * DEG_TO_RAD;
    double deltaR = (rightRot-lastRightRot) * WHEEL_RADIUS * DEG_TO_RAD;
    double deltaS = (sideRot-lastSideRot) * WHEEL_RADIUS * DEG_TO_RAD;

    lastLeftRot = leftRot;
    lastRightRot = rightRot;
    lastSideRot = sideRot;

    // Relative orientation
    double deltaTheta = (deltaL - deltaR) / (DST_SIDE * 2.0);

    // Relative position since last movement
    double h, h2;
    double c;
    if (deltaTheta == 0) {
        h = deltaS;
        h2 = deltaR;
        c = 0;
    }
    else {
        c = deltaTheta / 2.0;
        h = ((deltaR / deltaTheta) + DST_SIDE) * sin(c) * 2.0;
        h2 = ((deltaS / deltaTheta) + DST_BACK) * sin(c) * 2.0;
    }

    // Average rotation
    double thetaM = c - theta;
    double cosThetaM = cos(thetaM);
    double sinThetaM = sin(thetaM);

    // Relative position
    double deltaX = (h * cosThetaM) - (h2 * sinThetaM);
    double deltaY = (h * sinThetaM) + (h2 * cosThetaM);

    // Update global position/orientation
	x += deltaX;
	y += deltaY;
    theta += deltaTheta;
    odomHeading = theta * RAD_TO_DEG;

    lcd::print(2, "h: %f, h2: %f\n", h, h2);
    lcd::print(3, "x: %f, y: %f\n", x, y);
    lcd::print(5, "theta: %f\n", theta);
    lcd::print(6, "heading: %f\n", odomHeading);
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

