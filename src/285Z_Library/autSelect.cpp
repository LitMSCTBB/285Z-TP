#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285Z_Subsystems/intake.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Aux/gui.hpp"


void selectAuton(std::shared_ptr<okapi::AsyncMotionProfileController> profileController){

  twoBarMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
  double potVal = autonPot.get();
  if(potVal >= 0 && potVal < 819){
    //shortGoalSixRed(chassis, slow, fast);
    //sgFiveRed(profileController);
  }
  if(potVal >= 820 && potVal <= 1638){
    //sgFiveBlue(profileController);
  }
  if(potVal >= 1639 && potVal <= 2457){
    //lgRed(profileController);
  }
  if(potVal >= 2458 && potVal <= 3276){
    //lgBlue(profileController);
  }
  if(potVal >= 3277 && potVal <= 4096){
    //skills(profileController);
  }

}

//will write to the screen to say the auton
void displayAuton(){
  double potVal = autonPot.get();
  if(potVal >= 0 && potVal < 819){
    lv_aut_display("RED SHORT GOAL");
  }
  if(potVal >= 820 && potVal <= 1638){
    lv_aut_display("BLUE SHORT GOAL");
  }
  if(potVal >= 1639 && potVal <= 2457){
    lv_aut_display("RED LONG GOAL");
  }
  if(potVal >= 2458 && potVal <= 3276){
    lv_aut_display("BLUE LONG GOAL");
  }
  if(potVal >= 3277 && potVal <= 4096){
    lv_aut_display("SKILLS");
  }
}
