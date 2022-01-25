#pragma once
#include "../include/285z/initRobot.hpp"

extern std::shared_ptr<okapi::ChassisController> motion;
extern std::shared_ptr<okapi::AsyncMotionProfileController> profileController;
extern std::shared_ptr<okapi::OdomChassisController> chassisaut;

    //  **TELEOP FUNCTIONS**   //
void lcdStart();
void displayAuton();
//Drive
void tankDrive();

//Intake
void toggleIntake();
void intakeRev();

//Lift
void liftControl();
void liftUp();
void liftDown();
void liftToggle();
void liftPID();

//MANUAL LIFT CONTROL
void liftManual();
void liftManualUp();
void liftManualDown();
void liftManualStop();


void liftPositionToggleFunction();

//OP MACROS
void robotDeploy();
void stackDeploy();

//   **AUTON FUNCTIONS**    //
void blueLeft(std::shared_ptr<okapi::AsyncMotionProfileController> profileController);
void blueRight(std::shared_ptr<okapi::AsyncMotionProfileController> profileController);
void redLeft(std::shared_ptr<okapi::AsyncMotionProfileController> profileController);
void redRight(std::shared_ptr<okapi::AsyncMotionProfileController> profileController);
void noAuton();
void skillsAuto(std::shared_ptr<okapi::AsyncMotionProfileController> profileController);

const bool fwd {false};
const bool bwd {true};

void selectAuton(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast);

/*****************************   AUX AUTONS    **********************/
void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir);
