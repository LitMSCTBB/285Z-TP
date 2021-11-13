#include "../../include/285z/initRobot.hpp"
#include "../../include/285Z_Subsystems/lift.hpp"

std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarController = AsyncPosControllerBuilder().withMotor(fourBarPort).build();
std::shared_ptr<okapi::AsyncPositionController<double, double>> twoBarController = AsyncPosControllerBuilder().withMotor(twoBarPort).build();
std::shared_ptr<okapi::AsyncPositionController<double, double>> clawController = AsyncPosControllerBuilder().withMotor(clawPort).build();

// 2b

const int tbHeights[2] = {-3000, -1520};
int tbH = 2; // tbH will only ever be 2 at the beginning of the match (max height because needs to satisfy size reqs) before the lift is triggered for the first time


void TwoBar::liftToggle()
{
  if (twoBarButton.changedToPressed())
  {
    if (tbH == 2) tbH = 0;
    else {
      tbH++; if (tbH == sizeof(tbHeights)) tbH = 0;
    }
  }

  if (tbH != 2) twoBarController->setTarget(tbHeights[tbH]);
}

// 4b

int fbB = false;

void FourBar::liftToggle()
{
  if (fourBarButton.changedToPressed())
  {
    fbB = !fbB; fourBarController->setTarget(fbB ? -4750 : 0);
  }
}

int clawB = false;

void FourBar::claw()
{
  if (clawButton.changedToPressed())
  {
    clawB = !clawB; clawController->setTarget(clawB ? -820 : 0);
  }
}
 