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

  move(fast, 1_ft, fwd);
  turn(330);
  move(med, 1.8_ft, bwd);

  intakeMotor.moveVelocity(-600);
  pros::delay(2000);
  intakeMotor.moveVelocity(0);
  move(fast, 1_ft, fwd);

}



void redRightBlueRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  clawPiston.set_value(0);

  //neutral rush
  fast->setTarget("sideRight", fwd);
  pros::delay(1160);
  clawPiston.set_value(true);
  fourbarLift(600);
  fast->waitUntilSettled();


  fast->setTarget("sideRight", bwd);
  fast->waitUntilSettled();

  //grab alliance
  move(fast, 0.6_ft, fwd);
  turn(265);
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
  pros::delay(2000);
  intakeMotor.moveVelocity(0);


}



void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  fourbarLift(700);
  clawPiston.set_value(false);
  pros::delay(900);
  move(fast, 0.5_ft, bwd);

  turn(315);
  move(fast, 2.15_ft, fwd);

  turn(180);

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {11.5_ft, 0_ft,0_deg}},
    "acrossField"
  );

  fast->setTarget("acrossField", bwd);

  pros::delay(400);
  twobarDown();

  fast->waitUntilSettled();
  pros::delay(500);
  twobarUp();
  pros::delay(700);
  intakeMotor.moveVelocity(-600);
  pros::delay(2000);
  intakeMotor.moveVelocity(0);


}



void neutralSide(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  clawPiston.set_value(0);

  //neutral rush
  fast->setTarget("sideRight", fwd);
  pros::delay(1160);
  clawPiston.set_value(true);
  fourbarLift(300);
  fast->waitUntilSettled();


  fast->setTarget("sideRight", bwd);
  fast->waitUntilSettled();

}



void neutralCenter(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  clawPiston.set_value(0);
  fast->setTarget("centerNeutral", fwd);

  pros::delay(1420);
  clawPiston.set_value(true);
  fourbarLift(600);
  fast->waitUntilSettled();

  fast->setTarget("centerNeutral", bwd);
  fast->waitUntilSettled();

  fourbarLift(0);
  clawPiston.set_value(false);

}



void neutralSideCenter(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  clawPiston.set_value(0);


  fast->setTarget("sideRight", fwd);
  fast->waitUntilSettled();
  clawPiston.set_value(true);
  fourbarLift(600);

  fast->setTarget("sideRight", bwd);
  fast->waitUntilSettled();

  turn(25);
  fourbarLift(0);
  clawPiston.set_value(false);

  turn(315);

  fast->setTarget("centerNeutral", fwd);
  fast->waitUntilSettled();
  clawPiston.set_value(true);
  fourbarLift(600);

  fast->setTarget("centerNeutral", bwd);
  fast->waitUntilSettled();

  fourbarLift(0);
  clawPiston.set_value(false);

}
