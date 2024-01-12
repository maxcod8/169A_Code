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

    leftWheelsBack.move(100);
    leftWheelsFront.move(100);
    rightWheelsBack.move(-100);
    rightWheelsFront.move(-1000);

    pros::delay(2000);
    
    leftWheelsBack.move(-90);
    leftWheelsFront.move(-90);
    rightWheelsBack.move(90);
    rightWheelsFront.move(90);

    pros::delay(1000);

    leftWheelsBack.move(-90);
    leftWheelsFront.move(-90);
    rightWheelsBack.move(90);
    rightWheelsFront.move(90);

    pros::delay(15000);

    //leftWheelsBack.move(100);
    //leftWheelsFront.move(100);
    //rightWheelsBack.move(-100);
   //rightWheelsFront.move(-1000);

    //pros::delay(3000);
   // leftWheelsBack.move(-90);
   // leftWheelsFront.move(-90);
  //  rightWheelsBack.move(90);
  //  rightWheelsFront.move(90);

   // fourBarMotorLeft.tare_position();
   // fourBarMotorRight.tare_position();
   // far_elim();

}

//void far_elim(){
   // intakeMotor.move(-127);
   // setMoveTargetUnits(375);
   // pros::delay(775);
   // intakeMotor.move(0);
   // setMoveTargetUnits(-1650);
  //  pros::delay(1000);
  //  setAngleTargetAbsolute(-45);
  //  pros::delay(500);
  //  flap_backward.set_value(true);
  //  setMoveTargetUnits(-650);
  //  pros::delay(800);
  //  setAngleTargetAbsolute(-110);
  //  pros::delay(700);
   // setAngleTargetAbsolute(-67);
   // flap_backward.set_value(false);
   // fourBarMotorLeft.move(127);
  //  fourBarMotorRight.move(-127);
   // pros::delay(500);
   // fourBarMotorLeft.brake();
   // fourBarMotorRight.brake();
   // pros::delay(200);
   // setMoveTargetUnits(-1550);  
  //  pros::delay(1000);
  //  setMoveTargetUnits(550);
  //  pros::delay(200);
  //  fourBarMotorLeft.move(-127);
  //  fourBarMotorRight.move(127);
  //  pros::delay(300);
  //  fourBarMotorLeft.move(0);
  //  fourBarMotorRight.move(0);
  //  pros::delay(150);
  //  setAngleTargetAbsolute(85.0);
  //  pros::delay(800);
  //  setMoveTargetUnits(850);
  //  pros::delay(1500);
   // setMoveTargetUnits(-750);
   // pros::delay(1000);
   // setAngleTargetAbsolute(17.5);
  //  intakeMotor.move(-127);
  //  pros::delay(800);
  //  setMoveTargetUnits(2268);
  //  pros::delay(1700);
   // intakeMotor.move(0);
  //  setAngleTargetAbsolute(90);
  //  pros::delay(500);
  //  setMoveTargetUnits(650);
  //  pros::delay(750);
   // flap_forward.set_value(true);
   // setAngleTargetAbsolute(162.5);
   // pros::delay(1000);
  //  setMoveTargetUnits(1800);
  //  pros::delay(2000);
  //  setMoveTargetUnits(-800);
//}

//oid check_close_elim() {
   // setMoveTargetDistance(-65);
   // pros::delay(1500);
   // setAngleTargetAbsolute(85);
   // pros::delay(800);
  //  intakeMotor.move(127);
   // pros::delay(500);
  //  intakeMotor.move(0);
  //  setAngleTargetAbsolute(-80);
  //  pros::delay(1000);
  //  flap_forward.set_value(true);
  //  pros::delay(100);
  //  setMoveTargetDistance(45);
  //  pros::delay(1800);  
 //  setAngleTargetAbsolute(-85);
  //  pros::delay(500);
  //  flap_forward.set_value(false);
  //  setMoveTargetDistance(-47.5);
  //  fourBarMotorLeft.move(127);
  //  fourBarMotorRight.move(-127);
  //  pros::delay(500);
  //  fourBarMotorLeft.brake();
  //  fourBarMotorRight.brake();
  //  pros::delay(1100);
  //  setMoveTargetDistance(30);
   // fourBarMotorLeft.move(-127);
  //  fourBarMotorRight.move(127);
  //  pros::delay(300);
  //  fourBarMotorLeft.brake();
  //  fourBarMotorRight.brake();
   // pros::delay(1100);
  //  setAngleTargetAbsolute(-150);
  //  pros::delay(1250);
  //  setMoveTargetDistance(-79.5);
  //  pros::delay(1550);
  //  setAngleTargetRelative(-50);
  //  pros::delay(500);
  //  flap_backward.set_value(true);
  //  pros::delay(100);
    //setAngleTargetRelative(-45);
   // pros::delay(500);
   // flap_backward.set_value(false);
   // pros::delay(100);
   // setMoveTargetDistance(-20);
   // pros::delay(750);
   // setAngleTargetAbsolute(-275);
   // pros::delay(300);
   // setMoveTargetDistance(-45);
  //  pros::delay(700);
  //  flap_backward.set_value(true);
//}

