#ifndef Template_HPP
#define Template_HPP

#include <iostream>

/**
 *  Template with explicit Instantiation
 */
template<typename Type>
class Template
{
public:
    Template();
    virtual ~Template();

    void hello(Type type);

    void display(const std::string& message);
};

// Explicit instantiation
template class Template<int>;
template class Template<std::string>;

#endif
