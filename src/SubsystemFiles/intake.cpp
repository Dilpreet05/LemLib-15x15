#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"

pros::Motor flexWheelIntakeMotor(0, pros::MotorGearset::green, pros::v5::MotorUnits::degrees);
pros::Motor hookIntakeMotor(0, pros::MotorGearset::green, pros::v5::MotorUnits::degrees);

int hookSpeed=127;

void setIntakeBrakes(){

    flexWheelIntakeMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    hookIntakeMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

}

void intakeControl(){

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        flexWheelIntakeMotor.move(127);
        hookIntakeMotor.move(hookSpeed);
    }else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        flexWheelIntakeMotor.move(-127);
        hookIntakeMotor.move(-hookSpeed);
    }else{
        flexWheelIntakeMotor.brake();
        hookIntakeMotor.brake();
    }

}
