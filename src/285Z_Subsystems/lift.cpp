#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"
#include "../../include/285Z_Subsystems/lift.hpp"
#include "../../include/285z/functions.hpp"

std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarControllerL =
    AsyncPosControllerBuilder()
      .withMotor(fourBarPortLeft)
      .withMaxVelocity(140)
      .build();

std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarControllerR =
    AsyncPosControllerBuilder()
      .withMotor(fourBarPortRight)
      .withMaxVelocity(140)
      .build();

std::shared_ptr<okapi::AsyncPositionController<double, double>> twoBarController =
    AsyncPosControllerBuilder()
      .withMotor(twoBarPort)
      .build();



//claw
bool clawB = false;

// 2b
bool tbB = true;
const int height0 = -3000;
const int height1 = -1585; //decrease magnitude to go higher

//4b
const double height0F = 0.0;
const double height1F = 1630.0;
double currentHeight = fourBarMotor1.getPosition();


void TwoBar::liftToggle()
{

  if (twoBarButton.changedToPressed())
  {
    tbB = !tbB;
    if (tbB) twobarUp();
    else twobarDown();
  }

}

void TwoBar::reset()
{
  if (resettwobarButton.changedToPressed()) twoBarController->setTarget(0);
}



//AUTON FUNCTIONS
void twobarUp()
{
  twoBarController->setTarget(height1);
}

void twobarDown()
{
  twoBarController->setTarget(height0);
}

void fourbarDown()
{
  fourBarControllerL->setTarget(0.0);
  fourBarControllerR->setTarget(0.0);
}

void fourbarLift(const double target) {

  fourBarControllerL->setTarget(target);
  fourBarControllerR->setTarget(target);

}



void FourBar::liftToggle()
{

 fourBarMotor1.setBrakeMode(AbstractMotor::brakeMode::hold);  //left motor
 fourBarMotor2.setBrakeMode(AbstractMotor::brakeMode::hold);  //right motor

  if (fourBarNormal.isPressed() && currentHeight <= height1F) {
    fourBarMotor1.moveVelocity(200);
    fourBarMotor2.moveVelocity(200);
  }
  else if (fourBarReverse.isPressed() && currentHeight >= height0F)
  {
    fourBarMotor1.moveVelocity(-130);
    fourBarMotor2.moveVelocity(-130);
  }
  else
  {
    fourBarMotor1.moveVelocity(0);
    fourBarMotor2.moveVelocity(0);

  }
  currentHeight = fourBarMotor1.getPosition();

}

void FourBar::claw()
{

  if (clawButton.changedToPressed())
  {
    clawB = !clawB;
    clawPiston.set_value(clawB);
  }

}
