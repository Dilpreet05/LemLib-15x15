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

/** Functions Tasks for Autonomous */

void blueNegSide();
void redPosSide();