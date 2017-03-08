#include "ECSManager.h"
#include "GraphicSystem.h"
#include "Player.h"
#include <iostream>

int main()
{
    ECSManager ecsManager;

    ecsManager.addSystem<GraphicSystem>();
    ecsManager.addEntity<Player>();
    ecsManager.addEntity<Player>();
    ecsManager.addEntity<Player>();
    ecsManager.addEntity<Player>();

    while (1)
    {
        ecsManager.update();
        std::cout << std::endl;
    }

    return 0;
}
