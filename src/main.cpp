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
    bool fourBarState = true;
    bool cataState = false;
    int intakeState = 0;

    while(true){
        double left = -controller.get_analog(ANALOG_LEFT_Y);
		double right = controller.get_analog(ANALOG_RIGHT_Y);

        leftWheelsFront.move(left);
        leftWheelsBack.move(left);  
        rightWheelsFront.move(right);  
        rightWheelsBack.move(right);

        pros::lcd::print(2, "intake: %d", intakeState);
        pros::lcd::print(3, "flaps: %s", flapState ? "true" : "false");
        pros::lcd::print(4, "fourbar: %s", fourBarState ? "true" : "false");
        pros::lcd::print(5, "catapult: %s", cataState ? "true" : "false");

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
    if (controller.get_digital_new_press(INTAKE_FOWARD_TOGGLE_BUTTON)){
        intakeState += 1;
    }
    if (controller.get_digital_new_press(INTAKE_BACKWARD_TOGGLE_BUTTON))
        intakeState -= 1;

    if (intakeState > 1 || intakeState < -1)
        intakeState = 0;

    double rotationValue = -intakeState * 127;
    intakeMotor.move(rotationValue);
}
 
void handle_four_bar(bool &fourBarState){
    double rotationAmount = 2225;
    if (controller.get_digital_new_press(FOUR_BAR_TOGGLE_BUTTON)){
        fourBarMotor.move_relative(fourBarState ? -rotationAmount : rotationAmount, 1000);
        fourBarState = !fourBarState;
    }
}

void handle_catapult(bool &cataState){
    if (controller.get_digital_new_press(CATAPULT_TOGGLE_BUTTON))
        cataState = !cataState;
    
    if (cataState)
        cataMotor.move(127);
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