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
extern ControllerButton tilterButton;
extern ControllerButton resettwobarButton;
extern ControllerButton parkingBrakeButton;

//drive motor points
extern int rightFrontPort;
extern int rightMiddlePort;
extern int rightBackPort;
extern int leftFrontPort;
extern int leftMiddlePort;
extern int leftBackPort;
extern int fourBarPort;
extern int intakePort;

//Motors
extern Motor rightFrontMotor;
extern Motor rightMiddleMotor;
extern Motor rightBackMotor;
extern Motor leftFrontMotor;
extern Motor leftMiddleMotor;
extern Motor leftBackMotor;
extern Motor fourBarMotor;
extern Motor intakeMotor;

//Drive motor groups
extern MotorGroup driveL;
extern MotorGroup driveR;

extern std::shared_ptr<okapi::ChassisController> PIDchassis;
extern std::shared_ptr<okapi::ChassisController> PIDchassisGoal;
