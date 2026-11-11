#pragma once // Your second screenshot snippet goes at the very top!
#include <iostream>

namespace Log
{
    inline void Warn(const char* message)
    {
        std::cout << "[WARNING]: " << message << '\n';
    }

    inline void Info(const char* message)
    {
        std::cout << "[INFO]: " << message << '\n';
    }

    inline void Error(const char* message)
    {
        std::cout << "[ERROR]: " << message << '\n';
    }
    inline void LogPos(float x, float y, float z) // i hope this works i made this for no reason at 10pm in github and didnt test it.
    {
        std::cout << "[INFO]:    X: " << x << ", Y: " << y << ", Z: " << z <<'\n';
    }
}
