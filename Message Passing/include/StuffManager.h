#ifndef STUFFMANAGER_H
#define STUFFMANAGER_H

#include "Stuff.h"
#include <iostream>

class StuffManager
{
    public:
        StuffManager();
        virtual ~StuffManager();

        void receiveMessage(std::string message)
        {
            actOnMessage(message);
        }

        void actOnMessage(std::string message)
        {
            displayMessage(message);

            if (message == "NEW COMPONENT")
                std::cout << "A new component has been added\n";
            else if (message == "ENTITY REMOVED")
                std::cout << "An entity has been removed\n";
        }

        void displayMessage(std::string message)
        {
            std::cout << message << '\n';
        }

        Stuff& getStuff() { return stuff; }

    protected:
    private:
        Stuff stuff = Stuff(this);
};

#endif // STUFFMANAGER_H
