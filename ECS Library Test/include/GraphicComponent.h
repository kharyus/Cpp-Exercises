#ifndef GRAPHICCOMPONENT_H
#define GRAPHICCOMPONENT_H

#include "Component.h"

struct Pos2D{
    float x = 0;
    float y = 0;
};

class GraphicComponent : public Component
{
public:
    GraphicComponent();
    virtual ~GraphicComponent();

    Pos2D getPosition() { return position; }
    void setPosition(float x, float y) { position.x = x; position.y = y; }
    void move(float x, float y) { position.x += x; position.y += y; }

private:
    Pos2D position;
};

#endif // GRAPHICCOMPONENT_H
