#include "../include/285z/initRobot.hpp"

okapi::Controller controller;

okapi::ControllerButton intakeButton = okapi::ControllerDigital::R2;
okapi::ControllerButton intakeReverse = okapi::ControllerDigital::right;
okapi::ControllerButton clawButton = okapi::ControllerDigital::Y;
okapi::ControllerButton tilterButton = okapi::ControllerDigital::L2;
okapi::ControllerButton resettwobarButton = okapi::ControllerDigital::up;
okapi::ControllerButton parkingBrakeButton = okapi::ControllerDigital::X;
okapi::ControllerButton fbUpButton = okapi::ControllerDigital::R1;
okapi::ControllerButton fbDownButton = okapi::ControllerDigital::L1;


//drive motor points
int rightFrontPort = 18; 
int rightMiddlePort = 16; 
int rightBackPort = 17;

int leftFrontPort = -19;
int leftMiddlePort = -13;
int leftBackPort = -14;

int fourBarPort = 12;
int intakePort = 11;

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
