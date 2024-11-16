#include "main.h"
#include "pros/misc.h"

void doinkerControl(){
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
        doinkerStatus=!doinkerStatus;
        doinkerPiston.set_value(doinkerStatus);
    }
}