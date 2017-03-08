#include <iostream>
#include "ECSManager.h"
#include "CollisionSystem.h"
#include "GraphicSystem.h"
#include "Player.h"

#include <iostream>

int main()
{
    ECSManager ecsManager;

    ecsManager.addSystem<CollisionSystem>();
    ecsManager.addSystem<GraphicSystem>();

    ecsManager.addEntity<Player>();
    ecsManager.addEntity<Player>();
    ecsManager.addEntity<Player>();

    while(true)
    {
        ecsManager.update();
        std::cout << std::endl;
    }

    //CollisionSystem sys;

    //std::cout << "Current Health: " << sys.getComponents<HealthComponent>().at(0)->getHealth() << "/" << sys.getComponents<HealthComponent>().at(0)->getMaxHealth() << std::endl;

    /*sys.update();
    sys.update();
    sys.update();
    sys.update();*/

    //std::cout << "Current Health: " << sys.getComponents<HealthComponent>().at(0)->getHealth() << "/" << sys.getComponents<HealthComponent>().at(0)->getMaxHealth() << std::endl;

    return 0;
}
