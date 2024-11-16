#include "api.h" // IWYU pragma: keep

inline pros::adi::DigitalOut doinkerPiston('B',0);
inline short doinkerStatus = 0;

void doinkerControl();