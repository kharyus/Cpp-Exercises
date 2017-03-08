#include <tuple>
#include <iostream>
#include <vector>

class BaseOfSystem
{
public:
    BaseOfSystem(){}
    virtual ~BaseOfSystem(){}

    virtual void update() = 0;
};

template <typename... Deps>
class System : public BaseOfSystem
{
public:
    System(){}
    virtual ~System(){}

    void update(){ std::cout << "Update!" << std::endl; }

    std::vector<std::tuple<Deps...>> components;
protected:
private:
};


class Alchohol
{
public:
    Alchohol(){}
    virtual ~Alchohol(){}

    int i = 4;

    //void update() { std::cout << "Alchohol!" << std::endl;}
protected:
private:
};

class DerivedSystem : public System<Alchohol>
{
public:
    DerivedSystem(){ components.push_back(Alchohol()); }
    virtual ~DerivedSystem(){}

    void update() { std::cout << std::get<0>(components[0]).i << std::endl; }
protected:
private:
};

class VideoGames
{
public:
    VideoGames(){}
    virtual ~VideoGames(){}

    float j = 5;

    //void update() override { std::cout << "VideoGames!" << std::endl;}
protected:
private:
};

class Reddit
{
public:
    Reddit(){}
    virtual ~Reddit(){}

    std::string s = "Hello";

    //void update() override { std::cout << "Reddit!" << std::endl;}
protected:
private:
};



int main()
{

    System<Alchohol, VideoGames> sys;

    sys.components.push_back(std::make_tuple(Alchohol(), VideoGames()));

    std::cout << std::get<1>(sys.components[0]).j << std::endl;

    // Here's the trick.
    std::vector<BaseOfSystem*> systems;

    systems.push_back(&sys);

    System<Reddit> sys2;

    sys2.components.push_back(std::make_tuple(Reddit()));

    systems.push_back(&sys2);

    // Check this thing out. It's so ugly :')
    //std::cout << std::get<0>(dynamic_cast<System<Reddit>*>(systems[1])->components[0]).s << std::endl;

    systems[0]->update();

    DerivedSystem derived;

    // I think i finally managed to avoid dynamic_casts every update through heavy use of metaprogramming.
    derived.update();

    return 0;
}
