#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H

#include "Component.h"

class CollisionComponent : public Component
{
public:
    CollisionComponent();
    virtual ~CollisionComponent();

    bool collisionHappened() { return true; }
private:
};

#endif // COLLISIONCOMPONENT_H
