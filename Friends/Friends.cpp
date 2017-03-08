#include <iostream>

#include "Douchebag.hpp"
#include "NiceDude.hpp"

int main()
{
    NiceDude n;
    Douchebag d;

    d.sayHowMuchMoneyThereIsOutLoud(n);
    d.stealMoney(n, 200);
    d.sayHowMuchMoneyThereIsOutLoud(n);
    std::cout << d.getMoney() << std::endl;

    return 0;
}
