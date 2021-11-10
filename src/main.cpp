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
void disabled()
{
}

void competition_initialize()
{
  //Calibrate IMU Sensor
  while (true)
  {
    pros::delay(10);
  }
}

void autonomous()
{

  auto profileController = AsyncMotionProfileControllerBuilder().withLimits({ 0.5, 2.0, 10.0 }).withOutput(motion).buildMotionProfileController();
  profileController->generatePath({ { 0_ft, 0_ft, 0_deg }, { 10_ft, 0_ft, 0_deg }}, "A");

  profileController->setTarget("A");
  profileController->waitUntilSettled();



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

    chassisaut->getModel()->arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightY));

    tb.liftToggle();
    fb.liftToggle();
    in.run();

    pros::delay(20);

  }
}
