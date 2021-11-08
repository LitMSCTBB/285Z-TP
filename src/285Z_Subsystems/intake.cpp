#include "../../include/285z/initRobot.hpp"
#include "../../include/285Z_Subsystems/intake.hpp"

auto intakeController = AsyncPosControllerBuilder().withMotor(intakePort).build();

void Intake::normal()
{
  if (intakeNormalButton.isPressed())
  {
    // If the goal height is not at maximum and the up button is pressed, increase the setpoint
    // heightNow++;
    intakeController->setTarget(200);
  }
  else
  {
    intakeMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
    intakeController->tarePosition();
  }
}

void Intake::reverse()
{
  if (intakeReverseButton.isPressed())
  {
    // If the goal height is not at maximum and the up button is pressed, increase the setpoint
    // heightNow++;
    intakeController->setTarget(-200);
  }
  else
  {
    intakeMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
    intakeController->tarePosition();
  }
}