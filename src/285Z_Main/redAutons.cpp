#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"
#include "../include/285Z_Subsystems/pid.hpp"


//*****************************   RED AUTONOMOUS    **********************//

auto profileController = AsyncMotionProfileControllerBuilder().withLimits({0.5, 2.0, 10.0}).withOutput(motion).buildMotionProfileController();
auto motion =
    ChassisControllerBuilder()
        .withMotors({frontLeftPort, backLeftPort}, {frontRightPort, backRightPort})
        .withDimensions(AbstractMotor::gearset::green, scales)
        .withMaxVelocity(200)
        .build();


void redLeft(){


}
void redRight(){

  twoBarController->setTarget(-3000);
  move(profileController, 6_ft, false);
  fourBarController->setTarget(-4700); clawController->setTarget(-120);
  move(profileController, 3_ft, true);
  turn(90.0);
  move(profileController, 2_ft, true);
  twoBarController->setTarget(-1400);
  intakeMotor.moveRelative(100, 100);
}
