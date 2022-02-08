#include "../../include/285z/initRobot.hpp"
#include "../../include/285Z_Subsystems/intake.hpp"

auto intakeController = AsyncPosControllerBuilder().withMotor(intakeMotor).build();

bool intakeB = false;

void Intake::run()
{
  intakeMotor.setBrakeMode(AbstractMotor::brakeMode::coast);

  if (intakeButton.changedToPressed()) intakeB = !intakeB;
  intakeMotor.moveVelocity(intakeB ? -600 : 0);
}

void Intake::reverse() {
  intakeMotor.setBrakeMode(AbstractMotor::brakeMode::coast);

  if (intakeReverse.changedToPressed()) {
    intakeMotor.moveVelocity(0); intakeB = false;
    intakeMotor.moveVelocity(600);
  }
  else {
    intakeMotor.moveVelocity(0);
  }
}
