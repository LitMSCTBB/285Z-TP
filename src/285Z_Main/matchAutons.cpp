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
  clawPiston.set_value(0);
  pros::delay(1300);
  clawPiston.set_value(true);
  fourbarLift(200);
  fast->waitUntilSettled();

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

  //neutral rush
  fast->setTarget("sideRight", fwd);
  clawPiston.set_value(0);
  pros::delay(1180);
  clawPiston.set_value(true);
  fast->waitUntilSettled();

  fast->setTarget("sideRight", bwd);
  fourbarLift(200);
  fast->waitUntilSettled();

  //grab alliance
  move(fast, 0.8_ft, fwd);
  turn(268);
  move(med, 1_ft, fwd);
  fourbarLift(0);
  clawPiston.set_value(false);
  twobarDown();
  pros::delay(900);
  move(med, 1.65_ft, bwd);
  twobarUp();
  pros::delay(1200);

  // scoring
  intakeMotor.moveVelocity(-600);
  pros::delay(2000);
  intakeMotor.moveVelocity(0);
  move(fast, 2_ft, fwd);

}



void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  fourbarLift(1050);
  move(fast, 0.3_ft, fwd);
  pros::delay(200);
  clawPiston.set_value(false);
  pros::delay(600);
  move(fast, 0.8_ft, bwd);

  turn(315);
  move(fast, 2.15_ft, fwd);

  turn(180);

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {12.4_ft, 0_ft,0_deg}},
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
  move(fast, 2_ft, fwd);

}



void neutralSideRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  fast->setTarget("sideRight", fwd);
  clawPiston.set_value(0);
  pros::delay(1180);
  clawPiston.set_value(true);
  fast->waitUntilSettled();

  fast->setTarget("sideRight", bwd);
  fourbarLift(200);
  fast->waitUntilSettled();

}

void neutralSideLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
  {
    //neutral rush
    fast->setTarget("sideLeft", fwd);
    clawPiston.set_value(0);
    pros::delay(1300);
    clawPiston.set_value(true);
    fast->waitUntilSettled();

    fast->setTarget("sideLeft", bwd);
    fourbarLift(200);
    fast->waitUntilSettled();

  }



void neutralCenterRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  fast->setTarget("centerNeutral", fwd);
  clawPiston.set_value(0);
  pros::delay(1420);
  clawPiston.set_value(true);
  fast->waitUntilSettled();

  fast->setTarget("centerNeutral", bwd);
  fourbarLift(200);

  fast->waitUntilSettled();

  fourbarLift(0);
  clawPiston.set_value(false);

}

void neutralCenterLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
  {
    fast->setTarget("centerNeutralLeft", fwd);
    clawPiston.set_value(0);
    intakeMotor.moveVelocity(-600);
    pros::delay(1520);
    clawPiston.set_value(true);

    fast->waitUntilSettled();

    fast->setTarget("centerNeutralLeft", bwd);
    fourbarLift(200);
    intakeMotor.moveVelocity(0);
    fast->waitUntilSettled();

    fourbarLift(0);
    clawPiston.set_value(false);

  }


void neutralSideCenterRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  fast->setTarget("sideRight", fwd);
  clawPiston.set_value(0);
  pros::delay(1160);
  clawPiston.set_value(true);
  fourbarLift(200);
  fast->waitUntilSettled();


  fast->setTarget("sideRight", bwd);
  fast->waitUntilSettled();

  turn(315);

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

void neutralSideCenterLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
   std::shared_ptr<okapi::AsyncMotionProfileController> fast)
   {
     fast->setTarget("sideLeft", fwd);
     clawPiston.set_value(0);
     pros::delay(1160);
     clawPiston.set_value(true);
     fourbarLift(200);
     fast->waitUntilSettled();

     fast->setTarget("centerNeutralLeft", fwd);
     pros::delay(1420);
     clawPiston.set_value(true);
     fourbarLift(600);
     fast->waitUntilSettled();

     fast->setTarget("centerNeutralLeft", bwd);
     fast->waitUntilSettled();

     fourbarLift(0);
     clawPiston.set_value(0);
   }
