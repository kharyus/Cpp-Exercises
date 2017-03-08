#include <iostream>

// Print
template<typename T>
void print(T value)
{
    std::cout << value;
}

template<typename T, typename... Args>
void print(T value, Args... params)
{
    std::cout << value;
    print(params...);
}

// Print Line
void printLine() // In case no param is passed.
{
    std::cout << std::endl;
}

template<typename T>
void printLine(T value)
{
    std::cout << value << std::endl;
}

template<typename T, typename... Args>
void printLine(T value, Args... params)
{
    std::cout << value;
    printLine(params...);
}

// Add numbers, returning double since if I use T it's going to keep changing throughout the calls,
// truncating when reaching ints.
template<typename T>
double add(T value)
{
    return value;
}

template<typename T, typename... Args>
double add(T value, Args... params)
{
    return value + add(params...);
}

// Subtract numbers in a lisp-like manner in which the first number is subtracted from all the following.
template<typename T>
double subtract(T value)
{
    return value;
}

template<typename T1, typename T2, typename... Args>
double subtract(T1 value, T2 value2, Args... params)
{
    return subtract(value - value2, params...);
}

// Multiply numbers
template<typename T>
double multiply(T value)
{
    return value;
}

template<typename T, typename... Args>
double multiply(T value, Args... params)
{
    return value * multiply(params...);
}

// Divide numbers. Makes use of multiply since every other number other than first must be multiplied for the division
// Could do the same with subtract.
template<typename T, typename... Args>
double divide(T value, Args... params)
{
    return value / multiply(params...);
}

// Main
int main()
{
    // Prints
    printLine("This is my printLine function! ", 'a', 150, " - ", 5.03, "MESSATSU");
    print("This is my print function!", 'a', 150, " - ", 5.03, "MESSATSU");
    printLine("This is also my printLine function!", 'a', 150, " - ", 5.03, "MESSATSU");
    printLine();

    // Adds
    printLine("This is my add function: ", add(50.3,30,20.9));
    printLine("This is also my add function: ", add(52.5,42,31.5,21,10.5));
    printLine();

    // Subtracts
    printLine("This is my subtract function: ", subtract(50.3,30,20.9));
    printLine("This is also my subtract function: ", subtract(52.5,10,10.5,10,10.5));
    printLine();

    // Multiplies
    printLine("This is my multiply function: ", multiply(1.5,2,12));
    printLine("This is also my multiply function: ", multiply(100.5,100.5,100.5));
    printLine("This is also my multiply function: ", multiply(100.5,10,100));
    printLine();

    // Division
    printLine("This is my divide function: ", divide(20,2,5));
    printLine("This is also my divide function: ", divide(100,100,100));
    printLine("This is also my divide function: ", divide(50,2,5,2));
    printLine();

    return 0;
}
