#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285z/initSensors.hpp"

//***************************** RED/BLUE AUTONOMOUS PROGRAMS **********************//


void redLeftBlueLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  fast->setTarget("sideLeft", fwd);
  fast->waitUntilSettled();
  clawPiston.set_value(true);
  fourbarLift(100);
  fast->setTarget("sideLeft", bwd);
  fast->waitUntilSettled();

  move(fast, 1.45_ft, fwd);
  turn(315);
  twobarDown();
  pros::delay(500);
  move(med, 2.5_ft, bwd);
  twobarUp();
  pros::delay(1200);

  intakeMotor.moveVelocity(-600);
  pros::delay(2500);
  intakeMotor.moveVelocity(0);

}



void redRightBlueRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  fast->setTarget("sideRight", fwd);
  fast->waitUntilSettled();
  clawPiston.set_value(true);
  fourbarLift(100);
  fast->setTarget("sideRight", bwd);
  fast->waitUntilSettled();

  //grab alliance
  move(fast, 1.45_ft, fwd);
  turn(270);
  clawPiston.set_value(false);
  twobarDown();
  pros::delay(900);
  move(med, 1.3_ft, bwd);
  twobarUp();
  pros::delay(1200);

  // scoring
  intakeMotor.moveVelocity(-600);
  pros::delay(2500);
  intakeMotor.moveVelocity(0);

}



void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //liftDown();
  move(fast, 0.1_ft, bwd);
  fourbarDown();
  intakeMotor.moveVelocity(-600);
  pros::delay(2500);
  intakeMotor.moveVelocity(0);
  twobarDown();
  move(fast, 0.1_ft, fwd);

  turn(315);
  move(fast, 5.5_ft, bwd);
  turn(45);
  move(fast, 12_ft, bwd);
  twobarUp();
  intakeMotor.moveVelocity(-600);
  pros::delay(2500);
  intakeMotor.moveVelocity(0);
  twobarDown();
  move(fast, 0.1_ft, fwd);

}



void neutralSide(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  fast->setTarget("sideLeft", fwd);
  fast->waitUntilSettled();
  clawPiston.set_value(true);

  fast->setTarget("sideLeft", bwd);
  fast->waitUntilSettled();

  fast->removePath("sideLeft");
  clawPiston.set_value(false);
}



void neutralCenter(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  move(fast, 12_ft, fwd);
  clawPiston.set_value(true);
  move(fast, 13_ft, bwd);
  clawPiston.set_value(false);
}



void neutralSideCenter(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  fast->setTarget("sideRight", fwd);
  fast->waitUntilSettled();
  clawPiston.set_value(true);
  move(fast, 7.4_ft, bwd);

  fast->removePath("sideRight");
  clawPiston.set_value(false);

  turn(345);

  fast->setTarget("sideLeft", fwd);
  fast->waitUntilSettled();
  clawPiston.set_value(true);

  fast->setTarget("sideLeft", bwd);
  fast->waitUntilSettled();

  fast->removePath("sideLeft");
  clawPiston.set_value(false);

}
