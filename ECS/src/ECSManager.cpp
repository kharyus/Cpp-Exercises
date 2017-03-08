#include "ECSManager.h"

ECSManager::ECSManager()
{
    //ctor
}

ECSManager::~ECSManager()
{
    for (auto& system : systems)
        delete system;
}

void ECSManager::update()
{
    for (auto& system : systems)
        system->update();
}
