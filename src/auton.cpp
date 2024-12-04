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

void blueNegSide(){
    sortColor=1;
    chassis.setPose(54,31,270);


    chassis.moveToPoint(14, 37, 3500,{.maxSpeed=100,.minSpeed=60,.earlyExitRange=4},false);
    // chassis.moveToPose(-6, -37, 116, 2500,{.minSpeed=60},false);
    doinkerDown();

    chassis.moveToPoint(24, 24, 1750,{.forwards=false},false);
    doinkerUp();

    pros::delay(250);

    chassis.turnToHeading(90,1250);

    // chassis.moveToPose(-12, -45, 0, 2000,{.forwards=false,.lead=.7,.maxSpeed=80},false);
    // chassis.moveToPoint(-12, -45, 1250,{.forwards=false,.maxSpeed=40},false);
    chassis.turnToPoint(12, 24,750,{.forwards=false});
    chassis.moveToPoint(12, 24, 1250,{.forwards=false,.maxSpeed=80},false);



    chassis.turnToPoint(12, 55,750,{.forwards=false});
    chassis.moveToPoint(12, 55, 1750,{.forwards=false,.maxSpeed=80},false);
    // chassis.turnToHeading(0, 600);
    // chassis.moveToPoint(-12, -50, 1250,{.forwards=false,.maxSpeed=40},false);
    pros::delay(500);
    clampDown();
    pivotIntake();
    pros::delay(500);

    chassis.turnToPoint(12, 32, 1250,{.forwards=false,.maxSpeed=80});
    chassis.moveToPoint(12, 32, 2000,{.forwards=false,.minSpeed=100},false);

    intakeRing();

    pros::delay(750);

    chassis.turnToPoint(21, 60, 750);
    chassis.moveToPoint(21, 60, 2500,{.maxSpeed=60});

    pros::delay(750);

    chassis.turnToPoint(2.5, 60, 1250);
    chassis.moveToPoint(2.5, 60, 2000,{.maxSpeed=60});

    pros::delay(1250);


    chassis.moveToPoint(24, 48, 1750,{.forwards=false});

    chassis.turnToPoint(48,48,1250);
    chassis.moveToPoint(48, 48, 1750);

    // chassis.turnToPoint(60, 60, 750,{.forwards=false});
    // chassis.moveToPoint(60, 60, 1750,{.forwards=false},false);


    pros::delay(1000);
    stopIntake();
}

void redPosSide(){
    sortColor=-1;
    chassis.setPose(-54,-31,90);


    chassis.moveToPoint(-17, -36, 3500,{.maxSpeed=100,.minSpeed=60,.earlyExitRange=4},false);
    doinkerDown();
    pros::delay(150); // lets goal settle

    chassis.moveToPoint(-24, -24, 1750,{.forwards=false,.maxSpeed=70},false);
    pros::delay(150);
    doinkerUp();
    outtakeRing();
    pros::delay(400);
    stakeMotors.move_absolute(360, 70);
    stopIntake();
    pivotIntake();
    pros::delay(500);


    // chassis.turnToHeading(270, 1250);
    chassis.turnToPoint(-18, -24, 1750);
    chassis.moveToPoint(-18,-24,1750,{.maxSpeed=70});

    // chassis.turnToHeading(0, 1250);
    chassis.turnToPoint(-18, -40, 1250,{.forwards=false});
    chassis.moveToPoint(-18, -40, 2500,{.forwards=false,.minSpeed=70},false);
    clampDown();
    pros::delay(250);

    chassis.moveToPoint(-16, -30, 1750);

    chassis.turnToPoint(-30, -48, 1750);
    chassis.moveToPoint(-30, -48, 2500,{.maxSpeed=70});
    intakeRing();
    pros::delay(1750);


    chassis.moveToPose(-28, -60, 180,2500,{.lead=.6,.maxSpeed=50});
    pros::delay(1750);

    chassis.moveToPoint(-32, -55, 1750,{.forwards=false,.maxSpeed=70});
    chassis.turnToPoint(0, -55, 1750);
    chassis.moveToPoint(-9, -55, 2500,{.maxSpeed=70});
    pros::delay(1750);


    chassis.moveToPose(-24, -24, 180, 2500,{.forwards=false,.lead=.3,.minSpeed=70});

    chassis.moveToPoint(-48, -48, 2500,{.maxSpeed=70});
    pros::delay(1750);

    chassis.moveToPoint(-30,-30,1750,{.forwards=false,.maxSpeed=70});

    chassis.moveToPose(-60, -35, 270, 2500,{.lead=.2,.maxSpeed=70});
    pros::delay(1250);

    chassis.moveToPoint(-48, -48, 1750,{.forwards=false,.maxSpeed=70});


    stopIntake();


}


