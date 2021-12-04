#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"
#include "../../include/285Z_Subsystems/lift.hpp"

std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarController = AsyncPosControllerBuilder().withMotor(fourBarPort).build();
std::shared_ptr<okapi::AsyncPositionController<double, double>> twoBarController = AsyncPosControllerBuilder().withMotor(twoBarPort).build();
std::shared_ptr<okapi::AsyncPositionController<double, double>> clawController = AsyncPosControllerBuilder().withMotor(clawPort).build();

// 2b
bool tbB = true; // tbH will only ever be 2 at the beginning of the match (max height because needs to satisfy size reqs) before the lift is triggered for the first time

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
  if (fourBarButton.changedToPressed())
  {
    fbB = !fbB; fourBarController->setTarget(fbB ? -4350 : 0);
  }
}

bool clawB = true;

void FourBar::claw()
{
  if (clawButton.changedToPressed())
  {
    clawB = !clawB; clawPiston.set_value(clawB);
  }
}
 