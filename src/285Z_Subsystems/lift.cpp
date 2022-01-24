#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"
#include "../../include/285Z_Subsystems/lift.hpp"

std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarControllerLeft = AsyncPosControllerBuilder().withMotor(fourBarPortLeft).build();
std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarControllerRight = AsyncPosControllerBuilder().withMotor(fourBarPortRight).build();
std::shared_ptr<okapi::AsyncPositionController<double, double>> twoBarController = AsyncPosControllerBuilder().withMotor(twoBarPort).build();
std::shared_ptr<okapi::AsyncPositionController<double, double>> clawController = AsyncPosControllerBuilder().withMotor(intakePort).build();

// 2b
bool tbB = true;

void TwoBar::liftToggle()
{
  if (twoBarButton.changedToPressed())
  {
    tbB = !tbB; twoBarController->setTarget(tbB ? -1495 : -3100); // up position (0) will be 1495 from rest position
  }
}

// 4b
bool fbB = false;

void FourBar::liftToggle()
{
  /*if (fourBarNormal.isPressed()) fourBarMotor.moveVelocity(200);
  else if (fourBarReverse.isPressed()) fourBarMotor.moveVelocity(-200);
  else fourBarMotor.moveVelocity(0);
}

bool clawB = true;

void FourBar::claw()
{
  if (clawButton.changedToPressed())
  {
    clawB = !clawB; clawPiston.set_value(clawB);
  }
  */

  pros::delay(100);
}
