#pragma once
#include <iostream>
// btw i structured it like this with the engine namespace so its easier to work with
// why c++ why...
namespace engine
{
	// logger
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
		void printloc(T x, T y, T z)
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
	
	// math

	namespace math
	{
		// variables
		constexpr float PI = 3.14159265358979323846f; // 1/2 Circle (180 degrees)
		constexpr float TWO_PI = PI * 2.0f; // 1 circle (360 Degrees)
		constexpr float HALF_PI = PI * 0.5f; // 1/4 cirlce (90 Degrees)
		float dt = 0.0166667f; // base set for 60fps 

		constexpr float setDt(float fps) { dt = 1.0f / fps; }
		constexpr float toRadians(float degrees) { return degrees * (PI / 180.0f); }
		constexpr float toDegrees(float radians) { return radians * (180.0f / PI); }
		constexpr float lerp(float a, float b, float t) { return a + (b - a) * t; }
		constexpr float clamp(float value, float min, float max) 
		{
			if (value < min) return min;
			if (value > max) return max;
			return value;
		}
	}
}
