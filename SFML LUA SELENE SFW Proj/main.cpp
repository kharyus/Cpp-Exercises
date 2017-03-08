#include <SFML/Graphics.hpp>
#include <selene.h>
#include "Lua.hpp"
#include <iostream>
#include <FileWatcher/FileWatcher.h>
#include <thread>
#include "ECSManager.h"

/////////
// ECS //
/////////

using namespace ecs;

struct LuaComponent : public Component
{
public:
    LuaComponent(sel::State* state, std::string compName)
        : innerData((*state)[""]) // Initialize with any value. Shouldn't really be doing this.
    {
        // Set members
        this->state = state;
        this->compName = compName;
        index = ++i;

        // Make new Component with name %compName%Index
        (*state)(std::string(compName + std::to_string(index) + " = " + compName + ":new()").c_str());
        innerData = (*state)[(compName + std::to_string(index)).c_str()];

        // Debug
        std::cout << static_cast<int>(innerData["x"]);
    }
    virtual ~LuaComponent() noexcept
    {
        (*state)(std::string(compName + std::to_string(index) + " = nil").c_str());
    }

    sel::Selector operator[](char* const arg)
    {
        return innerData[arg];
    }

private:
    sel::Selector innerData;
    int index;
    std::string compName;
    sel::State* state;

    // Global counter
    static int i;
};
int LuaComponent::i = 0;

class LuaSystem : public System
{
public:
    LuaSystem(sel::State* state, std::string pathToScript)
    {
        this->pathToScript = pathToScript;
        this->state = state;
        state->Load(pathToScript); // TODO: Make a function called addLuaDependency();
    }

private:
    std::string pathToScript;
    sel::State* state;
};

struct LuaCollisionComponent : public LuaComponent
{
public:
    LuaCollisionComponent(sel::State* state)
        : LuaComponent(state, "Collision") // TODO: Make new instance of an collisionComponent and put inside the innerData
    {}


    int x = 0;

    void onCollision(LuaCollisionComponent* otherComponent)
    {
        int x = (*otherComponent)["x"];

        (*this)["onCollision"](x);
    }
};

class LuaCollisionSystem : public LuaSystem
{
public:
    LuaCollisionSystem(sel::State* state, std::string pathToScript)
        : LuaSystem(state, pathToScript)
    {
        newComponentDependency<LuaCollisionComponent>();
    }

    void update()
    {
        for (auto it = getEntities().begin(); it < getEntities().end(); ++it)
        {
            for (auto it2 = it + 1; it2 < getEntities().end(); ++it2)
            {
                if ((*it)->getComponent<LuaCollisionComponent>()->x == (*it2)->getComponent<LuaCollisionComponent>()->x)
                {
                    //std::cout << "Collision between " << *it << " and " << *it2;
                    (*it)->getComponent<LuaCollisionComponent>()->onCollision((*it2)->getComponent<LuaCollisionComponent>());
                    (*it2)->getComponent<LuaCollisionComponent>()->onCollision((*it)->getComponent<LuaCollisionComponent>());
                }
            }
        }
    }
};

// Processes a file action
class UpdateListener : public FW::FileWatchListener
{
public:
	UpdateListener(sel::State* state) { this->state = state; }
	void handleFileAction(FW::WatchID watchid, const FW::String& dir, const FW::String& filename, FW::Action action)
	{
	    if (filename.substr(filename.length()-4) == ".lua" && action == 4) {
            state->Load(filename);
            std::cout << filename << " modified." << std::endl;
	    }
	    else
            std::cout << "DIR (" << dir + ") FILE (" + filename + ") has event " << action << std::endl;
	}
private:
    sel::State* state;
};

int main()
{
    /////////////////////
    // Initialize SFML //
    /////////////////////

    // Create window
    sf::RenderWindow window(sf::VideoMode(800,600), "SFML + Lua + ECS");
    // Sets 60 fps
    window.setFramerateLimit(60);
    // V-sync
    window.setVerticalSyncEnabled(false);

    sf::Font font;
    font.loadFromFile("CardboardCat-Regular.otf");
    sf::Text text("Hello", font);

    /////////
    // Lua //
    /////////
    sel::State state{true};

    // Load script
    state.Load("concatenate.lua");

    std::string s = state["concatenate"]("Hello");
    text.setString( s );

    int i = state["add"](10,22);
    std::cout << i << '\n';

    state["metsu"]();

    //////////////////
    // REPL for Lua //
    //////////////////
    std::thread consoleInput( [&]{  std::string str;
                                    do {
                                        std::getline(std::cin, str);
                                        state(str.c_str());
                                    } while (str != "stop");
                                });
    consoleInput.detach();

    //////////////////
    // File watcher //
    //////////////////
    // create the file watcher object
    FW::FileWatcher fileWatcher;

    // add a watch to the system
    FW::WatchID watchID = fileWatcher.addWatch("./", new UpdateListener(&state));

    /////////
    // ECS //
    /////////
    ECSManager ecs;
    ecs.newSystemWithParameters<LuaCollisionSystem>(&state, "collisionComponent.lua");
    auto& entity1 = ecs.newEntity().addComponentWithParameters<LuaCollisionComponent>(&state);
    auto& entity2 = ecs.newEntity().addComponentWithParameters<LuaCollisionComponent>(&state);
    auto& entity3 = ecs.newEntity().addComponentWithParameters<LuaCollisionComponent>(&state);
    ecs.deleteEntity(entity3);

    // Window main loop
    while (window.isOpen())
    {
        // Iterate through all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear frame
        window.clear();

        // Draw entities
        window.draw(text);

        // Display Frame
        window.display();

        // File watcher
        fileWatcher.update();

        // ECS
        ecs.updateSystems();
    }

    // Exit program succesfully
    return 0;
}
