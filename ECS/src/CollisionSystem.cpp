#include "CollisionSystem.h"

#include <iostream>

using namespace std;

CollisionSystem::CollisionSystem(std::vector<Entity*>* entities)
    : System(entities)
{
    //ctor
}

CollisionSystem::~CollisionSystem()
{
    //dtor
}

void CollisionSystem::update()
{
    auto entities = getEntitiesWithComponent<CollisionComponent>();
    for (auto& collisionEntity : entities)
    {
        float damage = 5;
        collisionEntity->getComponent<HealthComponent>()->addHealth(-damage);
        cout << "Hit happened, " << collisionEntity << " lost " << damage << " health points." << endl;
        cout << collisionEntity << " has " << collisionEntity->getComponent<HealthComponent>()->getHealth()
            << "/" << collisionEntity->getComponent<HealthComponent>()->getMaxHealth() << " health points." << endl;
    }
}
