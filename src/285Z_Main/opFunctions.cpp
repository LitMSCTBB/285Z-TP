#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/lift.hpp"

void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile,
  okapi::QLength distance,
  bool dir)
{
  profile->generatePath({
    {0_ft,0_ft,0_deg},
    {distance, 0_ft,0_deg}},
    "M"
  );

  profile->setTarget("M", dir);
  profile->waitUntilSettled();
  profile->removePath("M");
}

void liftUp() {
  twoBarController->setTarget(-1615);
}

void liftDown() {
  twoBarController->setTarget(-3010);
}
