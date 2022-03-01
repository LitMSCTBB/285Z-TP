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

  move(med, 1.5_ft, fwd);
  turn(270);
  twobarDown();
  pros::delay(900); //tweak?
  move(med, 0.8_ft, bwd);
  twobarUp();
  pros::delay(1200); //tweak?

  intakeMotor.moveVelocity(-600);
  pros::delay(2000);
  intakeMotor.moveVelocity(0);

  move(med, 1.3_ft, fwd);
  turn(358);
  
  move(med, 2.5_ft, fwd);
  clawPiston.set_value(true);
  fourbarLift(2000);
  pros::delay(800); //tweak

  turn(324);
  move(fast, 7.3_ft, fwd);
  //fast->setTarget("skillsPlat", fwd);
  fourbarLift(700);
  pros::delay(800); //tweak
  clawPiston.set_value(false);
  pros::delay(850);
  fourbarLift(1800);
  pros::delay(1000);

  move(med, 2_ft, bwd);
  twobarDown();
  pros::delay(800);
  fourbarLift(0);
  pros::delay(800);
  move(med, 1.25_ft, fwd);
  pros::delay(1000);
  twobarUp();
  pros::delay(800);
  turn(150);
  move(med, 1.25_ft, fwd);
  clawPiston.set_value(true);
  fourbarLift(2000);
  pros::delay(800);
  turn(340);
  move(med, 1.75_ft, fwd);
  fourbarLift(700);
  pros::delay(800);
  clawPiston.set_value(false);

  
/*
  turn(215);
  fourbarLift(0);
  pros::delay(900);
  move(med, 9_ft, fwd);
*/
}
