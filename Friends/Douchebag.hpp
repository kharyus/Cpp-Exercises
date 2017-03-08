#ifndef DOUCHEBAG_HPP
#define DOUCHEBAG_HPP

#include "NiceDude.hpp"

class Douchebag
{
public:
    void stealMoney(NiceDude& n, float money)
    {
        n.money -= money;
        this->money += money;
    }

    void sayHowMuchMoneyThereIsOutLoud(NiceDude& n)
    {
        std::cout << n.money << std::endl;
    }

    float getMoney()
    {
        return money;
    }

private:
    float money = 0;
};

#endif
