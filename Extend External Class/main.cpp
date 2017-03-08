#include <iostream>
//#include <exception>
#include <vector>

////////////////////////////////////////////////////////////////////////////////////
// Turns out I Can't extend the class if the function is not declared on the header.
// That is for the best but still...
/*void std::exception::shinku()
{
    std::cout << "Hello World!";
}*/
////////////////////////////////////////////////////////////////////////////////////

template <typename T>
class MyVectorExtension : public std::vector<T>
{
public:
    MyVectorExtension();
    ~MyVectorExtension();

    void shinku() { std::cout << "Shinku! HADOUKEN!!!" << std::endl; }
protected:
private:
};

// Apparently std::vector uses specialization and requires me to specialize MyVectorExtension too...
template<>
MyVectorExtension<int>::MyVectorExtension(){}

template<>
MyVectorExtension<int>::~MyVectorExtension(){}

int main()
{
    MyVectorExtension<int> vec;

    vec.shinku();

    return 0;
}
