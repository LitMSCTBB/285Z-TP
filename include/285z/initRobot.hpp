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
extern ControllerButton liftUpButton;
extern ControllerButton liftDownButton;
extern ControllerButton liftToggleButton;
extern ControllerButton intakeNormalButton;
extern ControllerButton intakeReverseButton;
extern ControllerButton clawButton;
extern ControllerButton fourBarButton;
extern ControllerButton twoBarButton;

//drive motor points
extern int frontLeftPort;
extern int backLeftPort;
extern int frontRightPort;
extern int backRightPort;
extern int fourBarPort;
extern int twoBarPort;
extern int intakePort;
extern int clawPort;

//Drivetrain motors
extern Motor frontLeftMotor;
extern Motor backLeftMotor;
extern Motor frontRightMotor;
extern Motor backRightMotor;
extern Motor fourBarMotor;
extern Motor twoBarMotor;
extern Motor intakeMotor;
extern Motor clawMotor;

//Drive motor groups
extern MotorGroup driveL;
extern MotorGroup driveR;

extern ChassisScales scales;

//Chassis controllers
extern std::shared_ptr<okapi::OdomChassisController> chassisaut;

extern ChassisControllerBuilder aut;
extern ChassisControllerBuilder chassis;

// TASKS
void liftTask(void *);