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
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::Task taskUpdateOdometry(updateOdometry);
	//pros::Task taskMoveTo(moveTo);
	//pros::Task taskTurnTo(turnTo);
  	//pros::Task taskLookAt(lookAt);
	//pros::Task taskStationaryCheck(stationaryCheck);
}

void opcontrol(){

    while(true){
        double left = -controller.get_analog(ANALOG_LEFT_Y);
		double right = controller.get_analog(ANALOG_RIGHT_Y);

        leftWheelsOne.move(left);
        leftWheelsTwo.move(-left);
        rightWheelsOne.move(-right);
        rightWheelsTwo.move(right);
        
        pros::delay(TASK_DELAY);
    }
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