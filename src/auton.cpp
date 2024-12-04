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


    chassis.moveToPoint(17, 36, 3500,{.maxSpeed=100,.minSpeed=60,.earlyExitRange=4},false);
    doinkerDown();
    pros::delay(150); // lets goal settle

    chassis.moveToPoint(24, 24, 1750,{.forwards=false,.maxSpeed=70},false);
    pros::delay(150);
    doinkerUp();
    outtakeRing();
    pros::delay(400);
    stakeMotors.move_absolute(360, 70);
    stopIntake();
    pivotIntake();
    pros::delay(500);


    chassis.turnToPoint(18, 24, 1750);
    chassis.moveToPoint(18,24,1750,{.maxSpeed=70});

    chassis.turnToPoint(18, 40, 1250,{.forwards=false});
    chassis.moveToPoint(18, 40, 2500,{.forwards=false,.minSpeed=70},false);
    clampDown();
    pros::delay(250);

    chassis.moveToPoint(16, 30, 1750);

    chassis.turnToPoint(30, 48, 1750);
    chassis.moveToPoint(30, 48, 2500,{.maxSpeed=70});
    intakeRing();
    pros::delay(1750);


    chassis.moveToPose(28, 60, 180,2500,{.lead=.6,.maxSpeed=50});
    pros::delay(1750);

    chassis.moveToPoint(32, 55, 1750,{.forwards=false,.maxSpeed=70});
    chassis.turnToPoint(0, 55, 1750);
    chassis.moveToPoint(9, 55, 2500,{.maxSpeed=70});
    pros::delay(1750);


    chassis.moveToPose(24, 24, 180, 2500,{.forwards=false,.lead=.3,.minSpeed=70});

    chassis.moveToPoint(48, 48, 2500,{.maxSpeed=70});
    pros::delay(1750);

    chassis.moveToPoint(30,30,1750,{.forwards=false,.maxSpeed=70});

    chassis.moveToPose(60, 35, 270, 2500,{.lead=.2,.maxSpeed=70});
    pros::delay(1250);

    chassis.moveToPoint(48, 48, 1750,{.forwards=false,.maxSpeed=70});


    stopIntake();

}

