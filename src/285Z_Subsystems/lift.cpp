#include "../../include/285z/initRobot.hpp"
#include "../../include/285Z_Subsystems/lift.hpp"

auto fourBarController = AsyncPosControllerBuilder().withMotor(fourBarPort).build();
auto twoBarController = AsyncPosControllerBuilder().withMotor(twoBarPort).build();
auto clawController = AsyncPosControllerBuilder().withMotor(clawPort).build();

// 2b

const int tbHeights[2] = {-3000, -1400};
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

const int fbHeights[2] = {0, -4700};
int fbH = 0;

void FourBar::liftToggle()
{
  if (fourBarButton.changedToPressed())
  {
    fbH++;
    if (fbH == sizeof(fbHeights))
      fbH = 0;
  }

  fourBarController->setTarget(fbHeights[fbH]);
}

const int clawHeights[2] = {0, -120};
int clawH = 0;

void FourBar::claw()
{
  if (clawButton.changedToPressed())
  {
    clawH++;
    if (clawH == sizeof(clawHeights))
      clawH = 0;
  }

  clawController->setTarget(clawHeights[clawH]);
}
