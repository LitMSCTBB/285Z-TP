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

void leftSideWP(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void rightSideWP(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void fullWinPoint(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void neutralSideRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void neutralSideLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void neutralCenterRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void neutralCenterLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
    std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void neutralSideCenterRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void rightWPNeutral(std::shared_ptr<okapi::AsyncMotionProfileController> med,
    std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void leftWPNeutral(std::shared_ptr<okapi::AsyncMotionProfileController> med,
    std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void rightWPTwoNeutrals(std::shared_ptr<okapi::AsyncMotionProfileController> med,
    std::shared_ptr<okapi::AsyncMotionProfileController> fast);

const bool fwd {false};
const bool bwd {true};

/*****************************   AUX AUTONS    **********************/
void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir);
void parkingBrake();
