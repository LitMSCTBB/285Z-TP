#include "285z/initRobot.hpp"
#include "285z/functions.hpp"
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

std::shared_ptr<okapi::ChassisController> motion =
    ChassisControllerBuilder()
        .withMotors({frontLeftPort, backLeftPort}, {frontRightPort, backRightPort})
        .withDimensions(AbstractMotor::gearset::green, scales)
        .withMaxVelocity(600)
        .build();

std::shared_ptr<okapi::AsyncMotionProfileController> profileController = AsyncMotionProfileControllerBuilder().withLimits({0.5, 2.0, 10.0}).withOutput(motion).buildMotionProfileController();

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
-+
 */

void disabled() {}

void competition_initialize()
{

  pros::lcd::initialize();

  // imuSensor.reset();
  // while (imuSensor.is_calibrating())
  // {
  //   pros::delay(15);
  // }

  // pros::delay(20);

  // while (true)
  // {
  //   if (autoSelectorLeft.get_value() and !isPressed)
  //   {
  //     if (i > 0)
  //     {
  //       i = (i-1) % 6;
  //       isPressed = true;
  //     }
  //   }
  //   else if (autoSelectorRight.get_value() and !isPressed)
  //   {
  //     if (i < 6)
  //     {
  //       i = (i+1) % 6;
  //       isPressed = true;
  //     }
  //   }
  //   else if (!autoSelectorLeft.get_value() && !autoSelectorRight.get_value())
  //   {
  //     isPressed = false;
  //   }

  //   pros::lcd::set_text(1, autStringList[i]);
  //   pros::delay(30);
  // }
}

void autonomous()
{
  blueLeft(profileController);
  // switch(i) {
  //   case 0:
  //     redLeft(profileController);
  //     break;
  //   case 1:
  //     redRight(profileController);
  //     break;
  //   case 2:
  //     blueLeft(profileController);
  //     break;
  //   case 3:
  //     blueRight(profileController);
  //     break;
  //   case 4:
  //     noAuton();
  //     break;
  //   case 5:
  //     skillsAuto();
  //     break;
  // }
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
    pros::lcd::print(1, "Lift: hi");

    tb.liftToggle();
    chassisaut->getModel()->arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightX));
    fb.liftToggle();
    fb.claw();
    in.run();

    pros::delay(20);
  }
}