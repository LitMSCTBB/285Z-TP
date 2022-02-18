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

  clawPiston.set_value(0);

  //neutral rush
  fast->setTarget("sideLeft", fwd);
  fast->waitUntilSettled();
  clawPiston.set_value(true);
  fourbarLift(600);
  fast->setTarget("sideLeft", bwd);
  fast->waitUntilSettled();

  move(fast, 1.3_ft, fwd);
  turn(319);
  move(med, 2.2_ft, bwd);

  intakeMotor.moveVelocity(-600);
  pros::delay(2000);
  intakeMotor.moveVelocity(0);

}



void redRightBlueRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  clawPiston.set_value(0);

  //neutral rush
  fast->setTarget("sideRight", fwd);
  fast->waitUntilSettled();
  clawPiston.set_value(true);
  fourbarLift(600);
  fast->setTarget("sideRight", bwd);
  fast->waitUntilSettled();

  //grab alliance
  move(fast, 0.6_ft, fwd);
  turn(267);
  move(med, 1_ft, fwd);
  fourbarLift(0);
  clawPiston.set_value(false);
  twobarDown();
  pros::delay(900);
  move(med, 1.55_ft, bwd);
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
  move(fast, 0.1_ft, fwd);
  fourbarLift(400);
  clawPiston.set_value(false);

  turn(315);
  move(fast, 3_ft, bwd);
  turn(45);
  move(fast, 8_ft, bwd);
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

  clawPiston.set_value(0);

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

  clawPiston.set_value(0);

  move(fast, 4_ft, fwd);
  clawPiston.set_value(true);
  move(fast, 3.8_ft, bwd);
  clawPiston.set_value(false);
}



void neutralSideCenter(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  clawPiston.set_value(0);

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
