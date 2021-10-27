#pragma once
#include "main.h"
#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/tray.hpp"

extern int heightNow;

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
