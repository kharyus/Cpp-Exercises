#include <iostream>

#include "TemplateClass.hpp"

// Type of the variable to feed the template
typedef float VarType;

int main(int argc, char* argv[])
{
    TemplateClass<VarType>* templateClass = new TemplateClass<VarType>;

    VarType f1, f2;
    std::cout << "Input the 2 arguments: ";
    std::cin >> f1 >> f2;
    templateClass->setArgs(f1, f2);
    std::cout << std::endl;

    // Values
    std::cout << "Value 1: " << templateClass->getArgs().x << std::endl;
    std::cout << "Value 2: " << templateClass->getArgs().y << std::endl << std::endl;
    // Basic Operations
    std::cout << "Addition: " << templateClass->add() << std::endl;
    std::cout << "Subtract: " << templateClass->subtract() << std::endl;
    std::cout << "Multiply: " << templateClass->multiply() << std::endl;
    std::cout << "Divide: " << templateClass->divide() << std::endl;

    delete templateClass;
    return 0;
}
