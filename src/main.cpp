#include "285z/initRobot.hpp"
#include "../include/285z/functions.hpp"
#include "285Z_Subsystems/lift.hpp"
#include "285Z_Subsystems/pid.hpp"
#include "285Z_Subsystems/intake.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/pros/llemu.hpp"
#include <array>


int autoIndex = 0;
int modeIndex = 0;

std::string modes [] = {

  "WIN POINT",
  "NEUTRAL",
  "WIN POINT NEUTRAL"

};

std::string WP [] = {
  
  "No Auton",
  "Left Side WP",
  "Right Side WP",
  "Full WP",

};

std::string Neutral [] = {

  "N Side (Right)",
  "N Side (Left)",
  "N Center (Right)",
  "N Center (Left)",
  "N Side/Center (Right)",

};

std::string WPNeutral [] = {

  "Right Side WP + N",
  "Left Side WP + N",
  "Right Side WP + N Side/Center"

};

// std::string functions [] = {
  
//   "No Auton",
//   "Left Side WP",
//   "Right Side WP",
//   "Full WP",
//   "N Side (Right)",
//   "N Side (Left)",
//   "N Center (Right)",
//   "N Center (Left)",
//   "N Side/Center (Right)",
//   "Right Side WP + N",
//   "Left Side WP + N",
//   "Right Side WP + N Side/Center"

// };

Tilter t;
FourBar fb;
Intake in;

// int len = sizeof(autList)/sizeof(autList[0]);




//**************** INITIALIZE ALL CHASSIS FOR AUTON ********************//

std::shared_ptr<ChassisController> chassis = okapi::ChassisControllerBuilder()
      .withMotors(driveL, driveR)
      .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)}, {{3.25_in, 14.5_in}, imev5BlueTPR})
      .withMaxVoltage(12000)
      .build();

std::shared_ptr<okapi::ChassisModel> model = std::dynamic_pointer_cast<okapi::ChassisModel>(chassis->getModel());

std::shared_ptr<okapi::AsyncMotionProfileController> fastAuto = AsyncMotionProfileControllerBuilder()
      .withLimits({
        5.11, //max linear velocity of Chassis in m/s
        10.0, //max linear acceleration in m/s^2
        20.0 //max linear jerk in m/s^3
      })
      .withOutput(chassis)
      .buildMotionProfileController();

std::shared_ptr<okapi::AsyncMotionProfileController> normalAuto = AsyncMotionProfileControllerBuilder()
      .withLimits({
        2.7, //max linear velocity of Chassis in m/s
        4, //max linear acceleration in m/s^2
        6 //max linear jerk in m/s^3
      })
      .withOutput(chassis)
      .buildMotionProfileController();

std::shared_ptr<okapi::ChassisController> PIDchassis = okapi::ChassisControllerBuilder()
    .withMotors(driveL, driveR)
    .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)}, {{3.25_in, 14.5_in}, imev5BlueTPR})
    .withMaxVoltage(12000)
    .withGains(
      {0.00170, 0.0, 0.0000010}, // Distance controller gains  
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

  //IMU Calibration
  imuSensor.reset();
  while (imuSensor.is_calibrating())
    pros::delay(15);

  //fb hold for auton 
  fourBarMotor.setBrakeMode(AbstractMotor::brakeMode::hold);

  clawMech.set_value(true);
  goalCover.set_value(false);

  pros::lcd::initialize();

  pros::lcd::set_text(0, "<< CALIBRATION COMPLETE >>");
  pros::lcd::set_text(2, WP[autoIndex]);


  while(true) {
      
      bool mode = autonSelectorA.get_value();
      bool selector = autonSelectorB.get_value();

      if (mode == 1) {
        pros::delay(200);
        modeIndex = (modeIndex + 1) % (sizeof(modes)/sizeof(modes[0]));
        autoIndex = 0;
      }

      if (selector == 1) {

        pros::delay(200);
    
        if (modeIndex == 0){
          autoIndex = (autoIndex + 1) % (sizeof(WP)/sizeof(WP[0]));
          pros::lcd::set_text(2, WP[autoIndex]);
        }
        if (modeIndex == 1){
          autoIndex = (autoIndex + 1) % (sizeof(Neutral)/sizeof(Neutral[0]));
          pros::lcd::set_text(2, Neutral[autoIndex]);
        }
        if (modeIndex == 2){
          autoIndex = (autoIndex + 1) % (sizeof(WPNeutral)/sizeof(WPNeutral[0]));
          pros::lcd::set_text(2, WPNeutral[autoIndex]);
        }
      }

      pros::lcd::set_text(1, modes[modeIndex]);


      pros::delay(20);
    }

}

void autonomous()
{



  if (modeIndex == 0){
    switch(autoIndex) {
      case (0): noAuton(); break;
      case (1): leftSideWP(normalAuto, fastAuto); break;
      case (2): rightSideWP(normalAuto, fastAuto); break;
      case (3): fullWinPoint(normalAuto, fastAuto); break;
    }
  } 

  if (modeIndex == 1){
    switch(autoIndex) {
      case (0): neutralSideRight(normalAuto, fastAuto); break;
      case (1): neutralSideLeft(normalAuto, fastAuto); break;
      case (2): neutralCenterRight(normalAuto, fastAuto); break;
      case (3): neutralCenterLeft(normalAuto, fastAuto); break;
      case (4): neutralSideCenterRight(normalAuto, fastAuto); break;
    }
  } 

  if (modeIndex == 2){
    switch(autoIndex) {
      case (0): rightWPNeutral(normalAuto, fastAuto); break;
      case (1): leftWPNeutral(normalAuto, fastAuto); break;
      case (2): rightWPTwoNeutrals(normalAuto, fastAuto); break;
    }
  }
  
  //noAuton();
}


void opcontrol()
{

  // driveR.setBrakeMode(AbstractMotor::brakeMode::coast);
  // driveL.setBrakeMode(AbstractMotor::brakeMode::coast);

  while (1) {

    //fourBarVal = autonPotL.get(); //FOR TESTING POT VALUES
    //pros::lcd::set_text(1, std::to_string(fourBarVal)); //FOR TESTING POT VALUES

    model->tank(controller.getAnalog(okapi::ControllerAnalog::leftY), controller.getAnalog(okapi::ControllerAnalog::rightY));

    fb.claw();
    fb.liftToggle();
    t.lift2Toggle();
    in.run();
    in.reverse();

    pros::delay(20);
  }
}
