#ifndef SYSTEM_H
#define SYSTEM_H

#include "Entity.h"
#include <vector>

class System
{
public:
    System(std::vector<Entity*>* _entities);
    virtual ~System();

    virtual void update() = 0;

protected:
    // If this runs every frame this will be bad.
    // Have to find a way to avoid that.
    // One way would be using message passing.
    template <typename T>
    std::vector<Entity*> getEntitiesWithComponent()
    {
        std::vector<Entity*> entitiesFound;
        for (auto entity : *entities)
            if (entity->getComponent<T>() != nullptr)
                entitiesFound.push_back(entity);
        return entitiesFound;
    }

    std::vector<Entity*>* getEntities() { return entities; }

private:
    std::vector<Entity*>* entities;
};

#endif // SYSTEM_H
