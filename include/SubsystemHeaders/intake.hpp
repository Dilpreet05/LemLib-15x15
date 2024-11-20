#include "api.h" // IWYU pragma: keep
#include "pros/motor_group.hpp"

inline int intakeSpeed = 127;

// inline pros::Motor flexWheelIntakeMotor(117, pros::MotorGearset::green, pros::v5::MotorUnits::degrees);
inline pros::Motor hookIntakeMotor(18, pros::MotorGearset::blue, pros::v5::MotorUnits::degrees);
inline pros::MotorGroup intake({17,18},pros::MotorGearset::green,pros::v5::MotorUnits::degrees);


void setIntakeBrakes();
void intakeControl();

inline pros::Optical colorSensor(20);

inline int sortColor = 0;
extern pros::Task colorSorting;