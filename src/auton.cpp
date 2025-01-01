#include "main.h"
#include "pros/rtos.hpp"
#include <cmath>
#include <ctime>

/** Helper Functions */

void intakeRing() { intake.move(intakeSpeed);  }
void outtakeRing(){ intake.move(-intakeSpeed); }
void stopIntake() { intake.brake();                     }
void pivotIntake(){ 
    intakePivotStatus=!intakePivotStatus;
    intakePivotPistons.set_value(intakePivotStatus);
}

void doinkerDown(){ doinkerPiston.set_value(1);}
void doinkerUp(){   doinkerPiston.set_value(0);}

void clampDown() { 
    clamp_is_extended=true;
    clampPiston.set_value(1); 
}
void clampUp()   { 
    clamp_is_extended=false;
    clampPiston.set_value(0); 
}


void moveStakeTo(int position){ 

    targetPose = position;
    
}


/** timeout in milliseconds */
void waitUntilRingInIntake(int timeout){
    double time = pros::millis();
    double target = time + timeout;
    while(intakeDistanceSensor.get_distance()>50 && time < target){ 
        pros::delay(5);
    }
}

/** Helper Functions End */


/** PID Tuning Functions */

// tune kP and kD
void tuneAngularPID()
{
    chassis.setPose(0, 0, 0);
    chassis.turnToHeading(90, 10000);
}

void tuneLinearPID()
{
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 48, 10000);
}

/** PID Tuning Functions End */


/** Autonomous Functions */

    void skills(){}
    void blueNegSide(){}
    void redPosSide(){}

/** Autonomous Functions End */