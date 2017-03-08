#include <iostream>
#include "Robot.h"
#include "SelfFactory.h"

int main(){
    Robot r1;
    SelfFactory sf1, sf2;

    // Display Self Factories
    std::cout << "Self-Factories Vec Size: " << SelfFactory::getInstances().size() << std::endl;
    std::cout << std::endl;

    // Display Robots
    {
        Robot r2;
        std::cout << "Robots Count: " << Robot::getCount() << "\nRobots Vec Size: " << Robot::getInstances().size() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Robots Count: " << Robot::getCount() << "\nRobots Vec Size: " << Robot::getInstances().size() << std::endl;

    return 0;
}
