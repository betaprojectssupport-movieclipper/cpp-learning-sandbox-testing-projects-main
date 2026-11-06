#include <iostream>
#include <fstream>
#include <string>


/////////////////////////////////////////////////////
//   __          __        _____         _____     //
//   \ \        / /       |_   _|       |  __ \    //
//    \ \  /\  / /          | |         | |__) |   //
//     \ \/  \/ /           | |         |  ___/    //
//      \  /\  /    _      _| |_    _   | |        //
//       \/  \/    (_)    |_____|  (_)  |_|        //
/////////////////////////////////////////////////////


int weaponDamage[5];


////////////////////////////
// CLASSES AND NAMESPACES //
////////////////////////////


// weapons as namespaces cause im dont know advanced enum stuff, and raw ints are quite bad for this
// we're usng constexpr because its best for optimisation
namespace Weapons
{
	int id;
	namespace Fists
	{
		constexpr int id = 0;
		constexpr int weaponDamage = 11;
	}

	namespace Dagger
	{
		constexpr int id = 1;
		constexpr int weaponDamage = 21;
	}

	namespace Sword
	{
		constexpr int id = 2;
		constexpr int weaponDamage = 43;
	}

	namespace GreatAxe
	{
		constexpr int id = 3;
		constexpr int weaponDamage = 79;
	}

	namespace AK47
	{
		constexpr int id = 4;
		constexpr int weaponDamage = 97;
	}
}

class enemy; // forward declaration so there is no error

class Player
{
public:
	int weaponDamage[5] = { 11, 21, 43, 79, 97 };

	int health = 100;
	int currentWeapon = Weapons::id;
	int curWpDamage = weaponDamage[currentWeapon];

	std::string name;

	Player() : name("Player") {}

	void applyDamageEnemy(class enemy& cEnemy); // initalize the function so it can be used in main and since OF THE ENEMY CLASS IS INHERITING THIS IS SADLY NOT WORKING IF I DONT INITALIZE IT HERE >:(
	void setWeapon(int WeaponID) { currentWeapon = WeaponID; }
};

class enemy : public Player {};

void Player::applyDamageEnemy(enemy& cEnemy) { cEnemy.health -= curWpDamage; }

void Init()
{
	std::ifstream file("C:\\dev1\\m.i.l\\m.i.l\\src\\banner.txt"); // IMPORTANT THIS IS ONLY SUTIABLE FOR MY DEVICE YOU NEED TO SET IT UP FOR YOURSELF

	std::string line;
	while (std::getline(file, line)) {
		std::cout << line << "\n";
	}
	std::cout << '\n'; // needed after the banner for spacing


	// print the commands for the player
	std::cout << "COMMANDS:\n";
	std::cout << "--------------------\n";
	std::cout << "1. attack <enemy> - attacks the specified enemy\n";
	std::cout << "2. switch to <weapon> - switches to the specified weapon\n";
	std::cout << "3. exit - exits the game\n\n";
}

namespace Log
{
	void inputstr(std::string prompt, std::string& str)
	{
		std::cout << prompt << "\n> ";
		std::cin >> str;
	}

	// Accept a reference to the Player object
	void logEverything(const Player& p)
	{
		std::cout << "--------------------\n\n";
		std::cout << "Player Name: " << p.name << "\n";
		std::cout << "Player Health: " << p.health << "\n";
		std::cout << "Player Current Weapon: " << p.currentWeapon << "\n";
	}
}

///////////////////
// MAIN FUNCTION //
///////////////////

int main()
{
	Init();

	////////////////////// initalize the player and enemies with their weapons
	Player player;
	player.setWeapon(0);

	enemy ghoul;
	ghoul.setWeapon(0);

	enemy goblin;
	goblin.setWeapon(1);

	enemy skeleton;
	skeleton.setWeapon(2);

	enemy werewolf;
	werewolf.setWeapon(3);
	///////////////////////

	Log::inputstr("Enter your name:", player.name);
	Log::logEverything(player);// log the player info for debugging purposes

	std::cin.get();
}
