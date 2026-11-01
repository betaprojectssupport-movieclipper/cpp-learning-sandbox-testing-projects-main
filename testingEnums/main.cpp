#include <iostream>
#include <string>

enum gender : bool
{
	male = true,
	woman = false,
};

int main()
{
	gender Andrei = male;
	if (Andrei == male)
	{
		std::cout << "Your Male.";
	}
	else if (Andrei == woman)
	{
		std::cout << "Your Female";
	}
}