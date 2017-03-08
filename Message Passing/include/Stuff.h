#ifndef STUFF_H
#define STUFF_H

#include <string>

class StuffManager;

class Stuff
{
    public:
        Stuff(StuffManager* _stuffManager) { stuffManager = _stuffManager; }
        virtual ~Stuff();

        void sendMessage(std::string message);
        void sendMessage();

    protected:
    private:
        StuffManager* stuffManager;
};

#endif // STUFF_H
