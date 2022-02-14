#include "285z/initRobot.hpp"
#include "../include/285z/functions.hpp"
#include "285Z_Subsystems/lift.hpp"
#include "285Z_Subsystems/pid.hpp"
#include "285Z_Subsystems/intake.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/pros/llemu.hpp"

int autoIndex = 0;
bool isPressed = 0;

std::string autList [] =
{
  "No Auton",
  "Winpoint Auton",
  "Left Side Winpoint",
  "Right Side Winpoint",
  "Neutral Left / Right",
  "Neutral Center",
  "Neutral Side + Center (Right)",
  "Skills Auton"
};


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
        10.5, //max linear acceleration in m/s^2
        40.0 //max linear jerk in m/s^3
      })
      .withOutput(motion)
      .buildMotionProfileController();

std::shared_ptr<okapi::AsyncMotionProfileController> mediumAuto = AsyncMotionProfileControllerBuilder()
      .withLimits({
        1.7, //max linear velocity of Chassis in m/s
        6, //max linear acceleration in m/s^2
        24 //max linear jerk in m/s^3
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


void disabled() {}

//
/** Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void competition_initialize()
{

    pros::lcd::initialize();

    imuSensor.reset();
    while (imuSensor.is_calibrating())
      pros::delay(15);

    pros::lcd::set_text(1, "IMU Calibration Finished");

    fastAuto->generatePath({
        {0_ft,0_ft,0_deg},
        {10_ft, 0_ft,0_deg}},
        "sideLeft"
    );

    pros::lcd::set_text(1, "Side Path Finished");

    fastAuto->generatePath({
        {0_ft,0_ft,0_deg},
        {9.4_ft, 0_ft,0_deg}},
        "sideRight"
    );


    pros::lcd::set_text(1, "Center Path Finished");

    while(true) {

      bool autval = autonSelector.get_value();

      if (autval == 1) {
        pros::delay(350);
        autoIndex=(autoIndex + 1) % 8;
      }

      pros::lcd::set_text(6, autList[autoIndex]);
      pros::delay(20);
    }

}

void autonomous()
{

  pros::lcd::shutdown();

  switch(autoIndex) {
    case (0):
      noAuton();
      break;
    case (1):
      fastAuto->removePath("sideLeft");
      fastAuto->removePath("sideRight");
      skillsAuto(slowAuto, mediumAuto, fastAuto);
      break;
    case (2):
      fastAuto->removePath("sideRight");
      redLeftBlueLeft(slowAuto, mediumAuto, fastAuto);
      break;
    case (3):
      fastAuto->removePath("sideLeft");
      redRightBlueRight(slowAuto, mediumAuto, fastAuto);
      break;
    case (4):
      fastAuto->removePath("sideLeft");
      fastAuto->removePath("sideRight");
      winPoint(slowAuto, mediumAuto, fastAuto);
      break;
    case (5):
      fastAuto->removePath("sideRight");
      neutralSide(slowAuto, mediumAuto, fastAuto);
      break;
    case (6):
      fastAuto->removePath("sideLeft");
      fastAuto->removePath("sideRight");
      neutralCenter(slowAuto, mediumAuto, fastAuto);
      break;
    case (7):
      neutralSideCenter(slowAuto, mediumAuto, fastAuto);
      break;
    default:
      noAuton();
  }
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
    // in.reverse();

    pros::delay(20);

  }

}
