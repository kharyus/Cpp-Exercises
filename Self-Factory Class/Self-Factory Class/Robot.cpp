#include "Robot.h"

Robot::Robot()
{
    count++;
    instances.push_back(this);
}

Robot::~Robot()
{
    count--;
    auto it = std::find(instances.begin(), instances.end(), this);
    instances.erase(it);
}

////////////////////////////////////
// Static members initialization  //
////////////////////////////////////
int Robot::count = 0;
std::vector<Robot*> Robot::instances;
