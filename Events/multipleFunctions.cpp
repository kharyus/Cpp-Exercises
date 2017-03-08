/////////////////////////////////////////
// Multiple functions on one callback. //
/////////////////////////////////////////

#include <iostream>
#include <functional>

class Event
{
public:
    Event(){}
    ~Event(){}

    // Functor
    Event& operator()() { eventFunction(); }

    // Assignment
    //Event& operator=(Event rhs) { eventFunction = rhs; }
    Event& operator=(std::function<void()> rhs) { eventFunction = rhs; }

    // Implicit conversion
    operator std::function<void()>&() { return eventFunction; }

    // Assigning Multiple Functions
    Event& operator+=(std::function<void()> rhs)
    {
        // For some reason i need this temporary variable holding the eventFunction,
        // even though the lambda was supposed to make a copy of the member.
        auto temp = eventFunction;

        // Set eventFunction to a lambda that calls itself and the new function.
        //It will recursively get bigger
        eventFunction = [=]{
            //eventFunction(); // breaks everything
            temp();
            rhs();
        };
    }
protected:
private:
    std::function<void()> eventFunction;
};

int main()
{
    Event onDraw;

    {
        Event onUpdate;

        // Bind onUpdate
        onUpdate = []{ std::cout << "Update\n"; };

        // Call it once
        onUpdate();
        std::cout << std::endl;

        // Bind onDraw to onUpdate's function using implicit conversion
        onDraw = onUpdate;

        // Add other functions to onDraw
        onDraw += []{ std::cout << "Draw\n"; };
        onDraw += onUpdate;
        onDraw += []{ std::cout << "Hello!\n"; };

        // Call it.
        onDraw();
        std::cout << std::endl;
    }

    // onUpdate left scope, onDraw still works
    onDraw();


    return 0;
}
