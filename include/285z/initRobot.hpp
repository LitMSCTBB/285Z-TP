#pragma once
#include "main.h"

//Controller
extern Controller controller;
// extern std::shared_ptr<okapi::ChassisModel> model;
//GUI
int GUI();
void flat();

//Controller Buttons
extern ControllerButton stopPIDButton;

//drive motor points
extern int frontLeftPort;
extern int backLeftPort;
extern int frontRightPort;
extern int backRightPort;

//Drivetrain motors
extern Motor frontLeftMotor;
extern Motor backLeftMotor;
extern Motor frontRightMotor;
extern Motor backRightMotor;

//Drive motor groups
extern MotorGroup driveL;
extern MotorGroup driveR;

extern ChassisScales scales;

//Chassis controllers
extern std::shared_ptr<okapi::OdomChassisController> chassisaut;

extern ChassisControllerBuilder aut;
extern ChassisControllerBuilder chassis;

//TASKS
