#include "main.h"
#include "pros/misc.h"

void doinkerControl(){
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
        doinker_is_extended = !doinker_is_extended;
        doinkerPiston.set_value(doinker_is_extended);
    }
}