#include "main.h" // IWYU pragma: keep
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"
#include "pros/motors.h" // IWYU pragma: keep



float targetErrorRange = 7;

void stakeControl(){


    currPose = stakeRotation.get_angle()/100.0;


    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){

        targetPose = 175;


    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){

        targetPose=35;


    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){

        targetPose = 10;


    }else{
        
        stakeMotors.brake();


    }

}

void setStakeBrake(){

    stakeMotors.set_brake_mode(pros::MotorBrake::hold);

}

pros::Task stakeStateMachine([]{

    currPose = stakeRotation.get_angle()/100.0;

    while(true){
        if(!(stakeRotation.get_angle() < targetPose + targetErrorRange && stakeRotation.get_angle() > targetPose)){
            power = stake_pid.update(targetPose-currPose);
            stakeMotors.move(power);
        }else{
            stakeMotors.brake();
        }

        pros::delay(20);
    }

});