void skills(){

    sortColor = -1; // sort out blue rings

    /** Set robot skills starting position */
    chassis.setPose(-56,-16.5,90);
    
    /** Drop intake */
    outtakeRing();
    pros::delay(400);
    stopIntake();

    /** Pivot intake to allow us to score on mobile goals & alliance stakes */
    pivotIntake();
    pros::delay(500);

    /** Intake the ring @ (-48,0) */

    chassis.turnToPoint(-48, 0, 1250,{.maxSpeed=70});
    chassis.moveToPoint(-48, 2, 1750,{.maxSpeed=70});
    intakeRing();
    // while(intakeDistanceSensor.get()>50){pros::delay(5);} // wait until the ring reaches the top of the intake
    waitUntilRingInIntake(2500);
    stopIntake();

    // doinkerDown();
    // pros::delay(500);
    // doinkerUp();
    // pros::delay(500);


    /** Drive to MOGO and grab */
    // chassis.moveToPoint(-50, 0, 1250); // avoid hitting the back wall
    chassis.turnToPoint(-48, -35, 1250,{.forwards=false});
    chassis.moveToPoint(-48, -35, 2500,{.forwards=false,.maxSpeed=70});
    stakeMotors.move_absolute(360, 70);    

    chassis.turnToPoint(-24, -48, 750,{.forwards=false});
    chassis.moveToPoint(-24, -48, 2500,{.forwards=false,.maxSpeed=70},false);
    clampDown();
    pros::delay(250);


    // /** Score 5 rings */

    chassis.turnToPoint(0, -41, 1000);
    chassis.moveToPoint(0, -41, 1750,{.maxSpeed=70});
    intakeRing();
    pros::delay(1750);

    
    chassis.moveToPoint(-15, -42, 1750,{.forwards=false,.maxSpeed=70});

    chassis.turnToPoint(0, -58, 750);
    chassis.moveToPoint(0, -58, 1750,{.maxSpeed=70});
    pros::delay(1750);

    chassis.moveToPoint(-15, -42, 1750,{.forwards=false,.maxSpeed=70});


    chassis.turnToPoint(-24, -20, 750);
    chassis.moveToPoint(-24, -20, 1750,{.maxSpeed=70});
    waitUntilRingInIntake(1750);
    stopIntake();

    chassis.turnToPoint(-48, -44, 1250);
    chassis.moveToPoint(-48, -44, 2500,{.maxSpeed=70});
    intakeRing();
    pros::delay(1750);

    chassis.moveToPoint(-62, -57, 1750,{.maxSpeed=70});
    pros::delay(1750);

    chassis.moveToPoint(-48, -44, 1750,{.forwards=false,.maxSpeed=70});

    chassis.turnToPoint(-62, -57, 1250,{.forwards=false,.maxSpeed=70});
    chassis.moveToPoint(-62, -57, 1750,{.forwards=false,.maxSpeed=70},false);

    clampUp();
    chassis.moveToPoint(-48, -44, 1750,{.maxSpeed=70});     
    chassis.moveToPoint(-62, -57, 1750,{.forwards=false,.maxSpeed=70},false);
    chassis.moveToPoint(-48, -44, 1750,{.maxSpeed=70});     



}