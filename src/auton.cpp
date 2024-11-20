#include "main.h"
#include "pros/rtos.hpp"

/** Helper Functions */

void intakeRing() { intake.move(intakeSpeed);  }
void outtakeRing(){ intake.move(-intakeSpeed); }
void stopIntake() { intake.brake();                     }

void doinkerDown(){ doinkerPiston.set_value(1);}
void doinkerUp(){   doinkerPiston.set_value(0);}

void clampDown() { clampPiston.set_value(1); }
void clampUp()   { clampPiston.set_value(0); }

void moveStakeTo(int position){ stakeMotors.move_absolute(position, 127); }
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
    sortColor = 1;
    chassis.setPose(54.5,31.5,270);

    chassis.moveToPoint(13, 34, 2500,{},false);
    // chassis.moveToPose(13, 35,290, 2500,{.lead=.3,.minSpeed=70,.earlyExitRange=10},false);
    doinkerDown();

    pros::delay(125);

    chassis.moveToPoint(30, 20, 1750,{.forwards=false},false);
    doinkerUp();

    pros::delay(125);
}

void redPosSide(){
    sortColor=-1;
    chassis.setPose(-54.5,-31.5,90);


    chassis.moveToPoint(-10.5, -36, 3500,{},false);
    doinkerDown();

    chassis.moveToPoint(-24, -24, 1750,{.forwards=false,.maxSpeed=101},false);
    doinkerUp();
    pros::delay(250);

    chassis.turnToHeading(270,1250);

    // chassis.moveToPose(-12, -45, 0, 2000,{.forwards=false,.lead=.7,.maxSpeed=80},false);
    chassis.moveToPoint(-12, -50, 1250,{.forwards=false,.maxSpeed=50},false);
    // chassis.turnToHeading(0, 600);
    // chassis.moveToPoint(-12, -50, 1250,{.forwards=false,.maxSpeed=40},false);
    clampDown();

    chassis.moveToPoint(-12, -24, 2000,{.minSpeed=100},false);

    intakeRing();

    // pros::delay(1250);

    // // chassis.turnToPoint(-12,-60, 750,{.forwards=false,.maxSpeed=80});
    // chassis.moveToPoint(-12, -60, 1750,{.forwards=false,.maxSpeed=60},false);
    // // chassis.turnToPoint(-4, -62, 1250,{},false);
    // // chassis.turnToHeading(90, 750);
    // // chassis.moveToPoint(-4,-62,1750);

    // pros::delay(1500);

    // chassis.turnToPoint(-48, -54, 750,{});
    // chassis.moveToPoint(-48, -54, 1750,{.maxSpeed=50},false);

    // pros::delay(1250);

    // chassis.turnToPoint(-3, -61, 1000);
    // chassis.moveToPoint(-0.75, -62, 3000,{.maxSpeed=60});

}