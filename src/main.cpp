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

	//pros::Task taskUpdateOdometry(updateOdometry);
	//pros::Task taskMoveTo(moveTo);
	//pros::Task taskTurnTo(turnTo);
  	//pros::Task taskLookAt(lookAt);
	//pros::Task taskStationaryCheck(stationaryCheck);
}

void opcontrol(){

    bool flapState = true;
    bool fourBarState = false;
    bool cataState = false;
    int intakeState = 0;

    while(true){
        double left = controller.get_analog(ANALOG_LEFT_Y);
		double right = -controller.get_analog(ANALOG_RIGHT_Y);

        leftWheelsFront.move(left);
        leftWheelsBack.move(left);  
        rightWheelsFront.move(right);  
        rightWheelsBack.move(right);

        handle_flaps(flapState);
        handle_intake(intakeState);
        handle_four_bar(fourBarState);
        handle_catapult(cataState);
                
        pros::delay(TASK_DELAY);
    }
}

void handle_flaps(bool &flapState){
    if (controller.get_digital_new_press(FLAP_TOGGLE_BUTTON)) 
        flapState = !flapState;
    piston.set_value(flapState);
}

void handle_intake(int &intakeState){
    if (controller.get_digital_new_press(INTAKE_FOWARD_TOGGLE_BUTTON))
        intakeState += 1;
    if (controller.get_digital_new_press(INTAKE_BACKWARD_TOGGLE_BUTTON))
        intakeState -= 1;

    if (intakeState > 1 || intakeState < 1)
        intakeState = 0;

    double rotationValue = intakeState * degrees_to_position(360);
    intakeMotor.move_relative(rotationValue, 600);
}

void handle_four_bar(bool &fourBarState){
    double rotationAmount = degrees_to_position(450);
    if (controller.get_digital_new_press(FOUR_BAR_TOGGLE_BUTTON))
        fourBarMotor.move_relative(fourBarState ? -rotationAmount : rotationAmount, 100);
}

void handle_catapult(bool &cataState){
    if (controller.get_digital_new_press(CATAPULT_TOGGLE_BUTTON))
        cataState = !cataState;
    
    if (cataState)
        cataMotor.move_relative(degrees_to_position(360), 100);
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