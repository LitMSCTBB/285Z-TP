#include "../include/285z/initRobot.hpp"
#include "285z/initSensors.hpp"

pros::Imu imuSensor(6);

pros::ADIDigitalIn autonSelectorA ('D');
pros::ADIDigitalIn autonSelectorB ('E');

pros::ADIDigitalOut clawMech('B');
pros::ADIDigitalOut tilter('A');
pros::ADIDigitalOut goalCover('F');

Potentiometer pot('C');