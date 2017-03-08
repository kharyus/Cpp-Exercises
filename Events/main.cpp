#include <iostream>
#include <typeinfo>
#include <functional>

std::string const hello =
"     _         _\n\
| | |  |  |   / \\\n\
|-| |- |  |  |   |\n\
| | |_ |_ |_  \\_/";

void drawAscii(std::string drawing)
{
    std::cout << drawing << std::endl;
}

void drawHello()
{
    drawAscii(hello);
}

void helloWorld()
{
    std::cout << "Hello World!\n";
}

std::function<void()> onDraw;

int main()
{
    /////////////////////////////////////////////////////////////////////////////////////////
    // Testing
    std::function<void()> function = []{ std::cout << "_function_ called!" << std::endl; };

    function();

    std::cout << "Type of _function_: " << typeid(function).name() << std::endl;
    std::cout << "Type of an integer: " << typeid(int).name() << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////

    // Bind event
    onDraw = drawHello;

    // Call twice the event
    onDraw();
    onDraw();

    // Rebind
    onDraw = helloWorld;

    // Call twice the event again
    onDraw();
    onDraw();

    return 0;
}
