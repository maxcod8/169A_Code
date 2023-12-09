#pragma once
#include "main.h"
#include "globals.hpp"

void handle_flaps(bool &flapForwardState, bool &flapBackwardState);
void handle_intake(int &intakeState);
void handle_four_bar();
void handle_catapult(bool &cataState);
void hold();