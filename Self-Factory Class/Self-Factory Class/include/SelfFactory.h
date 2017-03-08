#ifndef SELFFACTORY_H
#define SELFFACTORY_H

#include <vector>
// TODO: Play around with this. Make a class inheriting this, and a templaced class to analyze beneffits

/**
 *  This class posseses a static collection of itself, and manages it's own instances.
 */
class SelfFactory
{
    public:
        SelfFactory();
        virtual ~SelfFactory();

        std::vector<SelfFactory*> static const getInstances() { return instances; }
    protected:

    private:
        static std::vector<SelfFactory*> instances;
};

#endif // SELFFACTORY_H
