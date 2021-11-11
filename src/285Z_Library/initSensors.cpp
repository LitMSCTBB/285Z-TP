#include "../include/285z/initRobot.hpp"

pros::ADIDigitalIn autoSelectorLeft ('E');
pros::ADIDigitalIn autoSelectorRight ('D');

const std::uint8_t imuPort = 5;
pros::Imu imuSensor(imuPort);
