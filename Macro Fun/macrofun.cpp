#include <iostream>

#define DO(times) for (int zPzozpzo = 0; zPzozpzo < times; zPzozpzo++)
#define FOR(var,times) for (int var = 0; var < times; var++)

int main()
{

    FOR(i,10)
    {
        std::cout << "Banana" << i << std::endl;
    }

    std::cout << std::endl;

    DO(10)
    {
        std::cout << "Banana" << std::endl;
    }

    return 0;
}
