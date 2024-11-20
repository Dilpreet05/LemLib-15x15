#include "api.h" // IWYU pragma: keep
#include "robodash/api.h"  // IWYU pragma: keep
#include "pros/misc.h"
// #include "main.h"


inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline rd::Console console;
extern rd::Selector selector;

void setAllBrakes();
