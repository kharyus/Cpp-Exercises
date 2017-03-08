#include "Template.hpp"

template<typename Type>
Template<Type>::Template(){}

template<typename Type>
Template<Type>::~Template(){}

template<typename Type>
void Template<Type>::hello(Type type)
{
    std::cout << "Hello World, The argument is: " << type << std::endl;
}

template<typename Type>
void Template<Type>::display(const std::string& message)
{
    std::cout << message << std::endl;
}
