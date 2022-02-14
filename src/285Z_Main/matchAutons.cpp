#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285z/initSensors.hpp"
using namespace std;

//***************************** RED/BLUE AUTONOMOUS PROGRAMS **********************//

void redLeftBlueLeft(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
  std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  // //neutral rush
  // moveProfile(fast, "0", dirs[0]);
  // clawPiston.set_value(true);
  // moveProfile(fast, "1", dirs[1]);

  // turn(330);
  // liftDown();
  // pros::delay(500);
  // moveProfile(slow, "2", dirs[2]);
  // liftUp();
  // intakeMotor.moveVelocity(-600);
  // pros::delay(2500);
  // intakeMotor.moveVelocity(0);

  // neutral rush
  move(fast, 10_ft, fwd);
  clawPiston.set_value(true);
  move(fast, 5_ft, bwd);

  turn(335);
  liftDown();
  pros::delay(500);
  move(med, 3_ft, bwd);
  liftUp();
  pros::delay(1200);

  intakeMotor.moveVelocity(-600);
  pros::delay(2500);
  intakeMotor.moveVelocity(0);
}
void redRightBlueRight(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
  std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  // neutral rush
  move(fast, 9.4_ft, fwd);
  clawPiston.set_value(true);
  move(fast, 7.35_ft, bwd);

  // facing alliance
  turn(270);
  move(fast, 1.67_ft, fwd);
  clawPiston.set_value(false);
  liftDown();
  pros::delay(800);
  move(med, 3.65_ft, bwd);
  liftUp();
  pros::delay(1200);

  // scoring on alliance
  intakeMotor.moveVelocity(-200);
  pros::delay(2500);
  intakeMotor.moveVelocity(0);


}

void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
  std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  liftDown();
  move(fast, 0.1_ft, bwd);
  liftUp();
  intakeMotor.moveVelocity(-600);
  pros::delay(2500);
  intakeMotor.moveVelocity(0);
  liftDown();
  move(fast, 0.1_ft, fwd);

  turn(315);
  move(fast, 5.5_ft, bwd);
  turn(45);
  move(fast, 12_ft, bwd);
  liftUp();
  intakeMotor.moveVelocity(-600);
  pros::delay(2500);
  intakeMotor.moveVelocity(0);
  liftDown();
  move(fast, 0.1_ft, fwd);

}

void neutralSide(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
  std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  move(fast, 9.55_ft, fwd);
  clawPiston.set_value(true);
  move(fast, 10_ft, bwd);
}

void neutralCenter(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
  std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  move(fast, 10.5_ft, fwd);
  clawPiston.set_value(true);
  move(fast, 10_ft, bwd);
}

void neutralSideCenter(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
  std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  move(fast, 9.55_ft, fwd);
  clawPiston.set_value(true);

}
