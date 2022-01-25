#include "../include/285z/initRobot.hpp"

Potentiometer autonPot('B');
pros::ADIDigitalOut clawPiston('A');

const std::uint8_t imuPort = 15;
pros::Imu imuSensor(imuPort);
