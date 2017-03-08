#include <iostream>

class Outer
{
public:
    Outer(){}
    virtual ~Outer(){}

protected:
private:

    int i = 0;

    // Nested Class
    class Inner
    {
    public:
        Inner(){}
        virtual ~Inner(){}

        int j = 0;

    protected:
    private:
    };

    // Instantiation
public:
    Inner* inner;

};

int main()
{
    Outer o;

    std::cout << "Nested class, attribute j: " << o.inner->j << '\n';

    o.inner->j = 5;

    std::cout << "Nested class, attribute j: " << o.inner->j << '\n';

    return 0;
}
