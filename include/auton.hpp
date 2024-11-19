#include "main.h"
#include "pros/misc.hpp"

/** Helper Functions */

void intakeRing();
void outtakeRing();
void stopIntake();

void doinkerDown();
void doinkerUp();

void clampDown();
void clampUp();

void moveStakeTo(int); // only to be used in tasks

/** Helper Functions End */

/** Autonomous Routines */

void skills();

void redRightSide();
void redLeftSide();

/** Autonomous Routines End */

/** PID Tuning Functions */

void tuneAngularPID();
void tuneAngularWindUp();
void tuneLinearPID();
void tuneLinearWindUp();

/** PID Tuning Functions End */

/** Tasks for Autonomous */
// 1 represents sort out red and -1 represents sort out blue
inline pros::Optical colorSensor(20);

inline int sortColor = 0;
inline pros::Task colorSorting{[]{

    colorSensor.set_led_pwm(100);

    while(true){

        if(pros::competition::is_autonomous()){
            if(sortColor==1){

                // if(colorSensor.get_hue() > ){

                // }

            }else if(sortColor==-1){

                if( colorSensor.get_hue()>250 && colorSensor.get_hue()<280){

                    pros::delay(250);
                    hookIntakeMotor.move(-intakeSpeed);
                    pros::delay(125);
                    hookIntakeMotor.move(intakeSpeed);
                    
                }

            }

        }else{

            if(sortColor==1){

                // if(colorSensor.get_hue() > ){

                // }

            }else if(sortColor==-1){

                if(hookIntakeMotor.get_actual_velocity() > 80 && colorSensor.get_hue()>250 && colorSensor.get_hue()<280){

                    pros::delay(250);
                    hookIntakeMotor.move(-intakeSpeed);
                    pros::delay(125);
                    hookIntakeMotor.move(intakeSpeed);
                    
                }

            }


        }
        
        pros::delay(20);

    }


}};