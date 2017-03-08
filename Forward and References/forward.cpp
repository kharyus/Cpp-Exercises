#include <iostream>

// todo forward

/*void function(int i)
{
    std::cout << "received a copy" << std::endl;
}*/

void function(int* i)
{
    std::cout << "received a pointer: " << i << std::endl;
}

void function(int& i)
{
    std::cout << "received a lvalue reference: " << i << std::endl;
}

void function(int&& i)
{
    std::cout << "received a rvalue reference: " << i << std::endl;
}

int main()
{
    int i = 5;
    function(i); //lvalue ref

    function(&i); //pointer

    function(std::move(i)); //passes a rvalue ref

    function(50); //rvalue ref

    return 0;
}
