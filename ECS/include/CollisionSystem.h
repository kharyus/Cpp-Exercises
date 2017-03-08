#ifndef TESTSYSTEM_H
#define TESTSYSTEM_H

#include "System.h"
#include "HealthComponent.h"
#include "CollisionComponent.h"

class CollisionSystem : public System
{
public:
    CollisionSystem(std::vector<Entity*>* entities);
    virtual ~CollisionSystem();

    void update();
private:
};

#endif // TESTSYSTEM_H
