#include "main.h"
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"


void setIntakeBrakes(){

    intake.set_brake_mode(pros::MotorBrake::coast);

}

void intakeControl(){

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        intake.move(intakeSpeed);
    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        intake.move(-intakeSpeed);
    }else{
        intake.brake();
    }

}
