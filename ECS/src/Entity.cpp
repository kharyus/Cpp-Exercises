#include "Entity.h"

Entity::Entity()
{
    //ctor
}

Entity::~Entity()
{
    for (auto& component : components)
        delete component.second;
}
