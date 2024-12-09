#include "api.h" // IWYU pragma: keep
#include "lemlib/pid.hpp"
#include "pros/motor_group.hpp"

extern lemlib::PID stake_pid;
extern float targetErrorRange;

// inline pros::Motor stakeMotorRight(13,pros::MotorGearset::red,pros::v5::MotorUnits::degrees);
// inline pros::Motor stakeMotorLeft(14,pros::MotorGearset::red,pros::v5::MotorUnits::degrees);
inline pros::MotorGroup stakeMotors({1},pros::MotorGearset::green,pros::v5::MotorUnits::degrees);
inline pros::Rotation stakeRotation(10);
inline double currPose;
inline double power;
inline double targetPose = 10;

void stakeControl();
void setStakeBrake();

extern pros::Task stakeStateMachine;
extern lemlib::PID stake_pid;