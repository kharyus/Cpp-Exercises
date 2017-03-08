#include "GraphicSystem.h"

#include "GraphicComponent.h"
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
    auto entities = getEntitiesWithComponent<GraphicComponent>();
    for (entity : entities)
    {
        float x = 10, y = 5;
        entity->getComponent<GraphicComponent>()->move(x,y);
        cout << entity << "'s X is: " << entity->getComponent<GraphicComponent>()->getPosition().x << endl;
        cout << entity << "'s Y is: " << entity->getComponent<GraphicComponent>()->getPosition().y << endl;
    }
}
