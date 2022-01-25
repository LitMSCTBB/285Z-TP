#include "285z/initRobot.hpp"
#include "../include/285z/functions.hpp"
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

//**************** INITIALIZE ALL CHASSIS FOR AUTON ********************//

std::string autStringList[] =
    {
        "Red Left",
        "Red Right",
        "Blue Left",
        "Blue Right",
        "No Auton",
        "Skills Auto"};

int i = 0;
bool isPressed = 0;

std::shared_ptr<okapi::OdomChassisController> chassisaut = okapi::ChassisControllerBuilder()
  .withMotors(driveL, driveR)
  .withGains(
      {0.001, 0, 0.0001},        // Distance controller gains
      {0.00075, 0.001, 0.00009}, // Turn controller gains //try 0.00075, 0.001, 0.00009
      {0.001, 0, 0.0001}         // Angle controller gains (helps drive straight)
      )
  .withDimensions(AbstractMotor::gearset::blue, scales)
  .withOdometryTimeUtilFactory(TimeUtilFactory())
  .withClosedLoopControllerTimeUtil(80, 10, 250_ms)
  .withOdometry()   // use the same scales as the chassis (above)
  .buildOdometry(); // build an odometry chassis

std::shared_ptr<okapi::ChassisController> motion =
    ChassisControllerBuilder()
      .withMotors(driveL, driveR)
      .withDimensions(AbstractMotor::gearset::blue, scales)
      .build();

std::shared_ptr<okapi::AsyncMotionProfileController> profileController = AsyncMotionProfileControllerBuilder()
      .withLimits({1.1, 2.0, 10.0})
      .withOutput(motion)
      .buildMotionProfileController();

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
-+
 */

double potVal;

void disabled() {

  clawPiston.set_value(true);

}

void competition_initialize()
{

  //pros::lcd::initialize();

  clawPiston.set_value(false);

  imuSensor.reset();
  while (imuSensor.is_calibrating())
    pros::delay(15);

}

void autonomous()
{
  skillsAuto(profileController);
  //noAuton();
  //blueRight(profileController);
  //blueLeft(profileController);
  //redRight(profileController);
  //redLeft(profileController);
}

void opcontrol()
{
  TwoBar tb;
  FourBar fb;
  Intake in;

  while (1)
  {

    tb.liftToggle();
    chassisaut->getModel()->tank(
      controller.getAnalog(ControllerAnalog::leftY),
      controller.getAnalog(ControllerAnalog::rightY)
    );
    fb.liftToggle();
    fb.claw();
    in.run();

    pros::delay(20);

  }
}
