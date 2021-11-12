#pragma once
#include "main.h"
#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"

std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarController;
std::shared_ptr<okapi::AsyncPositionController<double, double>> twoBarController;
std::shared_ptr<okapi::AsyncPositionController<double, double>> clawController;
    class TwoBar
{

public:
  void liftToggle();
  void deploy();
  void move(int);
  void moveTo(int);
};

class FourBar
{

public:
  void liftToggle();
  void deploy();
  void move(int);
  void moveTo(int);
  void claw();
};
