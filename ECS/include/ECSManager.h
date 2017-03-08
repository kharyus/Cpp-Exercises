#ifndef ECSMANAGER_H
#define ECSMANAGER_H

#include "Entity.h"
#include "Component.h"
#include "System.h"
#include <vector>

class ECSManager
{
public:
    ECSManager();
    virtual ~ECSManager();

    // TODO: Verify if already has system.
    template <typename T>
    void addSystem()
    {
        systems.push_back(new T(&entities));
    }

    template <typename T>
    void addEntity()
    {
        entities.push_back(new T());
    }

    /** Updates all systems */
    void update();

private:
    // List of entities
    std::vector<Entity*> entities;
    // Map of components to entities
    std::vector<Component*> componentLists;
    // Map of Systems to a map of components.
    // Each system has a list of components to each separate component.
    std::vector<System*> systems;
};

#endif // ECSMANAGER_H
