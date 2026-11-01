#include<iostream>
#include"logger.h"
#include"operator.h"

void logbase()
{
	// The apps name printed at the top, im too lazy to properly format this for you.. sorry :)
	std::cout << R"(#################################
 Welcome User to the one and only
         IDIOT'S PROGRAM
#################################)" << "\n\n" << "Press 'ESC' to Exit the Program\n\n";


	// here are all the operations the user can choose, simple to add one just do
	// std::cout << "(operation)\n\n"; and put your operation in there and MAKE SURE TO ADD the 2 "\n" cause they are needed !!!
	std::cout << "(1) Calculate Area of A Circle by the Radius Way [pi * r ^ 2]\n";
	std::cout << "(2) Calculate Area of A Circle by the Diameter Way [pi * d]\n";
	std::cout << "(3) Calculate Area of A Circle by the Circumference Way [C^2 / (4 * pi)]\n\n"; // 2 "\n" are needed for formatting

	std::cout << "(4) Calculate the area of a Triangle by (Base * Height) / 2\n";
	std::cout << "(5) Calculate the area of a Square by Base * Height\n\n"; // 2 "\n" are needed for formatting

	std::cout << "(6) Adding Numbers together\n";
	std::cout << "(7) Subtracting Numbers\n";
	std::cout << "(8) Multiplying Numbers together\n";
	std::cout << "(9) Dividing Numbers\n";
	std::cout << "(10) Check if a number, when divided by another number is a whole number\n";
	std::cout << "(11) Find the Square Root of a number\n";
	std::cout << "(12) Find The answer of a number to the power of another integer\n\n";
}

void printoperations(int ans) // literal torture	
{
	if (ans < 2)
	{
		circleradius();
	}
	else if (ans < 3)
	{
		circlediameter();
	}
	else if (ans < 4)
	{
		circlecircumference();
	}
	else if (ans < 5)
	{
		trianglearea();
	}
	else if (ans < 6)
	{
		squarearea();
	}
	else if (ans < 7)
	{
		adding();
	}
	else if (ans < 8)
	{
		subracting();
	}
	else if (ans < 9)
	{
		multiplying();
	}
	else if (ans < 10)
	{
		dividing();
	}
	else if (ans < 11)
	{
		divideXbyY();
	}
	else if (ans < 12)
	{
		squareroot();
	}
	else
	{
		bsod();
	}
}