void redPosSide(){
    /** Most motions are limited in speed for consistancy reasons. 
     *  Our preload ring is not located in our robot and is instead placed behind our robot at position (-60,-35) approx.
     */

    // sort out blue rings
    sortColor=-1;

    /** Set global positioning for Odometry */
    chassis.setPose(-54,-31,90);

    /** Rush towards one of the centerline mobile goals and take possession of it using our doinker/MOGO stick */
    chassis.moveToPoint(-17, -36, 3500,{.maxSpeed=100,.minSpeed=60,.earlyExitRange=4},false);
    doinkerDown();
    pros::delay(150); // lets goal settle

    /** Drive backwards with the goal in our possession */
    chassis.moveToPoint(-24, -24, 1750,{.forwards=false,.maxSpeed=70},false);
    pros::delay(150); // wait a little bit before putting the stick down in order to avoid premature retration
    doinkerUp(); // retract doinker
    outtakeRing(); // reverse our intake so that our first stage of flex wheels drops down
    pros::delay(400); // wait for any energy transfered to the robot from the intake drop and doinker to dissipate

    /** Put up our wall stake mech so we can stack more rings onto our mobile goal */
    stakeMotors.move_absolute(360, 70); // moves our wall stake mech ~60deg
    stopIntake(); // stop the intake reversing since the flex wheels most likely already dropped
    pivotIntake(); // pivot our intake upwards to the scoring position
    pros::delay(500); // wait for any transfered energy to dissipate 

    /** Drive to a position that lines us up the the flat edge of the MOGO in the X-direction*/
    chassis.turnToPoint(-18, -24, 1750);
    chassis.moveToPoint(-18,-24,1750,{.maxSpeed=70});

    /** Drive into the MOGO and clamp by changing our Y-component of our movement input, this motion knocks over a ring stack */
    chassis.turnToPoint(-18, -40, 1250,{.forwards=false});
    chassis.moveToPoint(-18, -40, 2500,{.forwards=false,.minSpeed=70},false);
    clampDown(); // clamp goal
    pros::delay(250); // wait for goal to settle

    /** Move away from any rings to avoid any collateral damage to ring stacks when turning to intake*/
    chassis.moveToPoint(-16, -30, 1750); 

    /** Turn to and Intake rings at (-24,-48) that was moved to (-30,-38) since it was hit by our robot */
    chassis.turnToPoint(-30, -48, 1750);
    chassis.moveToPoint(-30, -48, 2500,{.maxSpeed=70});
    intakeRing(); // our color sorting is consistent to the point where it doesnt matter which ring we intake
                  // As long as we intake our color ring in the end, everything else is irrelevent.
                  // This step typically only intakes the blue ring which is flinged away in the end.
    pros::delay(1750); // wait for ring to intake

    /** intake the red ring that was knocked away using a curving motion. */
    chassis.moveToPose(-28, -60, 180,2500,{.lead=.6,.maxSpeed=50});
        // the curving motion above allows for more accuracy in movements and slower, smoother movements.
    pros::delay(1750); // wait for ring to intake

    /** Back up from previous position & Intake the ring stack at position (0,-60) */
    chassis.moveToPoint(-32, -55, 1750,{.forwards=false,.maxSpeed=70}); // back up to avoid htiting wall
    chassis.turnToPoint(0, -55, 1750);
    chassis.moveToPoint(-9, -55, 2500,{.maxSpeed=70}); // occationally misses the ring
    pros::delay(1750); // wait for ring to intake

    /** Reverse using a curving motion as to avoid hitting the walls */
    chassis.moveToPose(-24, -24, 180, 2500,{.forwards=false,.lead=.3,.minSpeed=70});

    /** Intake the ring at position (-48,-48) */
    chassis.moveToPoint(-48, -48, 2500,{.maxSpeed=70});
    pros::delay(1750); // wait for ring to intake

    /** Reverse slighty for better angle of attack on next step */
    chassis.moveToPoint(-30,-30,1750,{.forwards=false,.maxSpeed=70});

    /** Use a curving motion to intake our preload ring located at (-60,-35) */
    chassis.moveToPose(-60, -35, 270, 2500,{.lead=.2,.maxSpeed=70});
    pros::delay(1250);

    /** Drive backk to (-48,-48) */
    chassis.moveToPoint(-48, -48, 1750,{.forwards=false,.maxSpeed=70});


    stopIntake(); // prevent intake overuse


} // End red auton


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
    waitUntilRingInIntake(2500);
    stopIntake();



    /** Drive to MOGO and grab */
    // chassis.moveToPoint(-50, 0, 1250); // avoid hitting the back wall
    chassis.turnToPoint(-48, -35, 1250,{.forwards=false});
    chassis.moveToPoint(-48, -35, 2500,{.forwards=false,.maxSpeed=70});
    stakeMotors.move_absolute(360, 70);    

    chassis.turnToPoint(-24, -48, 750,{.forwards=false});
    chassis.moveToPoint(-24, -48, 2500,{.forwards=false,.maxSpeed=70},false);
    clampDown();
    pros::delay(250);


    /** Score 5 rings */
    // ring 1
    chassis.turnToPoint(0, -41, 1000);
    chassis.moveToPoint(0, -41, 1750,{.maxSpeed=70});
    intakeRing();
    pros::delay(1750);

    // reverse to avoid hitting other rings
    chassis.moveToPoint(-15, -42, 1750,{.forwards=false,.maxSpeed=70});

    // ring 2
    chassis.turnToPoint(0, -58, 750);
    chassis.moveToPoint(0, -58, 1750,{.maxSpeed=70});
    pros::delay(1750);

    // reverse to better align for next step
    chassis.moveToPoint(-15, -42, 1750,{.forwards=false,.maxSpeed=70});

    // ring 3
    chassis.turnToPoint(-24, -20, 750);
    chassis.moveToPoint(-24, -20, 1750,{.maxSpeed=70});
    waitUntilRingInIntake(1750);
    stopIntake();

    // ring 4
    chassis.turnToPoint(-48, -44, 1250);
    chassis.moveToPoint(-48, -44, 2500,{.maxSpeed=70});
    intakeRing();
    pros::delay(1750);

    // ring 5
    chassis.moveToPoint(-62, -57, 1750,{.maxSpeed=70});
    pros::delay(1750);


    /** Reverse to align the back of the robot with the corner and push MOGO into corner */
    chassis.moveToPoint(-48, -44, 1750,{.forwards=false,.maxSpeed=70});

    chassis.turnToPoint(-62, -57, 1250,{.forwards=false,.maxSpeed=70});
    chassis.moveToPoint(-62, -57, 1750,{.forwards=false,.maxSpeed=70},false);
    clampUp(); // release mogo

    /** Slam it into the corner a few times for good measure */
    chassis.moveToPoint(-48, -44, 1750,{.maxSpeed=70});     
    chassis.moveToPoint(-62, -57, 1750,{.forwards=false,.maxSpeed=70},false);
    chassis.moveToPoint(-48, -44, 1750,{.maxSpeed=70});     



}