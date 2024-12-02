#include "api.h" // IWYU pragma: keep
#include "pros/adi.hpp"

// inline pros::adi::Pneumatics doinkerPiston('C',0);
inline pros::adi::DigitalOut doinkerPiston('D',0);
inline int doinker_is_extended = 0;

void doinkerControl();