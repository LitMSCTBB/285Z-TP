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
  t.release();
  move(med, 0.8_ft, bwd);
  t.grab();
  pros::delay(600);
  intakeMotor.moveVelocity(600);
  pros::delay(700);

  fb.lift(400);

  for (int i = 0; i < 2; i++) {
    move(med, 1.4_ft, fwd);
    move(med, 1.4_ft, bwd);
  }

  move(med, 1.4_ft, fwd);
  move(med, 1.2_ft, bwd);

  intakeMotor.moveVelocity(0);
  t.release();
  move(fast, 0.7_ft, fwd);


}



void rightSideWP(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //move to center onto alliance goal
  move(fast, 1.5_ft, fwd);

  //grab alliance
  turn(267);
  t.release();
  pros::delay(700);
  move(fast, 1.6_ft, bwd);
  t.grab();
  pros::delay(700);


  // scoring preloads
  fb.lift(400);
  intakeMotor.moveVelocity(500);
  pros::delay(950);
  intakeMotor.moveVelocity(0);
  move(fast, 0.5_ft, fwd);
  turn(357);


  //getting row of rings
  intakeMotor.moveVelocity(600);
  move(med, 4.5_ft, fwd);
  move(fast, 5.7_ft, bwd);
  intakeMotor.moveVelocity(0);

  t.release();
  pros::delay(500);
  move(fast, 0.5_ft, fwd);


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
  PIDchassis->moveDistanceAsync(4.2_ft);
  clawMech.set_value(false);
  goalCover.set_value(true);
  pros::delay(860);
  clawMech.set_value(true);
  PIDchassis->stop();
  PIDchassis->moveDistance(-4_ft);
  PIDchassis->stop();
  goalCover.set_value(false);

}

void neutralSideLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  PIDchassis->moveDistanceAsync(4.2_ft);

  goalCover.set_value(1);
  clawMech.set_value(0);
  pros::delay(970);
  clawMech.set_value(true);

  PIDchassis->stop();

  PIDchassisGoal->moveDistance(-4.0_ft);
  PIDchassisGoal->stop();
  goalCover.set_value(0);
}



void neutralCenterRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  intakeMotor.moveVelocity(600);
  PIDchassis->moveDistanceAsync(7_ft); //maybe 5.7_ft?

  clawMech.set_value(0);
  pros::delay(1270);
  clawMech.set_value(true);

  PIDchassis->stop();
  fb.lift(200);
  PIDchassisGoal->moveDistance(-7.2_ft);
  intakeMotor.moveVelocity(0);
}

void neutralCenterLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  intakeMotor.moveVelocity(600);
  PIDchassis->moveDistanceAsync(7.5_ft);

  clawMech.set_value(0);
  pros::delay(1400);
  clawMech.set_value(true);

  PIDchassis->stop();
  fb.lift(150);
  PIDchassisGoal->moveDistance(-7_ft);
  intakeMotor.moveVelocity(0);
}


void neutralSideCenterRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  PIDchassis->moveDistanceAsync(4.4_ft);
  clawMech.set_value(false);
  goalCover.set_value(true);
  pros::delay(860);
  clawMech.set_value(true);
  PIDchassis->stop();
  PIDchassis->moveDistance(-4_ft);
  PIDchassis->stop();
  goalCover.set_value(false);

  turn(45);
  clawMech.set_value(false);
  turn(330);

  intakeMotor.moveVelocity(600);
  PIDchassis->moveDistanceAsync(6.4_ft); //maybe 5.7_ft?

  clawMech.set_value(0);
  pros::delay(1270);
  clawMech.set_value(true);

  PIDchassis->stop();
  fb.lift(200);
  PIDchassisGoal->moveDistance(-6.5_ft);
  intakeMotor.moveVelocity(0);
}

void rightWPNeutral(std::shared_ptr<okapi::AsyncMotionProfileController> med,
   std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  //neutral rush
  PIDchassis->moveDistanceAsync(4.2_ft);
  clawMech.set_value(false);
  goalCover.set_value(true);
  pros::delay(860);
  clawMech.set_value(true);
  PIDchassis->stop();
  PIDchassis->moveDistance(-2.55_ft);
  PIDchassis->stop();
  goalCover.set_value(false);

  //grab alliance
  turn(267);
  t.release();
  pros::delay(700);
  move(fast, 1.6_ft, bwd);
  t.grab();
  pros::delay(700);


  // scoring preloads
  fb.lift(620);
  intakeMotor.moveVelocity(500);
  pros::delay(950);
  intakeMotor.moveVelocity(0);
  move(fast, 0.5_ft, fwd);
  turn(357);


  //getting row of rings
  intakeMotor.moveVelocity(600);
  move(med, 4.5_ft, fwd);
  move(fast, 10_ft, bwd);
  intakeMotor.moveVelocity(0);

  t.release();
  pros::delay(500);
  move(fast, 0.5_ft, fwd);
}

void leftWPNeutral(std::shared_ptr<okapi::AsyncMotionProfileController> med,
   std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
   //neutral rush
  PIDchassis->moveDistanceAsync(4.5_ft);

  goalCover.set_value(1);
  clawMech.set_value(0);
  pros::delay(950);
  clawMech.set_value(true);

  PIDchassis->stop();

  fb.lift(200);
  PIDchassisGoal->moveDistance(-4.6_ft); //mess with this
  PIDchassisGoal->stop();
  goalCover.set_value(0);

  

  turn(270); //tweak
  t.release();
  move(med, 1.5_ft, bwd); //tweak too probably
  t.grab();
  pros::delay(600);
  intakeMotor.moveVelocity(600);
  pros::delay(700);
  move(med, 1.7_ft, fwd);
  t.release();
  intakeMotor.moveVelocity(0);
}

  void rightWPTwoNeutrals(std::shared_ptr<okapi::AsyncMotionProfileController> med,
   std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

}

void neutralCenterWP(std::shared_ptr<okapi::AsyncMotionProfileController> med,
   std::shared_ptr<okapi::AsyncMotionProfileController> fast)
   {

     PIDchassis->moveDistanceAsync(6.5_ft);
     goalCover.set_value(true);
     clawMech.set_value(false);
     pros::delay(1050);
     clawMech.set_value(true);
     PIDchassis->stop();

     PIDchassis->moveDistance(-3.0_ft);
     turn(315);
     t.release();
  
    move(fast, 3.8_ft, bwd); //old is 4.4_ft
    t.grab();
    pros::delay(700);
    move(med, 1.7_ft, fwd);
    intakeMotor.moveVelocity(600);
    pros::delay(700);
    t.release();
    intakeMotor.moveVelocity(0);

    goalCover.set_value(false);

    // turn(30);
    // fb.lift(600);

    // //getting row of rings
    // intakeMotor.moveVelocity(600);
    // move(med, 4.5_ft, fwd);
    // move(fast, 5.7_ft, bwd);
    // intakeMotor.moveVelocity(0);

    // t.release();
    // pros::delay(500);
    // move(fast, 0.5_ft, fwd);
   }