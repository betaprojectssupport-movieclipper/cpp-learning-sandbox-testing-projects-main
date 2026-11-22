#include <iostream>
#include "Engine.h"
// PLEASE NOT THIS ISNT NEEDED JUST FOR SHOWING OFF THAT IT WORKS
int main()
{
    // 1. Testing engine::log
    engine::log::print("=== Starting Engine Tests ===");
    engine::log::print(42);
    engine::log::printloc(10.5f, 20.0f, -5.25f);
    engine::log::warn("Low memory or frame drop!");
    engine::log::error("Failed to load texture!");

    // 2. Testing engine::math constants and delta time
    engine::log::print("--- Math Tests ---");
    engine::log::print(engine::math::PI);
    engine::log::print(engine::math::TWO_PI);
    engine::log::print(engine::math::HALF_PI);

    engine::log::print(engine::math::dt); // Default 60 FPS (~0.0166667)
    engine::math::setDt(120.0f);
    engine::log::print(engine::math::dt); // Updated 120 FPS (~0.00833333)

    // 3. Testing angle conversions
    float rad = engine::math::toRadians(180.0f); // Should be ~3.14159 (PI)
    float deg = engine::math::toDegrees(engine::math::HALF_PI); // Should be 90
    engine::log::print(rad);
    engine::log::print(deg);

    // 4. Testing lerp and clamp
    float mid = engine::math::lerp(0.0f, 100.0f, 0.25f); // 25% between 0 and 100 = 25
    float clampedHigh = engine::math::clamp(150.0f, 0.0f, 100.0f); // Should clamp to 100
    float clampedLow = engine::math::clamp(-20.0f, 0.0f, 100.0f);  // Should clamp to 0

    engine::log::print(mid);
    engine::log::print(clampedHigh);
    engine::log::print(clampedLow);
    return 0;
}
