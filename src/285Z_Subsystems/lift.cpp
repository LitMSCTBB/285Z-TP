#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"
#include "../../include/285Z_Subsystems/lift.hpp"

// std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarControllerL =
//     AsyncPosControllerBuilder()
//       .withMotor(fourBarPortLeft)
//       .build();

// std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarControllerR =
//     AsyncPosControllerBuilder()
//       .withMotor(fourBarPortRight)
//       .build();

std::shared_ptr<okapi::AsyncPositionController<double, double>> twoBarController =
    AsyncPosControllerBuilder()
      .withMotor(twoBarPort)
      .build();

//claw
bool clawB = false;

// 2b
bool tbB = true;
const int height0 = -3010;
const int height1 = -1615; //decrease magnitude to go higher

//4b
const double height0F = 1.0;
const double height1F = 1520.0;
double currentHeight = fourBarMotor1.getPosition();


void TwoBar::liftToggle()
{

  if (twoBarButton.changedToPressed())
  {
    tbB = !tbB;
    twoBarController->setTarget(tbB ? height1 : height0);
  }
}


void FourBar::liftToggle()
{

  fourBarMotor1.setBrakeMode(AbstractMotor::brakeMode::hold); //left motor
  fourBarMotor2.setBrakeMode(AbstractMotor::brakeMode::hold); //right motor

  if (fourBarNormal.isPressed()) {
    fourBarMotor1.moveVelocity(100);
    fourBarMotor2.moveVelocity(100);
    currentHeight = fourBarMotor1.getPosition();
  }
  else if (fourBarReverse.isPressed() && currentHeight >= height0F)
  {
    fourBarMotor1.moveVelocity(-100);
    fourBarMotor2.moveVelocity(-100);
    currentHeight = fourBarMotor1.getPosition();
  }
  else
  {
    fourBarMotor1.moveVelocity(0);
    fourBarMotor2.moveVelocity(0);
    currentHeight = fourBarMotor1.getPosition();
  }
}

void FourBar::claw()
{
  if (clawButton.changedToPressed())
  {
    clawB = !clawB;
    clawPiston.set_value(clawB);
  }
}
