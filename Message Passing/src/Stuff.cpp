#include "Stuff.h"

#include "StuffManager.h"

/*Stuff::Stuff()
{
    //ctor
}*/

Stuff::~Stuff()
{
    //dtor
}

void Stuff::sendMessage(std::string message)
{
    stuffManager->receiveMessage(message);
}
