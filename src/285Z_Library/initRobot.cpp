#include "../include/285z/initRobot.hpp"

okapi::Controller controller;

//drive motor points
int frontLeftPort = -11;
int backLeftPort = -20;
int frontRightPort = 1; //reversed
int backRightPort = 9; //reversed

Motor frontLeftMotor(frontLeftPort);
Motor backLeftMotor(backLeftPort);
Motor frontRightMotor(frontRightPort);
Motor backRightMotor(backRightPort);

MotorGroup driveL({frontLeftPort, backLeftPort});
MotorGroup driveR({frontRightPort, backRightPort});

double wheelSize = 4.125;
double wheelBase = 9.75;

okapi::ChassisScales scales{
    //4.125 is the wheelsize and 9.75 is the wheelbase
    {4.125_in, 9.75_in}, //dimensions of the chassis
    imev5GreenTPR};

//**************** INITIALIZE CHASSIS FOR TELEOP ***********************//

// auto chassis = okapi::ChassisControllerBuilder()
//     .withMotors({frontLeftPort,backLeftPort}, {frontRightPort,backRightPort}) // left motor is 1, right motor is 2 (reversed)
//     .withDimensions(AbstractMotor::gearset::green, {{4.125_in, 9.75_in}, imev5GreenTPR})
//     .withMaxVelocity(200)
//     .build(); // build an odometry chassis
