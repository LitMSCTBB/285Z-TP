#include "../../include/285z/initRobot.hpp"
#include "../../include/285Z_Subsystems/intake.hpp"

auto intakeController = AsyncPosControllerBuilder().withMotor(intakeMotor).build();

void Intake::run()
{
  if (intakeNormalButton.isPressed())
  {
    intakeMotor.moveVoltage(12000);
  }
  else if (intakeReverseButton.isPressed())
  {
    intakeMotor.moveVoltage(-12000);
  }
  else
  {
    intakeMotor.moveVoltage(0);
  }

}