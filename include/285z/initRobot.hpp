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
extern ControllerButton parkingBrakeButton;

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
extern Motor fourBarMotor1;
extern Motor fourBarMotor2;
extern Motor twoBarMotor;
extern Motor intakeMotor;

//Drive motor groups
extern MotorGroup driveL;
extern MotorGroup driveR;

// extern std::shared_ptr<okapi::AsyncMotionProfileController> fastAuto;
// extern std::shared_ptr<okapi::AsyncMotionProfileController> normalAuto;
// extern okapi::ChassisControllerBuilder chassis;
