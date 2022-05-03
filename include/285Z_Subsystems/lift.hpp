#pragma once
#include "main.h"
#include "../include/285z/initRobot.hpp"

extern std::shared_ptr<okapi::AsyncPositionController<double, double>> fourBarController;

class Tilter
{
  public:
    void grab();
    void release();
    void lift2Toggle();
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

extern Tilter t;
extern FourBar fb;