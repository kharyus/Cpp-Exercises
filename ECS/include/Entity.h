#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"
#include <unordered_map>
#include <typeindex>

class Entity
{
public:
    Entity();
    virtual ~Entity();

    // TODO: Verify if already has component
    template <typename T>
    void addComponent() { components[std::type_index(typeid(T))] = new T(); }

    template <typename T>
    T* getComponent()
    {
        auto it = components.find(std::type_index(typeid(T)));
        if (it != components.end())
            return dynamic_cast<T*>(it->second);
        return nullptr;
    }

private:
    std::unordered_map<std::type_index, Component*> components;
};

#endif // ENTITY_H
