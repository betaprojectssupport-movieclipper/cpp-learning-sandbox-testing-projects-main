#include <iostream>
#include <vector>
// please note that the user should be allowed to put multiple of the same types of food in their basket
struct foods
{
	std::vector<float> prices;

	void applyBasket(std::string &option)
	{
		if (option == "Eggs"){ prices.push_back(3.50f); }
		else if (option == "Jam"){ prices.push_back(2.49f); }
		else if (option == "Doughnuts"){ prices.push_back(4.10f); }
		else if (option == "Meat"){ prices.push_back(6.99f); }
		else if (option == "Milk"){ prices.push_back(4.15f); }
		else { std::cout << "Sorry Sir thats not a thing in this shop, NOW GET OUT!!"; exit(0); }
	}
};

static void yes(foods &food, std::string &choice)
{
	std::cout << "\nYes actually, I would also like to buy ";
	std::cin >> choice;
	food.applyBasket(choice);
	std::cout << "\nGreat choice, anything else Sir?\n";
	std::cout << "(y/n): ";
	std::cin >> choice;
	if (choice == "y")
	{
		yes(food, choice);
	}
}


int main()
{
	std::string choice;
	float total = 0.0f;
	foods food;

	std::cout << "Pick what you would like to purchase:" << '\n';
	std::cout << "Eggs - $3.50\n";
	std::cout << "Jam - $2.49\n";
	std::cout << "Doughnuts - $4.10\n";
	std::cout << "Meat - $6.99\n";
	std::cout << "Milk - $4.15\n";
	std::cout << "Hmm I would like to buy ";
	std::cin >> choice;
	food.applyBasket(choice);
	std::cout << "\nGreat choice, anything else Sir?\n";
	std::cout << "(y/n): ";
	std::cin >> choice;

	while (choice == "y")
	{
		yes(food, choice);
		break;
	}
	if (choice == "n")
	{
		for (float price : food.prices)
		{
			total += price;
		}

		std::cout << "\nAlright Sir, your total is $" << total;
	}
	else
	{
		std::cout << "Wrong choice Sir, NOW GET OUT!!";
		exit(0);
	}
}
