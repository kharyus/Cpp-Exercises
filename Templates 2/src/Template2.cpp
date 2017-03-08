#include "Template2.hpp"

template<typename Type>
Template2<Type>::Template2()
{
    //ctor
}

template<typename Type>
Template2<Type>::~Template2()
{
    //dtor
}

template<typename Type>
void Template2<Type>::hello(Type type)
{
    std::cout << "Hello World, The argument is: " << type << std::endl;
}
