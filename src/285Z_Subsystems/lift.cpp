#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"
#include "../../include/285Z_Subsystems/lift.hpp"

std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarControllerLeft = AsyncPosControllerBuilder().withMotor(fourBarPortLeft).build();
std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarControllerRight = AsyncPosControllerBuilder().withMotor(fourBarPortRight).build();
std::shared_ptr<okapi::AsyncPositionController<double, double>> twoBarController = AsyncPosControllerBuilder().withMotor(twoBarPort).build();
std::shared_ptr<okapi::AsyncPositionController<double, double>> clawController = AsyncPosControllerBuilder().withMotor(intakePort).build();

// 2b
bool tbB = true;

void TwoBar::liftToggle()
{
  if (twoBarButton.changedToPressed())
  {
    tbB = !tbB;
    twoBarController->setTarget(tbB ? -1430 : -3000);
    // up position (0) will be 1495 from rest position
  }
}

// 4b
bool fbB = false;

void FourBar::liftToggle()
{
  if (fourBarNormal.isPressed()) {
    fourBarMotor1.moveVoltage(12000);
    fourBarMotor2.moveVoltage(12000);
  }
  else if (fourBarReverse.isPressed()) {
    fourBarMotor1.moveVoltage(-12000);
    fourBarMotor2.moveVoltage(-12000);
  }
    fourBarMotor1.moveVoltage(0);
    fourBarMotor1.setBrakeMode(AbstractMotor::brakeMode::hold);

    fourBarMotor2.moveVoltage(0);
    fourBarMotor2.setBrakeMode(AbstractMotor::brakeMode::hold);
}

bool clawB = true;

void FourBar::claw()
{
  if (clawButton.changedToPressed())
  {
    clawB = !clawB; clawPiston.set_value(clawB);
  }
}
