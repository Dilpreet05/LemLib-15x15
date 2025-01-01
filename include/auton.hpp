#include "api.h" // IWYU pragma: keep
#include "pros/misc.hpp" // IWYU pragma: keep

/** Helper Functions */

void intakeRing();
void outtakeRing();
void stopIntake();
void pivotIntake();

void doinkerDown();
void doinkerUp();

void clampDown();
void clampUp();

void waitUntilRingInIntake(int timeout);

/** Helper Functions End */

/** Autonomous Routines */

void skills();
void blueNegSide();
void redPosSide();

/** Autonomous Routines End */

/** PID Tuning Functions */

void tuneAngularPID();
void tuneAngularWindUp();
void tuneLinearPID();
void tuneLinearWindUp();

/** PID Tuning Functions End */
