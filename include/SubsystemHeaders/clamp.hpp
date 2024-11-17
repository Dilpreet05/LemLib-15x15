#include "api.h" 
#include "pros/adi.hpp"
inline pros::adi::Pneumatics clampPiston('E',0);

void clampControl();
void toggleAutoClamp();

inline pros::adi::DigitalIn autoClampSwitch('A');
inline bool autoclamp_active = true;
extern pros::Task autoclamp;