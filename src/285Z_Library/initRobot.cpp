#include "../include/285z/initRobot.hpp"

okapi::Controller controller;

okapi::ControllerButton buttonOne = okapi::ControllerDigital:: R2;
okapi::ControllerButton buttonTwo = okapi::ControllerDigital::R1;

okapi::ControllerButton buttonThree = okapi::ControllerDigital:: A;

okapi::ControllerButton buttonThree = okapi::ControllerDigital::L1;
okapi::ControllerButton buttonFour = okapi::ControllerDigital::L2;

okapi::ControllerButton deployButton = okapi::ControllerDigital::B;
okapi::ControllerButton startDeployButton = okapi::ControllerDigital::Y;

 //drive motor points
 int frontLeftPort = 9;
 int backLeftPort = 3;
 int frontRightPort = -8; //reversed
 int backRightPort = -1;  //reversed

 //intake motor ports
 int intakeLeftPort = 5;
 int intakeRightPort = -16;

 //LIFT MOTOR PORT
 int liftPort = 11;
 //angler motor port
 int anglerPort = 12;

 Motor frontLeftMotor(frontLeftPort);
 Motor backLeftMotor(backLeftPort);
 Motor frontRightMotor(frontRightPort);
 Motor backRightMotor(backRightPort);

 Motor intakeRightMotor(intakeRightPort);
 Motor intakeLeftMotor(intakeLeftPort);

 Motor anglerMotor(anglerPort);
 Motor liftMotor(liftPort);

//motor groups
 MotorGroup intake({intakeRightPort, intakeLeftPort});

 MotorGroup driveL({frontLeftPort, backLeftPort});
 MotorGroup driveR({frontRightPort, backRightPort});

 double wheelSize = 3.25;
 double wheelBase = 9.75; //need to measure

okapi::ChassisScales scales
{
  //3.25 is the wheelsize and 9.75 is the wheelbase
 {3.25_in, 9.75_in}, //dimensions of the chassis
 imev5GreenTPR
};

//**************** INITIALIZE CHASSIS FOR TELEOP ***********************//



// auto chassis = okapi::ChassisControllerBuilder()
//     .withMotors({frontLeftPort,backLeftPort}, {frontRightPort,backRightPort}) // left motor is 1, right motor is 2 (reversed)
//     .withDimensions(AbstractMotor::gearset::green, {{4.125_in, 9.75_in}, imev5GreenTPR})
//     .withMaxVelocity(200)
//     .build(); // build an odometry chassis
