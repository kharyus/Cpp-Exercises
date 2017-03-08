#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include <algorithm>

// Robot has information about all other robots. Robot hivemind!
class Robot
{
    public:
        Robot();
        virtual ~Robot();

        int static const getCount() { return count; }
        std::vector<Robot*> static const getInstances() { return instances; }
    protected:

    private:
        static int count; // Count is unnecessary because of the vector since it possesses the size() function
        static std::vector<Robot*> instances;

};

#endif // ROBOT_H
