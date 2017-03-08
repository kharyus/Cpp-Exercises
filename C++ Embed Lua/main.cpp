// Lua Vanilla test

/*#include <iostream>
#include "lua.hpp"

int main()
{
    lua_State *Lua = luaL_newstate();

    // load the libs
    luaL_openlibs(Lua);

    //run a Lua script here
    while (true)
        luaL_dofile(Lua,"foo.lua");

    std::cout << "AWWWw yeeeeee" << std::endl;

    lua_close(Lua);

    return 0;
}
*/

// Added LuaBridge

#include <lua.hpp>
#include <LuaBridge.h>
#include <iostream>

using namespace luabridge;

// Test function to call from Lua
int numTimes2(int num)
{
    return num * 2;
}

int main() {
    // Instanciate Lua state
    lua_State* L = luaL_newstate();

    // Open Lua libs
    luaL_openlibs(L);

    // Make numTimes2 accessible to Lua State
    getGlobalNamespace(L).addFunction("numTimes2", numTimes2);

    // Runs the script
    luaL_dofile(L, "testluabridge.lua");

    // Have no idea what this even does, since dofile runs/calls the script
    lua_pcall(L, 0, 0, 0);

    // Objects Containing the Lua variables
    LuaRef s = getGlobal(L, "testString");
    LuaRef n = getGlobal(L, "number");
    LuaRef sumNumbers = getGlobal(L, "sumNumbers");

    // Cast Refs to appropriate type
    std::string luaString = s.cast<std::string>();
    int answer = n.cast<int>();

    // Print
    std::cout << luaString << std::endl;
    std::cout << "And here's our number:" << answer << std::endl;
    std::cout << "Calling Lua function from C++: " << sumNumbers(2,20) << std::endl;

    // Why can't I close state? Why it breaks?
    // Close state
    //lua_close(L);
}
