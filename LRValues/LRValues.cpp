/**
 *  Work in progress, trying to figure this stuff out.
 */

#include <iostream>

void display(int& i){
    std::cout << i;
}

int main()
{
    int rv = 5;
    int& lv = rv;
    int&& rrv = std::move(rv);
    rv = 4;
    std::cout << "Lvalues and Rvalues exercise." << '\n';

    display(rv);
    std::cout << '\n';
    display(lv);
    std::cout << '\n';
    display(rrv);
    std::cout << '\n';
    //display(std::(5));
    std::cout << '\n';

    system("pause");
    return 0;
}
