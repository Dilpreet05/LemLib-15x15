#include "main.h"
#include "pros/motors.h"
#include "robodash/views/selector.hpp"

void setAllBrakes(){
    setStakeBrake();
    setIntakeBrakes();
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
}

rd::Selector selector({

 {"Red", &redPosSide},
 {"Blue",	&blueNegSide},
 {"Skills", &skills},
 {"Intake Only", &intakeRing},
    
    
    
});