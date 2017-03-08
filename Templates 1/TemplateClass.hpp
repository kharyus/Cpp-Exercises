#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H

template<typename T>
struct Args{T x; T y;};

template<typename T>
class TemplateClass
{
    public:
        TemplateClass();
        virtual ~TemplateClass();

        /* Functions */
        void setArgs(T arg1, T arg2);
        Args<T> getArgs();
        T add();
        T subtract();
        T multiply();
        T divide();

    protected:
    private:
        T arg1;
        T arg2;
};

/* Implementation */
template<typename T>
TemplateClass<T>::TemplateClass()
{
    //ctor
}

template<typename T>
TemplateClass<T>::~TemplateClass()
{
    //dtor
}

template<typename T>
void TemplateClass<T>::setArgs(T arg1, T arg2)
{
    this->arg1 = arg1;
    this->arg2 = arg2;
}

template<typename T>
Args<T> TemplateClass<T>::getArgs()
{
    return {arg1, arg2};
}

template<typename T>
T TemplateClass<T>::add()
{
    return arg1 + arg2;
}

template<typename T>
T TemplateClass<T>::subtract()
{
    return arg1 - arg2;
}

template<typename T>
T TemplateClass<T>::multiply()
{
    return arg1 * arg2;
}

template<typename T>
T TemplateClass<T>::divide()
{
    return arg1 / arg2;
}

#endif // TEMPLATECLASS_H
