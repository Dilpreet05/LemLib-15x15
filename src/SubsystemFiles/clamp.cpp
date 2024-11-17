#include "main.h"
#include "pros/misc.h"



void clampControl(){
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)){
        clampPiston.set_value(!clampPiston.is_extended());
    }
}

void toggleAutoClamp(){
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
        autoclamp.notify(); 
    }
}

pros::Task autoclamp{[] {
    while (true) {

        if (pros::Task::current().notify_take(true, 20)) {
            autoclamp_active = !autoclamp_active;
        }

        if (autoclamp_active) {
            if (!clampPiston.is_extended() && autoClampSwitch.get_new_press()) {
                clampPiston.set_value(1);
            }
        }
    }
}};