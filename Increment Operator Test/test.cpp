#include <iostream>

int main()
{

    for (int i = 0; i < 10; i++)
        std::cout << "i++ For: " << i << std::endl;

    std::endl;

    for (int i = 0; i < 10; ++i)
        std::cout << "++i For: " << i << std::endl;

    // Conclusion: They do the same thing.
    // ++i might do it better though because of performance,
    // although I would need to research whether it isn't optimized
    // anyway and where the performance increase would come from.

    return 0;
}
