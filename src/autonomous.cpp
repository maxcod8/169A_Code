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
    opControl = false;
    leftWheelsBack.tare_position();
    leftWheelsFront.tare_position();
    rightWheelsBack.tare_position();
    rightWheelsFront.tare_position();
    fourBarMotorLeft.tare_position();
    fourBarMotorRight.tare_position();
    far_awp();
}


void close_elim() {
    setMoveTargetDistance(-65);
    pros::delay(1500);
    setAngleTargetAbsolute(85);
    pros::delay(800);
    intakeMotor.move(127);
    pros::delay(500);
    intakeMotor.move(0);
    setAngleTargetAbsolute(-80);
    pros::delay(1000);
    flap_forward.set_value(true);
    pros::delay(100);
    setMoveTargetDistance(45);
    pros::delay(1800);  
    setAngleTargetAbsolute(-85);
    pros::delay(500);
    flap_forward.set_value(false);
    setMoveTargetDistance(-50);
    fourBarMotorLeft.move(127);
    fourBarMotorRight.move(-127);
    pros::delay(500);
    fourBarMotorLeft.brake();
    fourBarMotorRight.brake();
    pros::delay(1100);
    setMoveTargetDistance(30);
    fourBarMotorLeft.move(-127);
    fourBarMotorRight.move(127);
    pros::delay(300);
    fourBarMotorLeft.brake();
    fourBarMotorRight.brake();
    pros::delay(1100);
    setAngleTargetAbsolute(-150);
    pros::delay(1250);
    setMoveTargetDistance(-81);
    pros::delay(1550);
    setAngleTargetRelative(-60);
    pros::delay(500);
    flap_backward.set_value(true);
    pros::delay(100);
    setAngleTargetRelative(-35);
    pros::delay(500);
    flap_backward.set_value(false);
    pros::delay(100);
    setMoveTargetDistance(-20);
    pros::delay(750);
    setAngleTargetAbsolute(-280);
    pros::delay(300);
    setMoveTargetDistance(-60);
    pros::delay(700);
    flap_backward.set_value(true);
}

void ball_awp(){
    setMoveTargetDistance(39.0);
    pros::delay(750);
    setAngleTargetAbsolute(-35.0);
    pros::delay(300);
    setMoveTargetDistance(35.0);
    pros::delay(1000);
    setMoveTargetDistance(-20);
    pros::delay(750);
    setAngleTargetAbsolute(-7);
    pros::delay(500);
    setMoveTargetDistance(-20.0);
    pros::delay(1000);
    setAngleTargetAbsolute(0);
    pros::delay(200);
    flap_backward.set_value(true);
    setMoveTargetDistance(-23);
    pros::delay(900);
    flap_backward.set_value(false);
    pros::delay(120);
    setAngleTargetAbsolute(-75.0);
    pros::delay(1000);
    setMoveTargetDistance(50);
    pros::delay(1800); 
    setAngleTargetAbsolute(-110);
    intakeMotor.move(-127);
    pros::delay(300);
    setMoveTargetDistance(20);
    pros::delay(1000);
    intakeMotor.move(0);
    setMoveTargetDistance(-15); 
    pros::delay(500);
    setAngleTargetAbsolute(-45);
    pros::delay(400);
    setMoveTargetDistance(15);
    pros::delay(800);
    setAngleTargetAbsolute(32);
    pros::delay(500);
    setMoveTargetDistance(40);
    pros::delay(1000);
    setMoveTargetDistance(-30);
    pros::delay(1000);
    setAngleTargetAbsolute(-20);
    pros::delay(500);
    setMoveTargetDistance(-50);
    pros::delay(2000);
    flap_backward.set_value(true);
    setAngleTargetAbsolute(-85);
}

void far_awp(){
    setMoveTargetDistance(39.5);
    pros::delay(750);
    setAngleTargetAbsolute(-38.0);
    pros::delay(300);
    setMoveTargetDistance(35.0);
    pros::delay(1000);
    setMoveTargetDistance(-34);
    pros::delay(1050);
    setAngleTargetAbsolute(0);
    pros::delay(300);
    flap_backward.set_value(true);
    setMoveTargetDistance(-30);
    pros::delay(1000);
    flap_backward.set_value(false);
    pros::delay(300);
    setAngleTargetAbsolute(-75.0);
    pros::delay(700);
    setMoveTargetDistance(50);
    pros::delay(1000); 
    setAngleTargetAbsolute(-110);
    intakeMotor.move(-127);
    pros::delay(400);
    setMoveTargetDistance(25);
    pros::delay(800);
    intakeMotor.move(0);
    setMoveTargetDistance(-15);
    pros::delay(500);
    setAngleTargetAbsolute(-45);
    pros::delay(400);
    setMoveTargetDistance(25);
    pros::delay(800);
    setAngleTargetAbsolute(32);
    pros::delay(500);
    setMoveTargetDistance(40);
    pros::delay(900);
    setMoveTargetDistance(-30);
    pros::delay(900);
    setAngleTargetAbsolute(-17);
    pros::delay(500);
    setMoveTargetDistance(-60);
    pros::delay(1600);
    flap_backward.set_value(true);
    setAngleTargetAbsolute(-75);
}

void close_awp() {
    setMoveTargetDistance(35);
    pros::delay(1000);
    setAngleTargetAbsolute(0);
    pros::delay(1000);
    flap_backward.set_value(true);
    setMoveTargetDistance(-25);
    pros::delay(1000);
    flap_backward.set_value(false);
    pros::delay(1000);
    setAngleTargetAbsolute(-45);
    pros::delay(1000);
    setMoveTargetDistance(-45);
    pros::delay(1000);
    setAngleTargetAbsolute(-50);
    pros::delay(250);
    setMoveTargetDistance(-20);
    pros::delay(1000);
    flap_backward.set_value(true);
}

void prog() {

}

/**
 * Returns absolute value of the difference between two angles (in degrees)
*/
double angleDifference(double angle1, double angle2) {
    double diff =  fmod(round((angle2-angle1+180.0)),360) -180.0;
    return diff < -180.0 ? diff + 360.0 : diff;
}

void setFourBarPosition(int encoderUnits) {
    targetFourBar = encoderUnits;
}

void setMoveTargetDistance(double distance){
    double encoderUnits = ((360.0 * distance) / (WHEEL_DIAMETER * PI)) * (5.0/6.0);
    targetMove += encoderUnits;
    autoDriveState = 0;
}

void setMoveTargetUnits(int encoderUnits) {
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

    // Delay robot until it has traveled % of targetDistance
    if (autoDriveState == 0){
        while (abs(targetMove - position) >= (abs(targetMove) * (100 - percentComplete) / 100.0)) 
            pros::delay(10);
    }
    // Delay robot until it has turned % of target angle
    else if (autoDriveState == 1) {
       while (abs(angleDifference(orientation, targetAngle)) >= (abs(angleDifference(previousOrientation, targetAngle)) * (100 - percentComplete) / 100.0))
            pros::delay(10);
    }

}