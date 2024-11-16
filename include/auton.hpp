#include "api.h"

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
// 1 represents red, -1 represents blue
inline pros::Optical colorSensor(1);

inline int teamColor = 0;
inline pros::Task colorSorting{[]{

    colorSensor.set_led_pwm(100);

    while(true){

        if(teamColor==1){

            // if(colorSensor.get_hue() > ){

            // }

        }else if(teamColor==-1){

            if(colorSensor.get_hue()<30){
                
            }

        }

        pros::delay(20);
    }

}};