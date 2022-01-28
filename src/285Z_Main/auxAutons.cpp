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
  //neutral rush
  move(fast, 10.5_ft, fwd);
  clawPiston.set_value(true);
  move(fast, 5.5_ft, bwd);
  clawPiston.set_value(false);

  //facing alliance
  turn(270);
  liftDown();
  pros::delay(800);
  move(med, 3_ft, bwd);
  liftUp();

  //scoring on alliance
  intakeMotor.moveVelocity(600);
  pros::delay(3000);
  intakeMotor.moveVelocity(0);

}
