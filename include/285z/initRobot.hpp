#pragma once
#include "main.h"

//Controller
extern Controller controller;

//Controller Button
extern ControllerButton intakeButton;
extern ControllerButton intakeReverse;
extern ControllerButton clawButton;
extern ControllerButton fourBarNormal;
extern ControllerButton fourBarReverse;
extern ControllerButton twoBarButton;
extern ControllerButton resettwobarButton;

//drive motor points
extern int frontLeftPort;
extern int backLeftPort;
extern int frontRightPort;
extern int backRightPort;
extern int fourBarPortLeft;
extern int twoBarPort;
extern int fourBarPortRight;
extern int intakePort;

//Motors
extern Motor frontLeftMotor;
extern Motor backLeftMotor;
extern Motor frontRightMotor;
extern Motor backRightMotor;
extern pros::Motor fourBarMotor1;
extern pros::Motor fourBarMotor2;
extern Motor twoBarMotor;
extern Motor intakeMotor;

//Drive motor groups
extern MotorGroup driveL;
extern MotorGroup driveR;
