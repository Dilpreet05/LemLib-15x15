#include "main.h"
#include "pros/misc.h"



void clampControl(){
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)){
        clamp_is_extended = !clamp_is_extended;
        clampPiston.set_value(clamp_is_extended);
    }
}
