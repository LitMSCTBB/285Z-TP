#include "../include/285z/initRobot.hpp"

pros::ADIDigitalOut clawMech('A');
pros::ADIDigitalOut tilter('B');
pros::ADIDigitalOut cover('G');
pros::Imu imuSensor(15);
pros::ADIDigitalIn autonSelector ('D');
Potentiometer pot('C');
// Potentiometer autonPotR('E');
