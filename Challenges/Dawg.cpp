#include <iostream>
#include <string>

int main()
{
    uint16_t place, positions;
    std::string output;
    std::cin >> place >> positions;

    for(int i = 1; i <= positions; i++)
        if (i != place){
            output =  (i >= 11 && i <= 13) ? "th" : (i % 10 == 1) ? "st" : (i % 10 == 2) ? "nd" : (i % 10 == 3) ? "rd" : "th";
            std::cout << i << output << ((i != positions) ? ", " : ".");
        }
}
