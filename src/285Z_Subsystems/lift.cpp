#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"
#include "../../include/285Z_Subsystems/lift.hpp"
#include "../../include/285z/functions.hpp"


// AUTONOMOUS CONTROLLERS
std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarController =
    AsyncPosControllerBuilder()
        .withMotor(fourBarPort)
        .build();


//claw
bool clawB = false;

//two bar
bool tbB = true;
const int height0 = -2970;
const int height1 = -1480; //decrease magnitude to go higher

//four bar
const double height0F = 0.0;
const double height1F = 2900.0;

double currentHeight = fourBarMotor.getPosition();
// double currentHeight1 = 0.0; // left lift motor
// double currentHeight2 = 0.0; // right lift motor

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
  fourBarController->setTarget(0.0);
}

void fourbarLift(const double target) {

  fourBarController->setTarget(target);

}



void FourBar::liftToggle()
{

  fourBarMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  //  double valLR = autonPotR.get();

  double targetVel = controller.getAnalog(okapi::ControllerAnalog::leftY);
  if (targetVel < 0 && currentHeight >= height0F)
    fourBarMotor.moveVelocity(targetVel);
  else if (targetVel > 0 && currentHeight <= height1F)
    fourBarMotor.moveVelocity(targetVel);
  else
    fourBarMotor.moveVelocity(0);

  currentHeight = fourBarMotor.getPosition();
}


void FourBar::claw()
{

  if (clawButton.changedToPressed())
  {
    clawB = !clawB;
    clawMech.set_value(clawB);
  }

}
