#include "api.h" // IWYU pragma: keep
#include "robodash/api.h"  // IWYU pragma: keep
#include "pros/misc.h"
#include "stormlib/api.hpp"
#include "stormlib/led.hpp"

inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline rd::Console console;
inline rd::Selector selector({


    {"Skills"},{"Red"},{"Blue"}
    
    
    
    });

inline stormlib::aRGB LED_Strip('C',32);
// inline stormlib::aRGB_manager LED_Manager(&LED_Strip,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr);
