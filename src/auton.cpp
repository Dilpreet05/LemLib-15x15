#include "main.h"

/** Helper Functions */

void intakeRing() { intake.move(intakeSpeed);  }
void outtakeRing(){ intake.move(-intakeSpeed); }
void stopIntake() { intake.brake();                     }

void doinkerDown(){}
void doinkerUp(){}

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