//void close_elim() {
  //  setMoveTargetDistance(-65);
  //  pros::delay(1500);
  //  setAngleTargetAbsolute(85);
  //  pros::delay(800);
  //  intakeMotor.move(127);
  //  pros::delay(600);
  //  intakeMotor.move(0);
  //  setMoveTargetDistance(-10);
  //  pros::delay(400);
  //  setAngleTargetAbsolute(-80);
  //  pros::delay(1000);
  //  flap_forward.set_value(true);
  //  pros::delay(100);
  //  setMoveTargetDistance(35);
  //  pros::delay(1500);  
  //  setAngleTargetAbsolute(-85);
  //  pros::delay(500);
  //  flap_forward.set_value(false);
  //  setMoveTargetDistance(-17.5);
  //  pros::delay(1000);
  //  setAngleTargetAbsolute(-147);
  //  pros::delay(1250);
  //  setMoveTargetDistance(-78);
  //  pros::delay(1300);
  //  setAngleTargetAbsolute(-225);
  //  pros::delay(600);
  ////  setMoveTargetDistance(20);
  //  pros::delay(700);
  //  flap_backward.set_value(true);
  //  setMoveTargetDistance(-21);
  //  pros::delay(900);
  //  flap_backward.set_value(false);
  //  pros::delay(200);
  //  setAngleTargetAbsolute(-260);
  //  pros::delay(800);
  ////  setMoveTargetDistance(-20);
   // pros::delay(800);
   // setAngleTargetAbsolute(-275);
  ////  pros::delay(300);
  //  fourBarMotorLeft.move(127);
   // fourBarMotorRight.move(-127);
  //  setMoveTargetDistance(-33.5);
  //  pros::delay(500);
  //  fourBarMotorLeft.brake();
  //  fourBarMotorRight.brake();
  //  flap_backward.set_value(true);
//}

//oid far_awp(){
   // setMoveTargetDistance(37);
   //// pros::delay(750);
   // setAngleTargetAbsolute(-38.0);
   //// pros::delay(300);
  //  setMoveTargetDistance(32.0);
  //  pros::delay(1000);
  //  setMoveTargetDistance(-28);
 //  pros::delay(1050);
 //  setAngleTargetAbsolute(0);
 //   pros::delay(300);
 //   flap_backward.set_value(true);
 //   setMoveTargetDistance(-33);
 ////   pros::delay(1000);
  //  flap_backward.set_value(false);
  //  pros::delay(300);
  //  setAngleTargetAbsolute(-75.0);
  //  pros::delay(1000);
 //   setMoveTargetDistance(50);
  //  pros::delay(1000); 
  //  setAngleTargetAbsolute(-122.5);
  //  intakeMotor.move(-127);
 //   pros::delay(400);
 //   setMoveTargetDistance(33);
 //   pros::delay(800);
 //   intakeMotor.move(0);
 //   setMoveTargetDistance(-15);
 //   pros::delay(500);
 //   setAngleTargetAbsolute(-45);
  //  pros::delay(400);
  //  setMoveTargetDistance(25);
  //  pros::delay(800);
  //  setAngleTargetAbsolute(32);
  //  pros::delay(500);
  //  setMoveTargetDistance(40);
 //   pros::delay(900);
 //   setMoveTargetDistance(-30);
 //   pros::delay(900);
    //setAngleTargetAbsolute(-19.5);
   // pros::delay(500);
   // setMoveTargetDistance(-53);
   // pros::delay(1600);
  // flap_backward.set_value(true);
   // setAngleTargetAbsolute(-75);
//}

//void close_awp() {
  ////  setMoveTargetDistance(35);
 //  pros::delay(1000);
 //   setAngleTargetAbsolute(0);
 //   pros::delay(1000);
 //  flap_backward.set_value(true);
 //   setMoveTargetDistance(-25);
 //   pros::delay(1000);
 //   flap_backward.set_value(false);
 //   pros::delay(1000);
  //  setAngleTargetAbsolute(-45);
  //  pros::delay(1000);
  //  setMoveTargetDistance(-45);
  //  pros::delay(1000);
  //  setAngleTargetAbsolute(-55);
  //  pros::delay(250);
  //  setMoveTargetDistance(-20);
  //  pros::delay(1000);
  //  flap_backward.set_value(true);
//}

//void prog() {

//}

/**
 * Returns absolute value of the difference between two angles (in degrees)
*/
//double angleDifference(double angle1, double angle2) {
    //double diff =  fmod(round((angle2-angle1+180.0)),360) -180.0;
    //return diff < -180.0 ? diff + 360.0 : diff;
//}

//oid setFourBarPosition(int encoderUnits) {
 //  targetFourBar = encoderUnits;
//}

//void setMoveTargetDistance(double distance){
 //   double encoderUnits = ((360.0 * distance) / (WHEEL_DIAMETER * PI)) * (5.0/6.0);
   // targetMove += encoderUnits;
  //  autoDriveState = 0;
//}

//void setMoveTargetUnits(int encoderUnits) {
  //  targetMove = position + encoderUnits;
  ////  autoDriveState = 0;
//}

//oid setAngleTargetRelative(double degrees) {
  //  targetAngle += degrees;
 //   autoDriveState = 1;
//}

//void setAngleTargetAbsolute(double degrees) {
  //  targetAngle = degrees;
  //  autoDriveState = 1;
//}

//void wait(int percentComplete) {

    // Delay robot until it has traveled % of targetDistance
   // if (autoDriveState == 0){
   //     while (abs(targetMove - position) >= (abs(targetMove) * (100 - percentComplete) / 100.0)) 
   //         pros::delay(10);
   // }
    // Delay robot until it has turned % of target angle
   // else if (autoDriveState == 1) {
   //    while (abs(angleDifference(orientation, targetAngle)) >= (abs(angleDifference(previousOrientation, targetAngle)) * (100 - percentComplete) / 100.0))
   //         pros::delay(10);
   // }
//
