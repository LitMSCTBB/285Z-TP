#include "../include/285z/initRobot.hpp"

okapi::Controller controller;

okapi::ControllerButton intakeButton = okapi::ControllerDigital::R2;
okapi::ControllerButton intakeReverse = okapi::ControllerDigital::right;
okapi::ControllerButton clawButton = okapi::ControllerDigital::Y;
okapi::ControllerButton tilterButton = okapi::ControllerDigital::L2;
okapi::ControllerButton parkingBrakeButton = okapi::ControllerDigital::X;
okapi::ControllerButton fbUpButton = okapi::ControllerDigital::R1;
okapi::ControllerButton fbDownButton = okapi::ControllerDigital::L1;


//drive motor points
int rightFrontPort = 18; 
int rightMiddlePort = 7; 
int rightBackPort = 8;

int leftFrontPort = -20;
int leftMiddlePort = -9;
int leftBackPort = -10;

int fourBarPort = 17;
int intakePort = 16;

Motor rightFrontMotor(rightFrontPort);
Motor rightMiddleMotor(rightMiddlePort);
Motor rightBackMotor(rightBackPort);

Motor leftFrontMotor(leftFrontPort);
Motor leftMiddleMotor(leftMiddlePort);
Motor leftBackMotor(leftBackPort);

Motor fourBarMotor(fourBarPort);
Motor intakeMotor(intakePort);


MotorGroup driveL({leftFrontPort, leftMiddlePort, leftBackPort});
MotorGroup driveR({rightFrontPort, rightMiddlePort, rightBackPort});
