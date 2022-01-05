#include "../include/285z/initRobot.hpp"

okapi::Controller controller;

okapi::ControllerButton intakeButton = okapi::ControllerDigital::R1;
okapi::ControllerButton clawButton = okapi::ControllerDigital::Y;
okapi::ControllerButton fourBarReverse = okapi::ControllerDigital::L1;
okapi::ControllerButton fourBarNormal = okapi::ControllerDigital::L2;
okapi::ControllerButton twoBarButton = okapi::ControllerDigital::right;

//drive motor points
int frontLeftPort = -4; //reversed
int backLeftPort = -2; //reversed
int frontRightPort = 3; 
int backRightPort = 1;

int fourBarPort = 11;
int twoBarPort = 8;
int intakePort = 16;
int clawPort = 20;

Motor frontLeftMotor(frontLeftPort);
Motor backLeftMotor(backLeftPort);
Motor frontRightMotor(frontRightPort);
Motor backRightMotor(backRightPort);
Motor fourBarMotor(fourBarPort);
Motor twoBarMotor(twoBarPort);
Motor intakeMotor(intakePort);

MotorGroup driveL({frontLeftPort, backLeftPort});
MotorGroup driveR({frontRightPort, backRightPort});

okapi::ChassisScales scales{
    //4.125 is the wheelsize and 9.75 is the wheelbase
    {4.125_in, 11.5_in}, //dimensions of the chassis
    imev5BlueTPR};

//**************** INITIALIZE CHASSIS FOR TELEOP ***********************//

// auto chassis = okapi::ChassisControllerBuilder()
//     .withMotors({frontLeftPort,backLeftPort}, {frontRightPort,backRightPort}) // left motor is 1, right motor is 2 (reversed)
//     .withDimensions(AbstractMotor::gearset::green, {{4.125_in, 9.75_in}, imev5GreenTPR})
//     .withMaxVelocity(200)
//     .build(); // build an odometry chassis
