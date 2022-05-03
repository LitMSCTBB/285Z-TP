#include "../../include/285z/initRobot.hpp"
#include "../../include/285Z_Subsystems/intake.hpp"

bool intakeB = false;

void Intake::run()
{
  intakeMotor.setBrakeMode(AbstractMotor::brakeMode::coast);

  if (intakeButton.changedToPressed()) {
    intakeB = !intakeB;
    intakeMotor.moveVoltage(intakeB ? 12000 : 0);
  }
}

void Intake::reverse() {
  
  if (intakeReverse.isPressed()) {
    intakeMotor.moveVoltage(-12000);
  }
}