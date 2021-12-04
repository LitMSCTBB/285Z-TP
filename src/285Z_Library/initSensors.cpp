#include "../include/285z/initRobot.hpp"

pros::ADIDigitalIn autoSelectorLeft('E');
pros::ADIDigitalIn autoSelectorRight('D');
pros::ADIDigitalOut clawPiston('A');

const std::uint8_t imuPort = 5;
pros::Imu imuSensor(imuPort);

