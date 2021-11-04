#include "../../include/285z/initRobot.hpp"
#include "../../include/285Z_Subsystems/lift.hpp"

auto fourBarController = AsyncPosControllerBuilder().withMotor(fourBarPort).build();
auto twoBarController = AsyncPosControllerBuilder().withMotor(twoBarPort).build();
auto clawController = AsyncPosControllerBuilder().withMotor(clawPort).build();

// 2b

const int NUM_HEIGHTS = 2;
const int height0 = 0;
const int height1 = 800;

const int heights[NUM_HEIGHTS] = {height0, height1};
int tbHeight = 0;


void TwoBar::liftToggle()
{
  if (twoBarButton.changedToPressed())
  {
    tbHeight++; if (tbHeight == NUM_HEIGHTS) tbHeight = 0; 
  }

  twoBarController->setTarget(heights[tbHeight]);
}

// 4b

void FourBar::liftToggle()
{
  if (fourBarButton.changedToPressed())
  {
    // If the goal height is not at maximum and the up button is pressed, increase the setpoint
    // heightNow++;
    fourBarController->setTarget(2000);
  }
  else
  {
    fourBarMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
    fourBarController->tarePosition();
  }
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