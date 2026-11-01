#include <iostream>

class vehicle
{
public:
	float x;
	float y;

	vehicle(int X, int Y)
	{
		x = X;
		y = Y;

		std::cout << "Vehicle is Created\n";
	}

	~vehicle()
	{
		std::cout << "Vehicle is destroyed\n";
	}

};

void begin()
{
	vehicle lambo(0.0f, 0.0f);
	std::cout << lambo.x << '\n' << lambo.y << std::endl;
}              

int main()
{
	begin();
}