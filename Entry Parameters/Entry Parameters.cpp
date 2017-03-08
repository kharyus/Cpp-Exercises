#include <iostream>

// Entry parameters' names are irrelevant, being just identifiers like any other function.
int main(int banana, char* metsu[])
{
    std::cout << banana << std::endl;
    for (int i = 0; i < banana; i++)
        std::cout << metsu[i] << std::endl;

    int i;
    std::cin >> i;
}
