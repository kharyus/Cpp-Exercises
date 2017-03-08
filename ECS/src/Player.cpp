#include "Player.h"

#include "HealthComponent.h"
#include "CollisionComponent.h"

Player::Player()
{
    addComponent<HealthComponent>();
    addComponent<CollisionComponent>();
}

Player::~Player()
{
    //dtor
}
