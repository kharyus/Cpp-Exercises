#ifndef GRAPHICSYSTEM_H
#define GRAPHICSYSTEM_H

#include "System.h"

class GraphicSystem : public System
{
public:
    GraphicSystem(std::vector<Entity*>* entities);
    virtual ~GraphicSystem();

    void update();
private:
};

#endif // GRAPHICSYSTEM_H
