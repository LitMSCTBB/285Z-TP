#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285Z_Subsystems/intake.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285z/initSensors.hpp"



//***************************** RED/BLUE AUTONOMOUS PROGRAMS **********************//

void leftSideWP(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  // neutral rush
  PIDchassis->moveDistanceAsync(4.2_ft);
  clawMech.set_value(false);
  goalCover.set_value(true);
  pros::delay(1000);
  clawMech.set_value(true);
  PIDchassis->stop();
  PIDchassis->moveDistance(-4.6_ft);
  goalCover.set_value(false);


  //left win point
  turn(300);
  move(med, 1.5_ft, bwd);
  t.grab();

  intakeMotor.moveVelocity(-500);
  pros::delay(2000);
  intakeMotor.moveVelocity(0);
  move(fast, 1_ft, fwd);

  // go for left cross
  turn(90);
  PIDchassisGoal->moveDistanceAsync(1.5_ft);
  pros::delay(2000);
  intakeMotor.moveVelocity(0);
  PIDchassisGoal->stop();

  goalCover.set_value(0);

}



void rightSideWP(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
   PIDchassis->moveDistanceAsync(3.9_ft);
  clawMech.set_value(false);
  goalCover.set_value(true);
  pros::delay(860);
  clawMech.set_value(true);
  PIDchassis->stop();
  PIDchassis->moveDistance(-4.6_ft);
  PIDchassis->stop();


  //grab alliance
  turn(269);
  t.release();
  pros::delay(900);
  move(med, 0.8_ft, bwd);
  t.grab();
  pros::delay(950);


  // scoring preloads
  fb.lift(150);
  intakeMotor.moveVelocity(-500);
  pros::delay(950);
  intakeMotor.moveVelocity(0);
  turn(0);


  //getting row of rings
  med->generatePath({
    {0_ft,0_ft, 0_deg},
    {3_ft, 0_ft, 0_deg}},
    "rightRings"
  );
  med->setTarget("rightRings", fwd);

  intakeMotor.moveVelocity(-600);

  med->waitUntilSettled();
  intakeMotor.moveVelocity(0);

  move(fast, 4.6_ft, bwd);
  fb.lift(0);
}



void fullWinPoint(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  fb.lift(1050);
  move(fast, 0.3_ft, fwd);
  pros::delay(200);
  clawMech.set_value(false);
  pros::delay(600);
  move(fast, 0.8_ft, bwd);

  turn(315);
  move(fast, 2.15_ft, fwd);

  turn(182);

  fast->generatePath({
    {0_ft,0_ft,0_deg},
    {12.4_ft, 0_ft,0_deg}},
    "acrossField"
  );

  fast->setTarget("acrossField", bwd);

  pros::delay(400);
  //twobarDown();

  fast->waitUntilSettled();
  pros::delay(500);
  //twobarUp();
  pros::delay(700);
  intakeMotor.moveVelocity(-600);
  pros::delay(2000);
  intakeMotor.moveVelocity(0);
  move(fast, 2_ft, fwd);
}



void neutralSideRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

// neutral rush
   PIDchassis->moveDistanceAsync(3.9_ft);
  clawMech.set_value(false);
  goalCover.set_value(true);
  pros::delay(860);
  clawMech.set_value(true);
  PIDchassis->stop();
  PIDchassis->moveDistance(-4.6_ft);
  PIDchassis->stop();
  goalCover.set_value(false);

}

void neutralSideLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  PIDchassis->moveDistanceAsync(4.2_ft);

  clawMech.set_value(0);
  goalCover.set_value(1);
  pros::delay(1100);
  clawMech.set_value(true);

  PIDchassis->stop();
  fb.lift(150);
  PIDchassisGoal->moveDistance(-4.6_ft);
  PIDchassisGoal->stop();
  goalCover.set_value(0);
}



void neutralCenterRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  PIDchassis->moveDistanceAsync(6.4_ft);

  clawMech.set_value(0);
  pros::delay(1270);
  clawMech.set_value(true);

  PIDchassis->stop();
  fb.lift(200);
  PIDchassisGoal->moveDistance(-6.5_ft);
}

void neutralCenterLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  PIDchassis->moveDistanceAsync(7.5_ft);

  clawMech.set_value(0);
  pros::delay(1400);
  clawMech.set_value(true);

  PIDchassis->stop();
  fb.lift(150);
  PIDchassisGoal->moveDistance(-7_ft);
}


void neutralSideCenterRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  PIDchassis->moveDistanceAsync(4.3_ft);
  clawMech.set_value(0);
  pros::delay(1180); //old value: 1180
  clawMech.set_value(true);
  fb.lift(200);

  PIDchassis->moveDistance(-4.3_ft);

  turn(45);
  clawMech.set_value(false);
  turn(330);

  fast->setTarget("centerNeutral", fwd);
  pros::delay(1420);
  clawMech.set_value(true);
  fast->waitUntilSettled();

  fast->setTarget("centerNeutral", bwd);
  fb.lift(200);

  fast->waitUntilSettled();

  fb.lift(0);
  clawMech.set_value(false);
}

void rightWPNeutral(std::shared_ptr<okapi::AsyncMotionProfileController> med,
   std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  PIDchassis->moveDistanceAsync(3.75_ft);

  clawMech.set_value(0);
  pros::delay(900);
  clawMech.set_value(true);

  PIDchassis->stop();
  PIDchassisGoal->moveDistance(-3_ft);

  fast->setTarget("centerNeutralLeft", fwd);
  pros::delay(1420);
  clawMech.set_value(true);
  fb.lift(600);
  fast->waitUntilSettled();

  fast->setTarget("centerNeutralLeft", bwd);
  fast->waitUntilSettled();

  fb.lift(0);
  clawMech.set_value(0);
}

void leftWPNeutral(std::shared_ptr<okapi::AsyncMotionProfileController> med,
   std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

}

  void rightWPTwoNeutrals(std::shared_ptr<okapi::AsyncMotionProfileController> med,
   std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

}