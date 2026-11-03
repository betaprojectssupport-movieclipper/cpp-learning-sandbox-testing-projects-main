#include <iostream>
#include <string>

//best optimised code i could do at this level

class entity
{
public:
	std::string name;
	float x_pos = 0.0f;
	float y_pos = 0.0f;	
};

static void logPos(float x, float y) // static cause all it does is print NOT change variables also its not worth it to get the memory adress of x,y nor make them const.
{
	std::cout << x << " " << y << std::endl; // endl because sometimes the game can crash cause you like get flung or something so this is needed so you know the pos
}

static void logName(const std::string &name)
{
	std::cout << name << '\n'; // a character name so no need for endl
}


int main()
{
	entity Andrei;
	Andrei.name = "Andrei";
	logPos(Andrei.x_pos, Andrei.y_pos);
	logName(Andrei.name);
}