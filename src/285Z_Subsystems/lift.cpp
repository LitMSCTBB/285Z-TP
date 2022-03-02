#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"
#include "../../include/285Z_Subsystems/lift.hpp"
#include "../../include/285z/functions.hpp"

//std::shared_ptr<okapi::Potentiometer> potL_ptr = std::make_shared<okapi::Potentiometer>(autonPotL);
std::shared_ptr<okapi::Potentiometer> potR_ptr = std::make_shared<okapi::Potentiometer>(autonPotR);

// AUTONOMOUS CONTROLLERS
std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarControllerL =
    AsyncPosControllerBuilder()
        .withMotor(fourBarPortLeft)
        .withMaxVelocity(100)
        .build();

std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarControllerR =
    AsyncPosControllerBuilder()
      .withMotor(fourBarPortRight)
      .withMaxVelocity(100)
      .build();

std::shared_ptr<okapi::AsyncPositionController<double, double>> twoBarController =
    AsyncPosControllerBuilder()
      .withMotor(twoBarPort)
      .build();



//claw
bool clawB = false;

//two bar
bool tbB = true;
const int height0 = -3000;
const int height1 = -1565; //decrease magnitude to go higher

//four bar
const double height0F = 0.0;
const double height1F = 2800.0;

double currentHeight = fourBarMotor1.getPosition();
// double currentHeight1 = 0.0; // left lift motor
// double currentHeight2 = 0.0; // right lift motor


void TwoBar::liftToggle()
{

  twoBarMotor.setBrakeMode(AbstractMotor::brakeMode::hold);

  if (twoBarButton.changedToPressed())
  {
    tbB = !tbB;
    if (tbB) twobarUp();
    else twobarDown();
  }

}

void TwoBar::reset()
{
  if (resettwobarButton.changedToPressed())
  twoBarController->setTarget(0);
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

  fourBarMotor1.setBrakeMode(AbstractMotor::brakeMode::hold);
  fourBarMotor2.setBrakeMode(AbstractMotor::brakeMode::hold);
  //  double valLR = autonPotR.get();

  // if (fourBarNormal.isPressed() && valLR > 159) //add pot limits 123
  if (fourBarNormal.isPressed() && currentHeight <= height1F) //add pot limits 123
  {
    fourBarMotor1.moveVelocity(200);
    fourBarMotor2.moveVelocity(200);
  }
  // else if (fourBarReverse.isPressed() && valLR < 786) //add pot limits 790
  else if (fourBarReverse.isPressed() && currentHeight >= height0F) //add pot limits 790
  {
    fourBarMotor1.moveVelocity(-200);
    fourBarMotor2.moveVelocity(-200);
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
