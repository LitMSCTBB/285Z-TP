#include "285z/initRobot.hpp"
#include "285z/functions.hpp"
#include "285Z_Subsystems/tray.hpp"
#include "285Z_Subsystems/lift.hpp"
#include "285Z_Subsystems/pid.hpp"
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

}

void opcontrol()
{

  while (1)
  {

    chassisaut->getModel()->tank(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightY));

    pros::lcd::set_text(1, "hi");
    pros::delay(20);
    
  }
}
