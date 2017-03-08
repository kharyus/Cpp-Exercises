#include "SelfFactory.h"

#include <algorithm>

SelfFactory::SelfFactory()
{
    instances.push_back(this);
}

SelfFactory::~SelfFactory()
{
    auto it = std::find(instances.begin(), instances.end(), this);
    instances.erase(it);
}

////////////////////////////////////
// Static members initialization  //
////////////////////////////////////
std::vector<SelfFactory*> SelfFactory::instances;
