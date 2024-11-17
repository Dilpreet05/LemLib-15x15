#include "main.h" // IWYU pragma: keep
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"
#include "pros/motors.h" // IWYU pragma: keep



void stakeControl(){

    // if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){

    //     stakeMotorRight.move(127);
    //     stakeMotorLeft.move(-127);

    // }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){

    //     stakeMotorRight.move(-127);
    //     stakeMotorLeft.move(127);

    // }else{
        
    //     stakeMotorRight.brake();
    //     stakeMotorLeft.brake();

    // }
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){

        stakeMotors.move(127);

    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){

        stakeMotors.move(-127);

    }else{
        
        stakeMotors.brake();

    }

}

void setStakeBrake(){

    stakeMotors.set_brake_mode(pros::MotorBrake::hold);

}