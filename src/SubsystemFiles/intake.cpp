#include "main.h"
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"


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

pros::Task colorSorting{[]{

    colorSensor.set_led_pwm(100);

    while(true){
            if(sortColor==1){
                if(hookIntakeMotor.get_actual_velocity() > 50 && ((colorSensor.get_hue()>5 && colorSensor.get_hue()<30) ||  (hookIntakeMotor.get_current_draw() > 2100))){

                    pros::delay(375);
                    hookIntakeMotor.move(-intakeSpeed);
                    pros::delay(125);
                    hookIntakeMotor.move(intakeSpeed);
                    
                }                
            }else if(sortColor==-1){
                if(((hookIntakeMotor.get_actual_velocity() > 50 && colorSensor.get_hue()>185 && colorSensor.get_hue()<215) || (hookIntakeMotor.get_current_draw() > 2100) && hookIntakeMotor.get_actual_velocity() < 30)){

                    pros::delay(325);
                    hookIntakeMotor.move(-intakeSpeed);
                    pros::delay(125);
                    hookIntakeMotor.move(intakeSpeed);
                    
                }
            }

        pros::delay(20);

    }

}};