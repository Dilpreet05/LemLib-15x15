#include "main.h"
#include "pros/misc.h"



void clampControl(){
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)){
        clamp_is_extended = !clamp_is_extended;
        clampPiston.set_value(clamp_is_extended);
    }
}

// void toggleAutoClamp(){
//     if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
//         autoclamp.notify(); 
//     }
// }

// pros::Task autoclamp{[] {
//     while (true) {

//         if (pros::Task::current().notify_take(true, 20)) {
//             autoclamp_active = !autoclamp_active;
//         }

//         if (autoclamp_active) {
//             if (!clamp_is_extended && autoClampSwitch.get_new_press()==1) {
//                 // clampPiston.set_value(1);

//             }
//         }

//         pros::delay(50);
//     }
// }};