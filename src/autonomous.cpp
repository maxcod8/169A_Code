#include "autonomous.hpp"

/**  
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    
}
/**
 * Returns absolute value of the difference between two angles (in degrees)
*/
double angleDifference(double angle1, double angle2) {
    return 180.0 - abs(abs(angle2 - angle1) - 180.0);
}

void setMoveTarget(double distance){
    double encoderUnits = ((360.0 * distance) / (WHEEL_DIAMETER * PI)) * (5/6);
    targetMove += encoderUnits;
    autoDriveState = 0;
}

void setMoveTarget(int encoderUnits) {
    targetMove += encoderUnits;
    autoDriveState = 0;
}

void setAngleTargetRelative(double degrees) {
    targetAngle += degrees;
    autoDriveState = 1;
}

void setAngleTargetAbsolute(double degrees) {
    targetAngle = degrees;
    autoDriveState = 1;
}

void wait(int percentComplete) {

    // Get average position for all drive-train wheels
    double motorRightPos = (rightWheelsFront.get_position() + rightWheelsBack.get_position()) / 2.0;
    double motorLeftPos = (leftWheelsFront.get_position() + leftWheelsBack.get_position()) / 2.0;
    double averagePosition = (motorRightPos + motorLeftPos) / 2.0;

    // Delay robot until it has traveled % of targetDistance
    if (autoDriveState == 0){
        while (abs(targetMove - averagePosition) >= (targetMove * (percentComplete - 100) / 100.0)) 
            pros::delay(10);
    }
    // Delay robot until it has turned % of target angle
    else if (autoDriveState == 1) {
       while (angleDifference(orientation, targetAngle) >= (angleDifference(previousOrientation, targetAngle) * (percentComplete - 100) / 100.0))
            pros::delay(10);
    }

}