#include "../include/285z/initRobot.hpp"

pros::ADIDigitalOut clawPiston('A');
pros::Imu imuSensor(15);
pros::ADIDigitalIn autonSelector ('B');
Potentiometer autonPotL('D');
// Potentiometer autonPotR('E');
