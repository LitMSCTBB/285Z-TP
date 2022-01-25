#pragma once
#include "../include/285z/initRobot.hpp"

extern std::shared_ptr<okapi::ChassisController> motion;
extern std::shared_ptr<okapi::AsyncMotionProfileController> profileController;
extern std::shared_ptr<okapi::OdomChassisController> chassisaut;

    //  **TELEOP FUNCTIONS**   //
void lcdStart();
void displayAuton();

//lift 2b
void liftUp();
void liftDown();


//   **AUTON FUNCTIONS**    //
void noAuton();
void skillsAuto(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> med, std::shared_ptr<okapi::AsyncMotionProfileController> fast);
void redLeftBlueLeft(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> med, std::shared_ptr<okapi::AsyncMotionProfileController> fast);
void redRightBlueRight(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> med, std::shared_ptr<okapi::AsyncMotionProfileController> fast);
void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> med, std::shared_ptr<okapi::AsyncMotionProfileController> fast);

const bool fwd {false};
const bool bwd {true};

void selectAuton(std::shared_ptr<okapi::AsyncMotionProfileController> slow, std::shared_ptr<okapi::AsyncMotionProfileController> medium, std::shared_ptr<okapi::AsyncMotionProfileController> fast);

/*****************************   AUX AUTONS    **********************/
void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir);
void moveIntake(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir);
