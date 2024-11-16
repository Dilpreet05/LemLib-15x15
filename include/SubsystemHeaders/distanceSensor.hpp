#include "api.h" // IWYU pragma: keep
#include "pros/adi.hpp"

inline pros::adi::AnalogIn distanceSensor('A');

float getDistance();