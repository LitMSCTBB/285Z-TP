#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285z/initSensors.hpp"

//****************** SKILLS ***********************************//

void noAuton()
{

  pros::delay(15000);

}

void skillsAuto(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  clawPiston.set_value(0);


  //alliance grab + score
  move(med, 1.6_ft, fwd);
  twobarDown();
  turn(270);
  // pros::delay(700);
  move(med, 1.1_ft, bwd);
  twobarUp();
  pros::delay(900);
  intakeMotor.moveVoltage(-12000);
  pros::delay(1200);
  intakeMotor.moveVoltage(0);


  //grabbing neutral (side)
  move(fast, 1.3_ft, fwd);
  turn(0);
  fast->generatePath({
    {0_ft, 0_ft, 0_deg},
    {4_ft, 0_ft, 0_deg}},
    "first"
    );

  fast->setTarget("first", fwd);
  clawPiston.set_value(0);
  pros::delay(1100);
  clawPiston.set_value(true);
  fourbarLift(200);
  fast->waitUntilSettled();
  fourbarLift(2200);
  turn(325);


  //(side) neutral scoring on platform
  fast->generatePath({
    {0_ft, 0_ft, 0_deg},
    {7.5_ft, 0_ft, 0_deg}},
    "skillsPlat"
    );

  fast->setTarget("skillsPlat", fwd);
  intakeMotor.moveVoltage(-12000);
  pros::delay(1200);
  intakeMotor.moveVoltage(0);
  fast->waitUntilSettled();
  intakeMotor.moveVoltage(-12000);
  fourbarLift(1300);
  pros::delay(500);
  clawPiston.set_value(false);
  pros::delay(500);
  fourbarLift(1900);
  intakeMotor.moveVoltage(0);
  move(fast, 3.25_ft, bwd);
  turn(230);
  twobarDown();
  fourbarLift(0);
  pros::delay(700);

  //center neutral
  move(fast, 1.5_ft, fwd);
  clawPiston.set_value(true);
  fourbarLift(2200);
  turn(180);
  med->generatePath({
    {0_ft, 0_ft, 0_deg},
    {7.3_ft, 0_ft, 0_deg}},
    "secondpath"
    );

  med->setTarget("secondpath", fwd);
  intakeMotor.moveVoltage(-12000);
  pros::delay(1200);
  intakeMotor.moveVoltage(0);
  med->waitUntilSettled();
  intakeMotor.moveVoltage(-12000);
  fourbarLift(1300);
  pros::delay(900);
  clawPiston.set_value(false);
  pros::delay(900);
  move(med, 0.5_ft, bwd);
  pros::delay(700);
  fourbarLift(1900);
  intakeMotor.moveVoltage(0);
  twoBarController->setTarget(0);
  move(med, 1_ft, bwd);

//next side neutralSideLeft

  turn(315);

  fast->generatePath({
    {0_ft, 0_ft, 0_deg},
    {3.2_ft, 0_ft, 0_deg}},
    "thirdPath"
  );

  fast->setTarget("thirdPath", fwd);
  intakeMotor.moveVoltage(-12000);
  fourbarLift(0);
  pros::delay(1250);
  clawPiston.set_value(true);
  fast->waitUntilSettled();
  fourbarLift(2200);
  turn(38);
  move(fast, 4_ft, fwd);
  fourbarLift(1300);
  pros::delay(900);
  clawPiston.set_value(false);
  pros::delay(900);
  move(med, 0.5_ft, bwd);

/*
  turn(215);
  fourbarLift(0);
  pros::delay(900);
  move(med, 9_ft, fwd);
*/

}
