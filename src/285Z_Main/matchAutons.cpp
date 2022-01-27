#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"


//***************************** RED/BLUE AUTONOMOUS PROGRAMS **********************//

void redLeftBlueLeft(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
  std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  /*
  chassisaut->turnAngle(-20_deg);
  twoBarController->setTarget(-3100);
  pros::delay(1500);
  move(profileController, 0.4_ft, bwd);
  pros::delay(1500);
  twoBarController->setTarget(-1495);
  pros::delay(1500);
  move(profileController, 0.35_ft, fwd);
  pros::delay(1500);
  intakeMotor.moveVoltage(9500);
  */

}
void redRightBlueRight(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
  std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  /*
  move(profileController, 2_ft, fwd);
  pros::delay(200);
  // move(profileController, 0.065_ft, fwd);
  clawController->setTarget(-820);
  twoBarController->setTarget(-3100);
  move(profileController, 1_ft, bwd);
  chassisaut->turnAngle(-130_deg);
  move(profileController, 0.33_ft, bwd);
  twoBarController->setTarget(-1495);
  pros::delay(200);
  move(profileController, 0.33_ft, fwd);
  intakeMotor.moveVoltage(9500);
  */
}

void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
  std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{



}
