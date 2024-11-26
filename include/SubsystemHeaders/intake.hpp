#include "api.h" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/motor_group.hpp"

inline int intakeSpeed = 127;

// inline pros::Motor flexWheelIntakeMotor(117, pros::MotorGearset::green, pros::v5::MotorUnits::degrees);
inline pros::Motor hookIntakeMotor(18, pros::MotorGearset::blue, pros::v5::MotorUnits::degrees);
inline pros::MotorGroup intake({17,18},pros::MotorGearset::green,pros::v5::MotorUnits::degrees);


void setIntakeBrakes();
void intakeControl();

inline pros::Optical intakeColorSensor(20);
inline pros::Distance intakeDistanceSensor(0);
inline pros::adi::DigitalOut intakePiston('D',1);

inline int sortColor = 0;
inline bool isLoaded = false;
inline bool isStuck = false;
extern pros::Task colorSorting;