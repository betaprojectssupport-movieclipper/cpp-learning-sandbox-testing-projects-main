#include <iostream>
#include <string>
#include "base1.h"

static void initGame(int& userWins, int& cpuWins, int& iDraws);

int main()
{
	int userWins = 0;
	int cpuWins = 0;
	int iDraws = 0;

	initGame(userWins, cpuWins, iDraws);
}

void initGame(int& userWins, int& cpuWins, int& iDraws)
{
	// initialises all the variables
	srand(time(NULL));
	int cpu = rand() % 3;

	std::string sPcName; // just shows if rock paper or scissors
	std::string sCpuName = (cpu == 0) ? "Rock" : (cpu == 1) ? "Paper" : "Scissors";
	int ans = 0;
	char cAns;

	// main part


	print1();
	std::cin >> ans;
	if (ans != 2) { print2(); }
	else { exit(0); }

	std::cin >> ans;
	sPcName = (ans == 0) ? "Rock" : (ans == 1) ? "Paper" : "Scissors";
	print3(sPcName, sCpuName, userWins, cpuWins, iDraws);
	print4();
	std::cin >> cAns;
	if (cAns == 'Y')
	{
		initGame(userWins, cpuWins, iDraws);
	}
	else
	{
		print5(userWins, cpuWins, iDraws);
	}
}
