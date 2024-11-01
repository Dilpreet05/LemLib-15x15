#include "pros/adi.h"
#include "pros/adi.hpp"

inline pros::adi::DigitalOut clampPiston('A',1);
inline short status = 0;

void clampControl();