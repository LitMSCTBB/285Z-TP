#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285z/initSensors.hpp"

//***************************** RED/BLUE AUTONOMOUS PROGRAMS **********************//

void redLeftBlueLeft(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
  std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  move(fast, 10_ft, fwd);
  clawPiston.set_value(true);
  move(fast, 8_ft, bwd);

}
void redRightBlueRight(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
  std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
    //neutral rush
    move(fast, 9.55_ft, fwd);
    clawPiston.set_value(true);
    move(fast, 8.5_ft, bwd);


    //facing alliance
    turn(270);
    move(fast, 1.67_ft, fwd);
    clawPiston.set_value(false);
    liftDown();
    pros::delay(800);
    move(med, 3.65_ft, bwd);
    liftUp();
    pros::delay(1200);

    //scoring on alliance
    intakeMotor.moveVelocity(-600);
    pros::delay(2500);
    intakeMotor.moveVelocity(0);
}

void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
  std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  pros::delay(15000);

}

void newRedLeftBlueLeft(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
                     std::shared_ptr<okapi::AsyncMotionProfileController> med,
                     std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  /*
  chassisaut->turnAngle(-20_deg);
  twoBarController->setTarget(-3100);
  pros::delay(1500);
  move(profileController, 0.4_ft, bwd);
  pros::delay(1500);
  twoBarController->setTarget(-1495);
  pros::delay(1500);
  move(profileController, 0.35_ft, fwd);
  pros::delay(1500);
  intakeMotor.moveVoltage(9500);
  */
  move(fast, 13.5_ft, fwd);
  move(med, 2.4_ft, fwd);
  clawPiston.set_value(true);
  turn(-12);
  move(fast, 13.5_ft, bwd);
}