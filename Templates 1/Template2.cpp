#include <iostream>

#include "Data.h"

class Banana
{
    public:
        Banana(){tastinessLevel = 2;}
        virtual ~Banana(){}

        int getTaste(){return tastinessLevel;}

    private:
        int tastinessLevel;
        float length;
};

class Apple
{
    public:
        Apple(){tastinessLevel = 1;}
        virtual ~Apple(){}

        int getTaste(){return tastinessLevel;}

    private:
        int tastinessLevel;
        bool isBad;
};

//template<typename Data>
class EvilOverlordHolderOfFruits
{
public:
    EvilOverlordHolderOfFruits(){}
    virtual ~EvilOverlordHolderOfFruits(){}

    template<typename Data>
    void receiveThing(Data data)
    {
        this->data = &data;
    }

    template <typename Data>
    void displayThing()
    {
        Data* dataDeref = static_cast<Data*>(data);
        std::cout << dataDeref->getTaste() << std::endl;
    }

private:
    //template<typename Data>
    void* data;
};

template<typename T>
T returnThing(T t)
{
    return t;
}

int main()
{
    Apple a;
    Banana b;

    returnThing(a);
    returnThing(b);

    //EvilOverlordHolderOfFruits<Apple> e1;
    //EvilOverlordHolderOfFruits<Banana> e2;
    EvilOverlordHolderOfFruits e1;
    EvilOverlordHolderOfFruits e2;
    e1.receiveThing(a);
    e1.displayThing<Apple>();
    e2.receiveThing(b);
    e2.displayThing<Banana>();

    Apple* a2 = new Apple();
    Data data(*a2);
    delete a2;
    data.getData<Apple>();
    std::cout << data.getData<Apple>().getTaste() << std::endl;

    Banana* banana = new Banana();
    Data d(*banana);
    delete banana;
    std::cout << d.getData<Banana>().getTaste() << std::endl;

    return 0;
}
