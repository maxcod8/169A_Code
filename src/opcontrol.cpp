#include "globals.h"

using namespace pros;

void opcontrol(){

    while(true){
        leftWheels.move(controller.get_analog(ANALOG_LEFT_Y));
        rightWheels.move(controller.get_analog(ANALOG_RIGHT_Y));

        delay(2);
    }
}