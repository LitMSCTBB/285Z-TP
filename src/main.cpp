#include "285z/initRobot.hpp"
#include "../include/285z/functions.hpp"
#include "285Z_Subsystems/lift.hpp"
#include "285Z_Subsystems/pid.hpp"
#include "285Z_Subsystems/intake.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/pros/llemu.hpp"

int autoIndex = 0;

std::string autList [] =
{
  "No Auton",
  "Skills Auton",
  "Left Side Winpoint",
  "Right Side Winpoint",
  "Full Winpoint",
  "Neutral Side (Right)",
  "Neutral Side (Left)",
  "Neutral Center (Right)",
  "Neutral Center (Left)",
  "Neutral Side & Center (Right)",
  "Neutral Side & Center (Left)"
};

TwoBar tb;
FourBar fb;
Intake in;
int len = sizeof(autList)/sizeof(autList[0]);

//**************** INITIALIZE ALL CHASSIS FOR AUTON ********************//


std::shared_ptr<ChassisController> chassis = okapi::ChassisControllerBuilder()
      .withMotors(driveL, driveR)
      .withDimensions({AbstractMotor::gearset::blue, (84.0 / 36.0)}, {{4.125_in, 14.5_in}, imev5BlueTPR})
      .withMaxVoltage(12000)
      .build();

std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(chassis->getModel());

std::shared_ptr<okapi::AsyncMotionProfileController> fastAuto = AsyncMotionProfileControllerBuilder()
      .withLimits({
        2.7, //max linear velocity of Chassis in m/s
        9, //max linear acceleration in m/s^2
        18.0 //max linear jerk in m/s^3
      })
      .withOutput(chassis)
      .buildMotionProfileController();

std::shared_ptr<okapi::AsyncMotionProfileController> normalAuto = AsyncMotionProfileControllerBuilder()
      .withLimits({
        0.5, //max linear velocity of Chassis in m/s
        1.5, //max linear acceleration in m/s^2
        3.5 //max linear jerk in m/s^3
      })
      .withOutput(chassis)
      .buildMotionProfileController();

std::shared_ptr<okapi::ChassisController> PIDchassis = okapi::ChassisControllerBuilder()
    .withMotors(driveL, driveR)
    .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)}, {{3.25_in, 14.5_in}, imev5BlueTPR})
    .withMaxVoltage(12000)
    .withGains(
      {0.00191, 0.0, 0.00005}, // Distance controller gains  
      {0.001, 0, 0.0001}, // Turn controller gains
      {0.001, 0, 0.0001}  // Angle controller gains (helps drive straight)
    )
    .withClosedLoopControllerTimeUtil(50, 5, 250_ms)
    .withDerivativeFilters(
        std::make_unique<AverageFilter<3>>() // Distance controller filter
    )
    .build();

std::shared_ptr<okapi::ChassisController> PIDchassisGoal = okapi::ChassisControllerBuilder()
    .withMotors(driveL, driveR)
    .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)}, {{3.25_in, 14.5_in}, imev5BlueTPR})
    .withMaxVoltage(12000)
    .withGains(
      {0.0014, 0, 0.000007}, // Distance controller gains 
      {0.001, 0, 0.0001}, // Turn controller gains
      {0.001, 0, 0.0001}  // Angle controller gains (helps drive straight)
    )
    .withClosedLoopControllerTimeUtil(50, 5, 250_ms)
    .withDerivativeFilters(
        std::make_unique<AverageFilter<3>>() // Distance controller filter
    )
    .build();

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
  imuSensor.reset();
  while (imuSensor.is_calibrating())
    pros::delay(15);


  driveR.setBrakeMode(AbstractMotor::brakeMode::hold);
  driveL.setBrakeMode(AbstractMotor::brakeMode::hold);

  fourBarMotor1.setBrakeMode(AbstractMotor::brakeMode::hold);
  fourBarMotor2.setBrakeMode(AbstractMotor::brakeMode::hold);

  clawMech.set_value(true);

  pros::lcd::initialize();

  pros::lcd::set_text(6, "// CALIBRATION COMPLETE //");

  while(true) {
      bool autval = autonSelector.get_value();

      if (autval == 1) {
        pros::delay(200);
        autoIndex=(autoIndex + 1) % len;
      }

      pros::lcd::set_text(7, autList[autoIndex]);

      pros::delay(20);
    }

}

void autonomous()
{
  switch(autoIndex) {
    case (0): noAuton(); break;
    case (1): skillsAuto(normalAuto, fastAuto); break;
    case (2): redLeftBlueLeft(normalAuto, fastAuto); break;
    case (3): redRightBlueRight(normalAuto, fastAuto); break;
    case (4): winPoint(normalAuto, fastAuto); break;
    case (5): neutralSideRight(normalAuto, fastAuto); break;
    case (6): neutralSideLeft(normalAuto, fastAuto); break;
    case (7): neutralCenterRight(normalAuto, fastAuto); break;
    case (8): neutralCenterLeft(normalAuto, fastAuto); break;
    case (9): neutralSideCenterRight(normalAuto, fastAuto); break;
    case (10): neutralSideCenterLeft(normalAuto, fastAuto); break;
    default: noAuton();
  }
}


void opcontrol()
{

  driveR.setBrakeMode(AbstractMotor::brakeMode::coast);
  driveL.setBrakeMode(AbstractMotor::brakeMode::coast);

  while (1) {
    fb.claw();

    model->tank(controller.getAnalog(okapi::ControllerAnalog::leftY),
              controller.getAnalog(okapi::ControllerAnalog::rightY));

    //fourBarVal = autonPotL.get(); //FOR TESTING POT VALUES
    //pros::lcd::set_text(1, std::to_string(fourBarVal)); //FOR TESTING POT VALUES


    tb.liftToggle();

    fb.liftToggle();
    in.run();
    in.reverse();
    tb.reset();

    pros::delay(20);

  }
}
