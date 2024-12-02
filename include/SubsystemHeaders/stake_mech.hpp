#include "api.h" // IWYU pragma: keep
#include "pros/motor_group.hpp"

// inline pros::Motor stakeMotorRight(13,pros::MotorGearset::red,pros::v5::MotorUnits::degrees);
// inline pros::Motor stakeMotorLeft(14,pros::MotorGearset::red,pros::v5::MotorUnits::degrees);
inline pros::MotorGroup stakeMotors({1},pros::MotorGearset::green,pros::v5::MotorUnits::degrees);
inline pros::Rotation stakeRotation(9);

void stakeControl();
void setStakeBrake();