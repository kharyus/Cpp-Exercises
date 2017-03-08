#include "Player.h"

#include "GraphicComponent.h"

Player::Player()
{
    addComponent<GraphicComponent>();
}

Player::~Player()
{
    //dtor
}
