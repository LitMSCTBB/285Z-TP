#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285z/initSensors.hpp"

//****************** SKILLS ***********************************//

  //move(fast, 12_ft, fwd); //12 ft = 6 ft real


void noAuton()
{
  pros::delay(15000);
}

void skillsAuto(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
  std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  turn(90);
  move(fast, 4_ft, fwd);
  clawPiston.set_value(true);
  move(fast, 4_ft, bwd);
  clawPiston.set_value(false);

  //getting 1 neutral
  //move(fast, 18_ft, fwd);
  // move(med, 3_ft, bwd);

}
