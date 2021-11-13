#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"

//*************BLUE AUTONOMOUS PROGRAMS********************//

void blueLeft(std::shared_ptr<okapi::AsyncMotionProfileController> profileController)
{

  twoBarController->setTarget(-3000);
  move(profileController, 6_ft, false);
  fourBarController->setTarget(-4700);
  clawController->setTarget(-120);
  move(profileController, 3_ft, true);
  turn(90.0);
  move(profileController, 2_ft, true);
  twoBarController->setTarget(-1400);
  intakeMotor.moveRelative(100, 100);
}
void blueRight(std::shared_ptr<okapi::AsyncMotionProfileController> profileController)
{
  twoBarController->setTarget(-3000);
  move(profileController, 6_ft, false);
  fourBarController->setTarget(-4700);
  clawController->setTarget(-120);
  move(profileController, 3_ft, true);
}