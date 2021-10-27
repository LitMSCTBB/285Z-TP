#include "../../include/285z/initRobot.hpp"
#include "../../include/285Z_Subsystems/lift.hpp"

auto fourBarController = AsyncPosControllerBuilder().withMotor(fourBarPort).build();
auto twoBarController = AsyncPosControllerBuilder().withMotor(twoBarPort).build();
auto clawController = AsyncPosControllerBuilder().withMotor(clawPort).build();

// 2b

void TwoBar::liftToggle()
{
  if (twoBarButton.changedToPressed())
  {
    // If the goal height is not at maximum and the up button is pressed, increase the setpoint
    // heightNow++;
    twoBarController->setTarget(2000);
  }
  else
  {
    twoBarMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
    twoBarController->tarePosition();
  }
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