#include "GraphicSystem.h"

#include <iostream>
using namespace std;

GraphicSystem::GraphicSystem(std::vector<Entity*>* entities)
    : System(entities)
{
    //ctor
}

GraphicSystem::~GraphicSystem()
{
    //dtor
}

void GraphicSystem::update()
{
    cout << "Graphic System updated" << endl;
}
