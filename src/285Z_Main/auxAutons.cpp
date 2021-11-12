#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285z/initSensors.hpp"

// std::shared_ptr<okapi::ChassisController> motion =
//     ChassisControllerBuilder()
//         .withMotors({frontLeftPort, backLeftPort}, {frontRightPort, backRightPort})
//         .withDimensions(AbstractMotor::gearset::green, scales)
//         .withMaxVelocity(200)
//         .build();
// std::shared_ptr<okapi::AsyncMotionProfileController> profileController = AsyncMotionProfileControllerBuilder().withLimits({0.5, 2.0, 10.0}).withOutput(motion).buildMotionProfileController();

// void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir){
//   profile->generatePath({
//     {0_ft,0_ft,0_deg},
//     {distance, 0_ft,0_deg}},
//     "M"
//   );

//   profile->setTarget("M", dir);
//   profile->waitUntilSettled();
//   profile->removePath("M");
// }

//****************** SKILLS ***********************************//
void skillsAuto() {
  pros::delay(15000);
}

void noAuton() {
  pros::delay(15000);
}
