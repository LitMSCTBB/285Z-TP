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
bool tB = true;

//four bar
const double height0F = 0.0;
const double height1F = 2900.0;

double currentHeight = fourBarMotor.getPosition();
// double currentHeight1 = 0.0; // left lift motor
// double currentHeight2 = 0.0; // right lift motor

//AUTON FUNCTIONS

void Tilter::up()
{
  tilter.set_value(true);
}

void Tilter::down()
{
  tilter.set_value(false);
}

void FourBar::down()
{
  fourBarController->setTarget(0.0);
}

void FourBar::lift(const double target) {
  fourBarController->setTarget(target);
}

// opcontrol

void Tilter::liftToggle()
{
  if (tilterButton.changedToPressed())
  {
    tB = !tB;
    if (tB) this->up(); else this->down();
  }
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
