#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"
#include "../../include/285Z_Subsystems/lift.hpp"
#include "../../include/285z/functions.hpp"
#include "pros/llemu.hpp"


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
const double potLB = 580;
const double potUB = 1900;

double potVal = pot.get();



//AUTON FUNCTIONS

void Tilter::grab()
{
  tilter.set_value(true);
}

void Tilter::release()
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

void Tilter::lift2Toggle()
{
  if (tilterButton.changedToPressed())
  {
    tB = !tB;
    if (tB) this->grab(); else this->release();
  }
}

void FourBar::liftToggle()
{

  fourBarMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  
  if (fbDownButton.isPressed() && potVal > potLB) 
    fourBarMotor.moveVoltage(-12000);
  else if (fbUpButton.isPressed() && potVal < potUB) 
    fourBarMotor.moveVoltage(12000);
  else
    fourBarMotor.moveVoltage(0);


  potVal = pot.get();

  fourBarMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  
}


void FourBar::claw()
{

  if (clawButton.changedToPressed())
  {
    clawB = !clawB;
    clawMech.set_value(clawB);
  }

}
