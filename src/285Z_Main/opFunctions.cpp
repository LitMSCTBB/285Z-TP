#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/lift.hpp"
#include "../include/285z/initSensors.hpp"
using namespace std;

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

void moveProfile(std::shared_ptr<okapi::AsyncMotionProfileController> profile,
          string name,
          bool dir)
{
  profile->setTarget(name, dir);
  profile->waitUntilSettled();
}

void genPath(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, string name)
{
  profile->generatePath(
    {{0_ft,0_ft,0_deg},
    {distance, 0_ft,0_deg}},
    name
  );
}

vector<bool> genPaths(std::shared_ptr<okapi::AsyncMotionProfileController> slow,
                  std::shared_ptr<okapi::AsyncMotionProfileController> med,
                  std::shared_ptr<okapi::AsyncMotionProfileController> fast, int autoIndex)
{
  vector<bool> dirs;
  switch (autoIndex)
  {
  case (0):
    break;
  case (1):
    dirs = {fwd, bwd, fwd, bwd};
    genPath(fast, 9.55_ft, "0");
    genPath(fast, 8.5_ft, "1");
    genPath(fast, 1.67_ft, "2");
    genPath(med, 3.65_ft, "3");
    break;
  case (2):
    dirs = {fwd, bwd, bwd};
    genPath(fast, 10_ft, "0");
    genPath(fast, 5_ft, "1");
    genPath(slow, 3_ft, "2");
    break;
  case (3):
    dirs = {fwd, bwd, fwd, bwd};
    genPath(fast, 9.4_ft, "0");
    genPath(fast, 7.35_ft, "1");
    genPath(fast, 1.67_ft, "2");
    genPath(med, 3.65_ft, "3");
    break;
  case (4):
    break;
  case (5):
    break;
  case (6):
    break;
  case (7):
    break;
  default:
    break;
  }
  return dirs;
}