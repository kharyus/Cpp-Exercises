#include <iostream>

// Function Class
class Functor
{
public:
    // Calls function pointer
    int operator()(int a, int b){ return function(a, b); }

    // Set function pointer
    void operator=(int (*_function)(int,int)){ function = _function; }

private:
    // Function pointer
    int (* function)(int, int);
};

// Another function with a different signature to be called back(callbacked?)
void printInt(int i)
{
    std::cout << i;
}

/*
// Need to add typename... Args

// Generic Function Class
template<typename Function>
class GenericFunctor
{
public:
    // Constructor
    GenericFunctor(Function _function){ function = _function; }

    // Calls function pointer
    int operator()(){ return function(); }

    // Set function pointer
    void operator=(Function _function){ function = _function; }

private:
    // Function pointer
    Function function;
};*/

// Function to be called back(callbacked?)
int add(int i, int j)
{
    return i + j;
}


int main()
{

    Functor f;

    f = add;

    std::cout << f(1, 2) << '\n';
    std::cout << f(f(1,2), 3) << '\n';

    /*GenericFunctor<void (*)(int)> gf(printInt);

    gf = printInt;

    std::cout << gf();*/

    return 0;
}
