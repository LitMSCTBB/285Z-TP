#include "../../include/285z/initRobot.hpp"
#include "../../include/285Z_Subsystems/lift.hpp"

auto fourBarController = AsyncPosControllerBuilder().withMotor(fourBarPort).build();
auto twoBarController = AsyncPosControllerBuilder().withMotor(twoBarPort).build();
auto clawController = AsyncPosControllerBuilder().withMotor(clawPort).build();

// 2b

const int TB_NUM_HEIGHTS = 2;
const int tb_height0 = -2950;
const int tb_height1 = -1450;
const int tb_height2 = 0; // when tb is at highest at match start to satisfy height reqs

const int tbHeights[TB_NUM_HEIGHTS] = {tb_height0, tb_height1};
int tbHeight = 2; // tbHeight will only ever be 2 at the beginning of the match before the lift is triggered for the first time


void TwoBar::liftToggle()
{
  if (twoBarButton.changedToPressed())
  {
    if (tbHeight == 2) tbHeight = 0;
    else { 
      tbHeight++; if (tbHeight == 2) tbHeight = 0;
    }
  }

  if (tbHeight != 2) twoBarController->setTarget(tbHeights[tbHeight]);
}

// 4b

const int FB_NUM_HEIGHTS = 2;
const int fb_height0 = 0;
const int fb_height1 = 4700;

const int fbHeights[FB_NUM_HEIGHTS] = {fb_height0, fb_height1};
int fbHeight = 0;

void FourBar::liftToggle()
{
  if (fourBarButton.changedToPressed())
  {
    fbHeight++;
    if (fbHeight == FB_NUM_HEIGHTS)
      fbHeight = 0;
  }

  fourBarController->setTarget(fbHeights[fbHeight]);
}

void FourBar::claw()
{
  if (clawButton.changedToPressed())
  {
    // If the goal height is not at maximum and the up button is pressed, increase the setpoint
    // heightNow++;
    clawController->setTarget(2000);
  }
  else
  {
    clawMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
    clawController->tarePosition();
  }
}
