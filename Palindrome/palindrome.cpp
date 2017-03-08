#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>

int main()
{
    // Word to check
    std::string word = "BANANA";

    // To lowercase
    std::for_each(word.begin(), word.end(), [](char& c){ c = std::tolower(c); } );

    // Reverse word
    std::string reversed = word;
    std::reverse(reversed.begin(), reversed.end());

    // Verify if palindrome
    if (word == reversed)
        std::cout << "true";
    else
        std::cout << "false";

    return 0;
}
