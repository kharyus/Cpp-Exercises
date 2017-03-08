#include "System.h"

System::System(std::vector<Entity*>* _entities)
{
    entities = _entities;
}

System::~System()
{
    //dtor
}
