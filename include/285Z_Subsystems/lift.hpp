#pragma once
#include "main.h"
#include "../include/285z/initRobot.hpp"

extern std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarControllerL;
extern std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarControllerR;
extern std::shared_ptr<okapi::AsyncPositionController<double, double>> twoBarController;

class Tilter
{

public:
  void up();
  void down();
  void liftToggle();
};

class FourBar
{

public:
  void liftToggle();
  void deploy();
  void move(int);
  void moveTo(int);
  void claw();
  void down();
  void lift(double);
};
