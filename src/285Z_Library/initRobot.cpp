#include "../include/285z/initRobot.hpp"

okapi::Controller controller;

okapi::ControllerButton intakeButton = okapi::ControllerDigital::R2;
okapi::ControllerButton intakeReverse = okapi::ControllerDigital::B;
okapi::ControllerButton clawButton = okapi::ControllerDigital::Y;
okapi::ControllerButton fourBarReverse = okapi::ControllerDigital::L1;
okapi::ControllerButton fourBarNormal = okapi::ControllerDigital::R1;
okapi::ControllerButton twoBarButton = okapi::ControllerDigital::L2;

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

okapi::ChassisScales scales{
    {4.125_in, 11.5_in}, //dimensions of the chassis
    imev5BlueTPR};

//**************** INITIALIZE CHASSIS FOR TELEOP ***********************//

// auto chassis = okapi::ChassisControllerBuilder()
//     .withMotors({frontLeftPort,backLeftPort}, {frontRightPort,backRightPort}) // left motor is 1, right motor is 2 (reversed)
//     .withDimensions(AbstractMotor::gearset::green, {{4.125_in, 9.75_in}, imev5GreenTPR})
//     .withMaxVelocity(200)
//     .build(); // build an odometry chassis
