#include <StuffManager.h>

int main()
{
    StuffManager stuffManager;

    stuffManager.getStuff().sendMessage("QWE");
    stuffManager.getStuff().sendMessage("Messatsu");
    stuffManager.getStuff().sendMessage("Passing message upwards works :)");

    std::cout << std::endl;

    stuffManager.getStuff().sendMessage("NEW COMPONENT");

    stuffManager.getStuff().sendMessage("ENTITY REMOVED");

    return 0;
}
