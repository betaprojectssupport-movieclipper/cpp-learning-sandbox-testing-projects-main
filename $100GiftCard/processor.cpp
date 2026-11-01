#include<iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "process.h"


//"main" process for all the printing
void Termination(std::string answer, int i, int time)
{
	// if friend says no :(
	if (answer == "NO")
	{
		std::cout << "\nABORTING PROCESS!!\n";
	}

	// if freind says yes :)
	else if (answer == "YES")
	{
		while (i <= 19432)
		{
			std::cout << i << " files lost in downloads & documents" << "\n";

			if (i > 18000)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(80)); //default 80ms near end
				i += 1;
			}
			else
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(2)); //default 2ms at start
				i += 37;
			}
		}
		std::cout << "\nSYSTEM TERMINATION COMPLETE. TOTAL FILES WIPED: " << 19432 << "\n\n";
		if (i >= 19432)
		{
			while (time > 0)
			{
				std::cout << "Exiting in " << time << " seconds..\n";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				time--;
			}

			if (time == 0)
			{
				std::exit(0);
			}
		}
	}

	//if freind is dumb >:(
	else
	{
		std::cout << "\nunknown command please restart the program..\n";
	}
}