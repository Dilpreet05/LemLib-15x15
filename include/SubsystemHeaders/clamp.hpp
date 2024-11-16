#include "api.h"
inline pros::adi::DigitalOut clampPiston('A',1);
inline short clampStatus = 1;

void clampControl();
void toggleAutoClamp();

inline bool autoclamp_active = true;
extern pros::Task autoclamp;