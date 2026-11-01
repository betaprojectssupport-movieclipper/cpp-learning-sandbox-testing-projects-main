#include<iostream>
#include <cstdlib> 
#include"logger.h"
#include"operator.h"
//THIS WAS CREATED BY c++profolio13yr
// very important things
// note this is not the final version
// thanks for downloading either way, and have fun cheating :)



int main()
{
	int iOperation;
	const int iAmmountOperations = 12; // ALWAYS CHANGE THIS MF IF ADDING ANOTHER OPERATION
	logbase();


	while (true)
	{
		std::cout << "Select operation to proceed with (or 0 to quit): ";
		std::cin >> iOperation;

		// 1. If they type 0, instantly close the program!
		if (iOperation == 0)
		{
			std::cout << "\nExiting program...\n";
			exit(0);
		}

		// 2. Your exact validation check (allowing 1 to "?")
		if (std::cin.fail() || iOperation < 1 || iOperation > iAmmountOperations)
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');

			std::cout << "Please input a valid number.. \n\n";
		}
		else
		{
			printoperations(iOperation);
			std::cout << "\n\n";
		}
	}
}