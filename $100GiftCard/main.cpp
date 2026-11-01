//THIS WAS CREATED BY c++profolio13yr
// very important things
// note this is a PRANK no data is actually lost, so dont worry but if you wanted it to be real.. dont ask me
// thanks for downloading either way, and have fun pranking your friends!!
#include <iostream>
#include<string>
#include "process.h"

//actual 'main' process
int main()
{
	int i = 1;
	int time = 5;
	std::string ans;
	std::cout << "Data Will Be lost! Are you Sure You Want To Proceed?! " << "\nType 'YES' if your sure, type 'NO' if you want to cancel: ";
	std::cin >> ans;
	Termination(ans, i, time);
}
