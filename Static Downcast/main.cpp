#include <iostream>

class Base
{
public:
    Base(){}
    virtual ~Base(){}
protected:
private:
};

class Derived : public Base
{
public:
    Derived(){}
    virtual ~Derived(){}

    int i = 5;
protected:
private:
};

int main()
{
    Base* b = new Derived();

    // Both Work. One verifies at runtime the type.
    std::cout << static_cast<Derived*>(b)->i << std::endl;
    std::cout << dynamic_cast<Derived*>(b)->i << std::endl;

    return 0;
}
