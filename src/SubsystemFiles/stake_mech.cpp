#include "main.h" // IWYU pragma: keep
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"
#include "pros/motors.h" // IWYU pragma: keep

lemlib::PID stake_pid(
    1.75,
    0.0,
    7.5,
    0,
    true
);
double currPose;
double power;
double targetPose;

float targetErrorRange = 3;

void stakeControl(){


    currPose = stakeRotation.get_angle()/100.0;


    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){

        targetPose = 175;
        if(!(stakeRotation.get_angle() < targetPose + targetErrorRange && stakeRotation.get_angle() > targetPose - targetErrorRange)){
            power = stake_pid.update(targetPose-currPose);
            stakeMotors.move(power);
        }


    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){

        targetPose=33;
        if(!(stakeRotation.get_angle() < targetPose + targetErrorRange && stakeRotation.get_angle() > targetPose - targetErrorRange)){
            power = stake_pid.update(targetPose-currPose);
            stakeMotors.move(power);
        }


    }else{
        
        power = 0;
        stakeMotors.brake();

    }

}

void setStakeBrake(){

    stakeMotors.set_brake_mode(pros::MotorBrake::hold);

}