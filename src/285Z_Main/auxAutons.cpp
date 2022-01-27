#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285z/initSensors.hpp"

//****************** SKILLS ***********************************//

void noAuton()
{
  pros::delay(15000);
}

void skillsAuto(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
  std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  intakeMotor.moveVelocity(-600);
  move(fast, 0.3_ft, fwd);
  move(med, 0.3_ft, fwd);
  move(slow, 0.3_ft, fwd);
  intakeMotor.moveVelocity(0);
  turn(90);
  turn(180);
  turn(0);
}
