#include "main.h"
#include "pros/rtos.hpp"

/** Helper Functions */

void intakeRing() { intake.move(intakeSpeed);  }
void outtakeRing(){ intake.move(-intakeSpeed); }
void stopIntake() { intake.brake();                     }
void intakeDrop() {  intakePiston.set_value(0);         }

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
    intakeDrop();
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


    chassis.moveToPoint(-14, -37, 3500,{.maxSpeed=100,.minSpeed=60,.earlyExitRange=4},false);
    // chassis.moveToPose(-6, -37, 116, 2500,{.minSpeed=60},false);
    doinkerDown();

    chassis.moveToPoint(-24, -24, 1750,{.forwards=false},false);
    doinkerUp();
    pros::delay(150);
    intakeDrop();
    pros::delay(500);

    chassis.turnToHeading(270,1250);

    chassis.turnToPoint(-12, -24,750,{.forwards=false});
    chassis.moveToPoint(-12, -24, 1250,{.forwards=false,.maxSpeed=80},false);

    chassis.turnToPoint(-12, -55,750,{.forwards=false});
    chassis.moveToPoint(-12, -55, 1750,{.forwards=false,.maxSpeed=80},false);
    pros::delay(500);
    clampDown();

    pros::delay(500);

    chassis.turnToPoint(-12, -32, 1250,{.forwards=false,.maxSpeed=80});
    chassis.moveToPoint(-12, -32, 2000,{.forwards=false,.minSpeed=100},false);

    intakeRing();

    pros::delay(750);

    chassis.turnToPoint(-21, -60, 750);
    chassis.moveToPoint(-21, -60, 2500,{.maxSpeed=60});

    pros::delay(750);

    chassis.turnToPoint(-2.5, -60, 1250);
    chassis.moveToPoint(-2.5, -60, 2000,{.maxSpeed=60});

    pros::delay(1250);

    // chassis.turnToHeading(270,750);
    // chassis.turnToPoint(float x, float y, int timeout)
    chassis.moveToPoint(-24, -48, 1750,{.forwards=false});

    chassis.turnToPoint(-48,-48,1250);
    chassis.moveToPoint(-48, -48, 1750);

    chassis.turnToPoint(-60, -60, 750,{.forwards=false});
    chassis.moveToPoint(-60, -60, 1750,{.forwards=false},false);


    pros::delay(1000);
    stopIntake();





}