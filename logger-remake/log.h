#pragma once
#include <iostream>

// why c++ why...
namespace engine
{
	namespace log
	{
		template<typename T>
		void print(const T& value)
		{
#ifndef NDEBUG
			std::cout << "[INFO]: " << value << "\n";
#endif
		}

		template<typename T>
		void printloc(T x, T y, T z)  // no touching
		{
#ifndef NDEBUG
			std::cout << "[INFO]: X: " << x << " Y: " << y << " Z: " << z << "\n";
#endif
		}

		template<typename T>
		void warn(const T& msg)
		{
#ifndef NDEBUG
			std::cout << "[WARN]: " << msg << "\n";
#endif
		}
	}
}
