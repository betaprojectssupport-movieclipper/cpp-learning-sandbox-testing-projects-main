#pragma once
#include <iostream>

// why c++ why...
namespace engine
{
	namespace log
	{
		template<typename T>
		void print(const T& value) // Optimized for strings/objects
		{
#ifndef NDEBUG
			std::cout << "[INFO]: " << value << "\n";
#endif
		}

		template<typename T>
		void printloc(T x, T y, T z) // Kept by value (best for float/int coordinates)
		{
#ifndef NDEBUG
			std::cout << "[INFO]: X: " << x << " Y: " << y << " Z: " << z << "\n";
#endif
		}

		template<typename T>
		void warn(const T& msg) // Optimized for strings/objects
		{
#ifndef NDEBUG
			std::cout << "[WARN]: " << msg << "\n";
#endif
		}
	}
}
