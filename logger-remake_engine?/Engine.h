#pragma once
#include <iostream>
// btw i structured it like this with the engine namespace so its easier to work with
// why c++ why...

namespace engine
{
	inline float dt = 0.0166667f; // base set for 60fps

	// time

	namespace time
	{
		struct Timer
		{
			float duration = 1.0f;
			float elapsed = 0.0f;
			bool active = false;

			// user calls this ONCE when an event happens (e.g. button press, taking damage)
			void begin(float newDuration)
			{
				duration = newDuration;
				elapsed = 0.0f;
				active = true;
			}

			// put this in your main loop (does nothing unless active == true)
			void update()
			{
				if (!active) return;

				elapsed += dt;
				if (elapsed >= duration)
				{
					elapsed = duration;
					active = false;
				}
			}

			// checks whether the timer has finished
			bool isDone() const { return !active && elapsed >= duration; }
		};

		struct stopwatch
		{
			float elapsed = 0.0f;
			bool active = false;

			// user calls this ONCE for tracking time (e.g. time taken in a race)
			void activate(float newDuration)
			{
				elapsed = 0.0f;
				active = true;
			}
			// creates a new instance of the stopwatch
			float begin() { if (active) { return elapsed += dt; } }
			// checks wheather the stopwatch is active and running
			bool isRunning() const { return active; }
			// stops stopwatch and returns time elapsed (returns just in case)
			float end() { active = false; return elapsed; }
		};
	}
	// logger
	namespace log
	{
#ifndef NDEBUG
		// just debug colours for the text
		constexpr const char* WHITE = "\033[97m";
		constexpr const char* YELLOW = "\033[93m";
		constexpr const char* RED = "\033[31m";
		constexpr const char* RESET = "\033[0m";

#endif

		template<typename T>
		void print(const T& value)
		{
#ifndef NDEBUG
			std::cout << WHITE << "[INFO]: " << value << RESET << "\n";
#endif
		}

		template<typename T>
		void printloc(T x, T y, T z)
		{
#ifndef NDEBUG
			std::cout << WHITE << "[INFO]: X: " << x << " Y: " << y << " Z: " << z << RESET << "\n";
#endif
		}

		template<typename T>
		void warn(const T& msg)	
		{
#ifndef NDEBUG
			std::cout << YELLOW << "[WARN]: " << msg << RESET << std::endl; // use endl so if program crashes it's printed pre-crash
#endif
		}

		template<typename T>
		void error(const T& msg)
		{
#ifndef NDEBUG
			std::cout << RED << "[ERROR]: " << msg << RESET << std::endl; // use endl so if program crashes it's printed pre-crash
#endif
		}
	}
	
	// math

	namespace math
	{
		// variables
		constexpr float PI = 3.14159265358979323846f;
		constexpr float TWO_PI = PI * 2.0f;
		constexpr float HALF_PI = PI * 0.5f;

		constexpr void setDt(float fps) { dt = 1.0f / fps; }
		constexpr float toRadians(float degrees) { return degrees * (PI / 180.0f); }
		constexpr float toDegrees(float radians) { return radians * (180.0f / PI); }
		constexpr float lerp(float a, float b, float t) { return a + (b - a) * t; }
		constexpr float clamp(float value, float min, float max)
		{
			if (value < min) { return min; }
			if (value > max) { return max; }
			return value;
		}
	}
}
