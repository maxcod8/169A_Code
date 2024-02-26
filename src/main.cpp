#include "main.h"
#include "tasks.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	
	leftWheelsBack.tare_position();
    leftWheelsFront.tare_position();
	leftWheelsMiddle.tare_position();
    rightWheelsBack.tare_position();
    rightWheelsFront.tare_position();
    fourBarMotorLeft.tare_position();
    fourBarMotorRight.tare_position();

	fourBarMotorLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	fourBarMotorRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	
	//cataMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	
	//pros::Task taskMove(move);
	//pros::Task taskTurn(turn);
}


/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}