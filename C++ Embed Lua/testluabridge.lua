-- Global variables
testString = "LuaBridge works!"
number = 42

-- Call a function defined in C++
print(numTimes2(5))

-- Defines function to be used by C++
sumNumbers = function(a,b)
    return a + b
end
