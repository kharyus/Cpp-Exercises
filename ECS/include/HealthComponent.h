#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

#include "Component.h"

class HealthComponent : public Component
{
public:
    HealthComponent();
    virtual ~HealthComponent();

    float getHealth() { return health; }
    void addHealth(float offset) { health += offset; }
    float getMaxHealth() { return MAX_HEALTH; }

private:
    const float MAX_HEALTH = 100;
    float health = MAX_HEALTH;
};

#endif // HEALTHCOMPONENT_H
