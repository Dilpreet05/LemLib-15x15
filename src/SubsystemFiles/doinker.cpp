#include "main.h"
#include "pros/misc.h"

void doinkerControl(){
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
        doinkerPiston.set_value(doinkerPiston.is_extended());
    }
}