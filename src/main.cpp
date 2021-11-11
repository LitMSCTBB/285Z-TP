#include "285z/initRobot.hpp"
#include "285z/functions.hpp"
#include "285Z_Subsystems/tray.hpp"
#include "285Z_Subsystems/lift.hpp"
#include "285Z_Subsystems/pid.hpp"
#include "285Z_Subsystems/intake.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/pros/llemu.hpp"
//
/** Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.

 */

 std::string autStringList [] =
 {
   "Red Left", 
   "Red Right", 
   "Blue Left", 
   "Blue Right",
   "No Auton",
   "Skills Auto"
 };
 
int i = 0;
bool isPressed = 0;

//**************** INITIALIZE ALL CHASSIS FOR AUTON ********************//

// okapi::DefaultOdomChassisController chassisauto = DefaultOdomChassisController();
std::shared_ptr<okapi::OdomChassisController> chassisaut = okapi::ChassisControllerBuilder()
        .withMotors(driveL, driveR) // left motor is 1, right motor is 2 (reversed)
        .withGains(
            {0.001, 0, 0.0001},        // Distance controller gains
            {0.00075, 0.001, 0.00009}, // Turn controller gains //try 0.00075, 0.001, 0.00009
            {0.001, 0, 0.0001}         // Angle controller gains (helps drive straight)
            )
        .withDimensions(AbstractMotor::gearset::green, scales)
        .withMaxVelocity(90)
        .withOdometryTimeUtilFactory(TimeUtilFactory())
        .withClosedLoopControllerTimeUtil(80, 10, 250_ms)
        .withOdometry()   // use the same scales as the chassis (above)
        .buildOdometry(); // build an odometry chassis

auto motion =
    ChassisControllerBuilder()
        .withMotors({frontLeftPort, backLeftPort}, {frontRightPort, backRightPort})
        .withDimensions(AbstractMotor::gearset::green, scales)
        .withMaxVelocity(200)
        .build();

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
-+
 */
 
 void initialize() {
 
   imuSensor.reset();
   while(imuSensor.is_calibrating()){
     pros::delay(15);
   }
 
 }
 
void disabled() {}

void competition_initialize()
{
  
  pros::lcd::initialize();

    imuSensor.reset();
    while(imuSensor.is_calibrating()){
      pros::delay(15);
    }

    pros::delay(20);

    while (true) {
    if (autoSelectorLeft.get_value() and !isPressed) {
      if (i > 0) {i -= 1; isPressed = true;}}
    else if (autoSelectorRight.get_value() and !isPressed) {
      if (i < 7) {i += 1; isPressed = true;}}
    else if(!autoSelectorLeft.get_value() && !autoSelectorRight.get_value()){isPressed = false;
    }

      pros::lcd::set_text(1, autStringList[i]);
      pros::delay(30);
    }
    
}

void autonomous()
{

  if(i == 0){redLeft();}
  else if(i == 1){redRight();}
  else if(i == 2){blueLeft();}
  else if(i == 3){blueRight();}
  else if(i == 4){noAuton();}
  else if(i == 7){skillsAuto();}

}

void opcontrol()
{

  // // LIFT TASK
  // pros::Task intakeThread(liftTask, (void *)"PROS", TASK_PRIORITY_DEFAULT,
  //                         TASK_STACK_DEPTH_DEFAULT, "Lift Task");

  TwoBar tb;
  FourBar fb;
  Intake in;

  while (1)
  {

    tb.liftToggle();
    chassisaut->getModel()->arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightX));
    fb.liftToggle(); 
    fb.claw();
    in.run();

    pros::delay(20);

  }
}
