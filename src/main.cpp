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
  .withMaxVelocity(600)
  .withOdometry()   // use the same scales as the chassis (above)
  .buildOdometry(); // build an odometry chassis

std::shared_ptr<okapi::ChassisController> motion =
    ChassisControllerBuilder()
      .withMotors(driveL, driveR)
      .withMaxVelocity(600)
      .withDimensions(AbstractMotor::gearset::blue, scales)
      .build();

std::shared_ptr<okapi::AsyncMotionProfileController> fastAuto = AsyncMotionProfileControllerBuilder()
      .withLimits({
        2.8213, //max linear velocity of Chassis in m/s
        2.6, //max linear acceleration in m/s^2
        10.0 //max linear jerk in m/s^3
      })
      .withOutput(motion)
      .buildMotionProfileController();

std::shared_ptr<okapi::AsyncMotionProfileController> mediumAuto = AsyncMotionProfileControllerBuilder()
      .withLimits({
        1.7, //max linear velocity of Chassis in m/s
        2.3, //max linear acceleration in m/s^2
        10.0 //max linear jerk in m/s^3
      })
      .withOutput(motion)
      .buildMotionProfileController();

std::shared_ptr<okapi::AsyncMotionProfileController> slowAuto = AsyncMotionProfileControllerBuilder()
      .withLimits({
        0.7, //max linear velocity of Chassis in m/s
        2.0, //max linear acceleration in m/s^2
        10.0 //max linear jerk in m/s^3
      })
      .withOutput(motion)
      .buildMotionProfileController();


/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
-+
 */

void disabled() {

  //clawPiston.set_value(true);

}

void competition_initialize()
{

  //pros::lcd::initialize();
  imuSensor.reset();
  while (imuSensor.is_calibrating())
    pros::delay(15);

  //clawPiston.set_value(false);

}

void autonomous()
{
  //noAuton();
  skillsAuto(slowAuto, mediumAuto, fastAuto);
  //redLeftBlueLeft(slowAuto, mediumAuto, fastAuto);
  //redRightBlueRight(slowAuto, mediumAuto, fastAuto);x
  // winPoint(slowAuto, mediumAuto, fastAuto);
}

void opcontrol()
{
  TwoBar tb;
  FourBar fb;
  Intake in;

  while (1)
  {
    chassisaut->getModel()->tank(
      controller.getAnalog(ControllerAnalog::leftY),
      controller.getAnalog(ControllerAnalog::rightY)
    );

  tb.liftToggle();
  fb.liftToggle();
  fb.claw();
  in.run();

  pros::delay(20);

  }

}
