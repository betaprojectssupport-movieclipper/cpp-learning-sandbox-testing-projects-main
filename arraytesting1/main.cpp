#include <iostream>

int main()
{
	// the 2 variables below should be put largest to smallest however ibaseNums is needed inside the array so :(
	constexpr int ibaseNums = 10;  //i know rockstar loves constexpr in game engines
	int numberArray[ibaseNums];

	int* ptr = numberArray;
	*(ptr + 2) = 13; // quite useless since it gets overwritten so dont penalise me I did this to show how ptr's work inside a array.


	for (int i = 0; i < ibaseNums; ++i)
	{
		numberArray[i] = i;
		std::cout << "number -> " << numberArray[i] << "    :    memory location -> " << &numberArray[i] << '\n';
	}

	std::cin.get();
}
