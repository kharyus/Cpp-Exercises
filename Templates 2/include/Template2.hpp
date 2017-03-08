#ifndef TEMPLATE2_HPP
#define TEMPLATE2_HPP

#include <iostream>

/**
 *  Separating 'Template2' templated class into header and source.
 *  It requires that the Template2.cpp file be removed from the IDE's build target,
 *  or when using compiler i assume just not adding Template2.cpp into the sources to be compiled.
 */
template <typename Type>
class Template2
{
    public:
        Template2();
        virtual ~Template2();

        void hello(Type type);
    protected:
    private:
};

/**
 *  Include Source file containing template definition at the end of header.
 */
#include "../src/Template2.cpp"

#endif // TEMPLATE2_HPP
