#include "main.h"
#include "pros/motors.h"

void setAllBrakes(){
    setStakeBrake();
    setIntakeBrakes();
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
}