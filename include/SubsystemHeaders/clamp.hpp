#include "api.h" 
#include "pros/adi.hpp"
// inline pros::adi::Pneumatics clampPiston('E',0);
inline pros::adi::DigitalOut clampPiston('C',0);
inline int clamp_is_extended = 0;

void clampControl();