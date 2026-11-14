#include "base1.h"

void print1()
{
	std::cout << R"(================================
     ROCK - PAPER - SCISSORS
================================

[1] Play Game
[2] Exit

Select an option: )";
}

void print2()
{
	std::cout << R"(
--------------------------------
             BEGIN
--------------------------------

[1] Rock
[2] Paper
[3] Scissors

Your choice: )";
}
void print3(const std::string& sPc, const std::string& sCpu, int& pwins, int& cwins, int& draws)
{
	if ((sPc == "Rock" && sCpu == "Scissors") || (sPc == "Scissors" && sCpu == "Paper") || (sPc == "Paper" && sCpu == "Rock"))
	{
		pwins += 1;
		std::cout << "\nYou picked:      " << sPc << "\nComputer picked: " << sCpu << "\n\n";
		std::cout << sPc << " beats " << sCpu << "!\nYou win this round!\n";
		std::cout << "----------------------------------\n";
		std::cout << "Player: " << pwins << "| Computer: " << cwins << "| Draws : " << draws << '\n';
		std::cout << "----------------------------------\n";
	}
	else if (sCpu == sPc)
	{
		draws += 1;
		std::cout << "\nYou picked:      " << sPc << "\nComputer picked: " << sCpu << "\n\n";
		std::cout << "You both picked " << sPc << "!\nIt's a tie!\n";
		std::cout << "----------------------------------\n";
		std::cout << "Player: " << pwins << "| Computer: " << cwins << "| Draws : " << draws << '\n';
		std::cout << "----------------------------------\n";
	}
	else
	{
		cwins += 1;
		std::cout << "\nYou picked:      " << sPc << "\nComputer picked: " << sCpu << "\n\n";
		std::cout << sCpu << " beats " << sPc << "!\nYou lost this round!";
		std::cout << "----------------------------------\n";
		std::cout << "Player: " << pwins << "| Computer: " << cwins << "| Draws : " << draws << '\n';
		std::cout << "----------------------------------\n";
	}
}
void print4()
{
	std::cout << "Play again ? (Y / N) : ";
}
void print5(int pwins, int cwins, int draws)
{
	std::cout << "\n\n";
	std::cout << R"(================================
          FINAL RESULTS
================================)" << "\n\n";
	std::cout << "Wins:          " << pwins << '\n';
	std::cout << "Losses:        " << cwins << '\n';
	std::cout << "Draws:         " << draws << "\n\n";
	std::cout << R"(Thanks for playing!

Press anything to quit...)";
}
