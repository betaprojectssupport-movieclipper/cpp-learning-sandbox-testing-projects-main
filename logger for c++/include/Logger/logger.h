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
}
