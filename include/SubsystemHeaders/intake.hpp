#include "api.h" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/motor_group.hpp"

inline int intakeSpeed = 127;

// inline pros::Motor flexWheelIntakeMotor(17, pros::MotorGearset::green, pros::v5::MotorUnits::degrees);
inline pros::Motor hookIntakeMotor(0, pros::MotorGearset::blue, pros::v5::MotorUnits::degrees);
inline pros::MotorGroup intake({0,0},pros::MotorGearset::green,pros::v5::MotorUnits::degrees);


void setIntakeBrakes();
void intakeControl();

inline pros::Optical intakeColorSensor(0);
inline pros::Distance intakeDistanceSensor(0);
inline pros::adi::DigitalOut intakePivotPistons('E',LOW);
inline int intakePivotStatus = 0;

inline int sortColor = 0;
inline bool isLoaded = false;
inline bool isStuck = false;
extern pros::Task colorSorting;