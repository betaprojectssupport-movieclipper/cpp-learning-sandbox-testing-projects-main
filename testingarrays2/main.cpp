#include <iostream>

class Entity
{
public:
	//i fixed it now so no neeed to worry about cpu padding stuff since i just made the small guy static 
	static constexpr int arrayAmmount = 10; // i know im so cool putting in constexpr, rockstar :)
	int numberArray[arrayAmmount];

	Entity()
	{

		//int count = sizeof(numberArray) / sizeof(int)  this is used to practically check how big the array is, it only works for this instance though so it wont for for pointers!!!

		for (int i = 0; i < 10; ++i)
		{
			numberArray[i] = i;
			std::cout << "number -> " << numberArray[i] << "    :    memory location -> " << &numberArray[i] << '\n';
		}
	}
};

int main()
{
	Entity Andrei;

	std::cin.get();
}
