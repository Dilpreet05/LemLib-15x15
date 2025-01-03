#include "main.h"
#include "pros/misc.h"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	console.focus();

   	console.println("Initializing robot...");
    chassis.calibrate(); // calibrate sensors

	console.println("Done.");

	selector.focus();
    setAllBrakes();
	stakeMotors.tare_position();
	stakeRotation.reset_position();

	stakeStateMachine.suspend();


    pros::Task screenTask([&]() {
        while (true) {
            // print robot location to the brain screen
			console.printf("X: %f\n", chassis.getPose().x);
			console.printf("Y: %f\n",chassis.getPose().y);
			console.printf("Theta: %f\n", chassis.getPose().theta);

            // console.printf("Vertical Tracking Wheel (AMT): %d\n",verticalTrackingWheelSensor.get_value());
            // console.printf("Horizontal tracking Wheel: %d\n",horizontalTrackingWheelSensor.get_angle());

			console.printf("Stake_Angle: %f\n", stakeRotation.get_angle()/100.0);
			console.printf("Color: %lf\n", intakeColorSensor.get_hue());
			console.printf("Distance: %d\n", intakeDistanceSensor.get_distance());
			console.printf("isLoaded: %d\n", isLoaded);
			console.printf("isStuck: %d\n", isStuck);

			master.print(0, 0, "%f", stakeRotation.get_angle()/100.0);
			// console.printf("distanceSensor reading: %f\n", getDistance());
			// console.printf("Autoclamp boolean: %s\n", (autoclamp_active) ? "true": "false");
			// console.printf("clamp piston value: %d\n", clamp_is_extended);
			// console.printf("limit_switch: %d\n",autoClampSwitch.get_value());



            // log position telemetry
            lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());

            // delay to save resources
            pros::delay(50);
			console.clear();
        }
    });



}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {	selector.focus();}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

	console.println("Running auton...");
	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
	chassis.setPose(0,0,0);
	stakeMotors.tare_position();
	colorSorting.resume();


	console.focus();

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	colorSorting.suspend();

	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);

	while (true) {

		chassis.arcade(master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));
		intakeControl();
        stakeControl();
		doinkerControl();
		clampControl();

        pros::delay(20);
	}
}