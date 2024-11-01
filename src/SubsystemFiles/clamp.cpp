#include "main.h"



void clampControl(){
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)){
        clampPiston.set_value(status);
        status=!status;
    }
}