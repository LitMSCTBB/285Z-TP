#include "../include/285z/initRobot.hpp"

okapi::Controller controller;

okapi::ControllerButton intakeButton = okapi::ControllerDigital::R2;
okapi::ControllerButton intakeReverse = okapi::ControllerDigital::right;
okapi::ControllerButton clawButton = okapi::ControllerDigital::Y;
okapi::ControllerButton fourBarReverse = okapi::ControllerDigital::L1;
okapi::ControllerButton fourBarNormal = okapi::ControllerDigital::R1;
okapi::ControllerButton twoBarButton = okapi::ControllerDigital::L2;
okapi::ControllerButton resettwobarButton = okapi::ControllerDigital::up;


//drive motor points
int frontLeftPort = -18; //reversed
int backLeftPort = -20; //reversed
int frontRightPort = 17;
int backRightPort = 19;

int fourBarPortLeft = -13;
int twoBarPort = 14;
int fourBarPortRight = 12;
int intakePort = 11;

Motor frontLeftMotor(frontLeftPort);
Motor backLeftMotor(backLeftPort);
Motor frontRightMotor(frontRightPort);
Motor backRightMotor(backRightPort);
Motor fourBarMotor1(fourBarPortLeft);
Motor fourBarMotor2(fourBarPortRight);
Motor twoBarMotor(twoBarPort);
Motor intakeMotor(intakePort);

MotorGroup driveL({frontLeftPort, backLeftPort});
MotorGroup driveR({frontRightPort, backRightPort});
