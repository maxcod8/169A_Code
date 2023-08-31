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

    // Absolute oreintation and change in orientation
    double newRot = (deltaL - deltaR) / (DST_SIDE * 2.0);

    // Relative position since last movement
    double h, h2;
    if (newRot == 0) {
        h = deltaS;
        h2 = deltaR;
    }
    else {
        double i = 2 * sin(newRot / 2);
        h = ((deltaS / newRot) + DST_BACK) * i;
        h2 = ((deltaR / newRot) + DST_SIDE) * i;
    }

    // Calculate average rotation
    double avgRot = (newRot / 2.0) - orientation;
    orientation += newRot;

    double newX = x + (h * sin(avgRot));
    double newY = y + (h * cos(avgRot));

	newX += h2 * cos(avgRot);
	newY += h2 * -sin(avgRot);

	x = newY;
	y = newX;

    lcd::print(2, "x: %f\n", x);
    lcd::print(3, "y: %f\n", y);
    lcd::print(4, "thetaRAD: %f\n", orientation);
    lcd::print(5, "thetaDEG: %f\n", orientation * RAD_TO_DEG);
    lcd::print(6, "rightD: %f, leftd: %f", deltaR, deltaL);
    lcd::print(7, "sideD: %f", deltaS);
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

void cataControl(void* args){
    cataRotationSensor.reset_position();

    while (true){
        double turnDegrees = cataRotationSensor.get_position()/100.0;

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
