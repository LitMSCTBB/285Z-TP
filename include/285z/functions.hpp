#pragma once
#include "../include/285z/initRobot.hpp"

//lift 2b
void twobarUp();
void twobarDown();
void fourbarUp();
void fourbarDown();
void fourbarLift(const double target);

//   **AUTON FUNCTIONS**    //
void noAuton();
void skillsAuto(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void redLeftBlueLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void redRightBlueRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void neutralSide(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void neutralCenter(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void neutralSideCenter(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

const bool fwd {false};
const bool bwd {true};

/*****************************   AUX AUTONS    **********************/
void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir);
