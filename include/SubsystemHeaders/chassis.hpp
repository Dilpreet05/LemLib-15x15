#include "api.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/adi.hpp"
#include "pros/rotation.hpp"

/** Everything needed for our lemlib template is located here */

extern lemlib::Chassis chassis;
extern lemlib::ControllerSettings angularController;
extern lemlib::ControllerSettings lateralController;
extern lemlib::OdomSensors sensors;
extern lemlib::TrackingWheel horizontalTrackingWheel;
extern lemlib::TrackingWheel verticalTrackingWheel;
extern pros::Rotation horizontalTrackingWheelSensor;
extern pros::adi::Encoder verticalTrackingWheelSensor;
extern pros::Imu IMU;
extern lemlib::Drivetrain DRIVETRAIN;

/** These are our left and right drive train ports */
extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;
