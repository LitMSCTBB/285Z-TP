#include "../include/285z/initRobot.hpp"

pros::ADIDigitalOut clawMech('A');
pros::ADIDigitalOut tilter('E');
pros::Imu imuSensor(15);
pros::ADIDigitalIn autonSelector ('B');
// Potentiometer autonPotL('D');
// Potentiometer autonPotR('E');
