#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"


//***********************  INITIALIZE SUBSYSTEMS  ***************************//
Lift lift;

//           DRIVE         //
/*void tankDrive(){
  model->tank(controller.getAnalog(okapi::ControllerAnalog::rightY),
        controller.getAnalog(okapi::ControllerAnalog::leftY));

}

void arcadeDrive(){
  model->arcade(controller.getAnalog(okapi::ControllerAnalog::leftY),
    -controller.getAnalog(okapi::ControllerAnalog::rightX));
}*/



//******************* INTAKE ********************//

//TOGGLE INTAKE

//REVERSE INTAKE WHEN BUTTON HELD


//****************** ANGLER ********************//




//*********************MACROS*******************************//

// MANUAL DUAL CONTROL
void liftControl()
{
  if (liftUpButton.isPressed())
  {
    lift.move(-200);
  }
  else if (liftDownButton.isPressed())
  {
    lift.move(170);
  }
  else
  {
    lift.move(0);
  }
}

// TASK FOR LIFT CONTROL
void liftTask(void *param)
{
  while (true)
  {
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
    liftControl();
    pros::Task::delay(10);
  }
}