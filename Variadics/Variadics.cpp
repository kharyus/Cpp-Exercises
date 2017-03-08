#include <iostream>
#include <cstdarg>

class Test
{
public:
    Test();
    ~Test();
protected:
private:

    int j;
};

Test i;

i.j = 0;

// Variadic function
// It seems $ can be used as an identifier...                           Nice!
int $(int count, ...)
{
    int result = 0;

    // Having to use this start and end is kind of bad. I don't like it.
    // I much prefer variadic template's way of doing it.
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
        result += va_arg(args, int);
    va_end(args);

    return result;
}

int main()
{
    //int i = 5, j = 6, k = 8;

    int result = $(3,5,6,7);  // 18
    std::cout << result << '\n';
    return 0;
}
