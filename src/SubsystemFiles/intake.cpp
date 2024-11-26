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

    intakeColorSensor.set_led_pwm(100);



    
    while(true){


        /* when the specified color */
        if(sortColor==1){

            isLoaded = (intakeColorSensor.get_hue()>5 && intakeColorSensor.get_hue()<30) ? true:false; /* if the ring is red, prepare to get rid of it */

        }else if(sortColor==-1){

            isLoaded = (intakeColorSensor.get_hue()>185 && intakeColorSensor.get_hue()<215) ? true:false; /*  if the ring is blue, prepare to get rid of it */

        }


        /* if the motors current draw is massive, it's probably stuck */
        if(hookIntakeMotor.get_current_draw()>2100){
            isStuck = true;
        }



        if((isLoaded && intakeDistanceSensor.get_distance() < 4) || isStuck){

            /* reverse intake for specified time. if intake is stuck then reverse for longer */
            intake.move(-intakeSpeed);
            pros::delay(125 * (isStuck*3));
            intake.move(intakeSpeed);

            /* reset */
            isStuck = false;
            isLoaded=false;
        }

        pros::delay(20);

    }


    
}};