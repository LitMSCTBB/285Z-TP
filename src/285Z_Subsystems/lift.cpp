#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"
#include "../../include/285Z_Subsystems/lift.hpp"

// std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarControllerLeft =
//     AsyncPosControllerBuilder()
//       .withMotor(fourBarPortLeft)
//       .build();
//
// std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarControllerRight =
//     AsyncPosControllerBuilder()
//       .withMotor(fourBarPortRight)
//       .build();

std::shared_ptr<okapi::AsyncPositionController<double, double>> twoBarController =
    AsyncPosControllerBuilder()
      .withMotor(twoBarPort)
      .build();

//claw
bool clawB = true;

// 2b
bool tbB = true;
const int height0 = -3000;
const int height1 = -1230; //increase magnitude to go higher

//4b

const int height0L = 0;
const int height0R = 0;
const int height1L = 100;
const int height1R = 100;
int currentHeight = fourBarMotor1.getPosition();


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

    if (fourBarNormal.isPressed() && currentHeight <= height1L) {
      fourBarMotor1.moveVelocity(100);
      fourBarMotor2.moveVelocity(100);
    } else if (fourBarReverse.isPressed()) {
      fourBarMotor1.moveVelocity(-100);
      fourBarMotor2.moveVelocity(-100);
    } else {
    fourBarMotor1.moveVelocity(0);
    fourBarMotor2.moveVelocity(0);
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
