#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
#include <vector>
#include <random>

/////////////////////////////////////////////////////
//   __          __        _____         _____     //
//   \ \        / /       |_   _|       |  __ \    //
//    \ \  /\  / /          | |         | |__) |   //
//     \ \/  \/ /           | |         |  ___/    //
//      \  /\  /    _      _| |_    _   | |        //
//       \/  \/    (_)    |_____|  (_)  |_|        //
/////////////////////////////////////////////////////

//program work = true;
//easy reading = no;

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

///////////
//CLASSES//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
class enemy; // forward declaration so there is no error

class Player
{
public:
	int weaponDamage[5] = { 11, 21, 43, 79, 97 };

	int health = 100;
	int currentWeapon = Weapons::id; // CONTAINS WEAPPON ID OF THE CURRENT WEAPON, 0 = FISTS, 1 = DAGGER, 2 = SWORD, 3 = GREAT AXE, 4 = AK47
	int curWpDamage = weaponDamage[currentWeapon];

	std::string name;

	Player() : name("Player") {}

	void applyDamageEnemy(class enemy& cEnemy);// initalize the function so it can be used in main and since OF THE ENEMY CLASS IS INHERITING THIS IS SADLY NOT WORKING IF I DONT INITALIZE IT HERE >:(
	void applyDamagePlayer(class Player& cPlayer, enemy& cEnemy); // same goes for this
	void setWeapon(int WeaponID) { currentWeapon = WeaponID; }
};

class enemy : public Player
{
public:
	int eType; // just means ememy type, 0 = ghoul, 1 = goblin, 2 = skeleton, 3 = werewolf
	void setType(int type) { eType = type; }
};

void Player::applyDamageEnemy(enemy& cEnemy)
{
	cEnemy.health -= curWpDamage;
}

void Player::applyDamagePlayer(Player& cPlayer, enemy& cEnemy)
{
	cPlayer.health -= cEnemy.curWpDamage;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Init()
{
	std::ifstream file("C:\\dev1\\m.i.l\\m.i.l\\src\\banner.txt"); // IMPORTANT THIS IS ONLY SUTIABLE FOR MY DEVICE YOU NEED TO SET IT UP FOR YOURSELF

	std::string line;
	while (std::getline(file, line))
	{
		std::cout << line << "\n";
	}
	std::cout << '\n'; // needed after the banner for spacing

	// print the commands for the player
	std::cout << "COMMANDS:\n";
	std::cout << "--------------------\n";
	std::cout << "1. attack <enemy> - attacks the specified enemy\n";
	std::cout << "2. switch to <weapon> - switches to the specified weapon\n";
	std::cout << "3. exit - exits the game\n";
	std::cout << R"(4. help - displays all commands)" << "\n\n";
}

namespace Log
{
	void inputnamestr(std::string prompt, std::string& str)
	{
		std::cout << prompt << "\n> ";
		std::cin >> str;
	}

	void askifReady(std::string& name)
	{
		std::string response;

		std::cout << "Are you ready, " << name << "? (yes/no)\n> ";
		std::cin >> response;
		if (response == "yes" || response == "y")
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << "Then you weren't chosen to be a hero. Now leave my sight.\n";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			exit(0);
		}
	}

	// Accept a reference to the Player object
	void logEverything(const Player& p)
	{
		std::cout << "--------------------\n";
		std::cout << "Player Name: " << p.name << "\n";
		std::cout << "Player Health: " << p.health << "\n";
		std::cout << "Player Current Weapon: " << p.currentWeapon << "\n";
	}
}

////////////////////
// MAIN FUNCTIONS //
////////////////////

void attackPlayer(enemy& enemy, Player& player)
{
	std::cout << enemy.name << " attacked " << player.name << " for " << player.curWpDamage << " damage!\n";
	std::cout << player.name << " has " << player.health << " health remaining.\n";
}

void PlayIntro(Player& player)
{
	std::cout << "\n=======================================================\n";
	std::cout << "Welcome " << player.name << ", to the battle of a lifetime...\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "The realm has fallen into absolute chaos.\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Ghouls, goblins and ancient skeletons roam the wilds.\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "With only your wits and your weapons, you must survive.\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Prepare yourself... your journey begins now.\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "=======================================================\n\n";
}

void chooseWeapon(Player& player)
{
	std::cout << "Choose your weapon:\n";
	std::cout << "0. Fists\n";
	std::cout << "1. Dagger\n";
	std::cout << "2. Sword\n";
	std::cout << "3. Great Axe\n";
	std::cout << "4. AK47\n";
	std::cout << "> ";
	int choice;
	std::cin >> choice;
	if (choice >= 0 && choice <= 4)
	{
		player.setWeapon(choice);
		player.curWpDamage = player.weaponDamage[choice];
		std::cout << "You have chosen: ";

		if (choice == 0)
			std::cout << "Fists\n\n";
		else if (choice == 1)
			std::cout << "Dagger\n\n";
		else if (choice == 2)
			std::cout << "Sword\n\n";
		else if (choice == 3)
			std::cout << "Great Axe\n\n";
		else if (choice == 4)
			std::cout << "AK47\n\n";
	}
	else
	{
		std::cout << "Invalid choice. Please choose a valid weapon.\n\n";
		chooseWeapon(player); // recursively call the function until a valid choice is made
	}
}

void beginBattle(enemy& e, Player& player)
{
	std::string playerWeaponName;
	if (player.currentWeapon == 0) playerWeaponName = "Fists";
	else if (player.currentWeapon == 1) playerWeaponName = "Dagger";
	else if (player.currentWeapon == 2) playerWeaponName = "Sword";
	else if (player.currentWeapon == 3) playerWeaponName = "Great Axe";
	else if (player.currentWeapon == 4) playerWeaponName = "AK47";

	std::string enemyWeaponName;
	if (e.currentWeapon == 0) enemyWeaponName = "Fists";
	else if (e.currentWeapon == 1) enemyWeaponName = "Dagger";
	else if (e.currentWeapon == 2) enemyWeaponName = "Sword";
	else if (e.currentWeapon == 3) enemyWeaponName = "Great Axe";
	else if (e.currentWeapon == 4) enemyWeaponName = "AK47";

	std::cout << "=====================================================\n";
	std::cout << "   A " << e.name << " leaps out of nowhere and is angry!\n";
	std::cout << "=====================================================\n\n";
	std::cout << "----------------- BATTLE STATUS ---------------------\n";
	std::cout << "   " << player.name << "        : " << player.health << " HP   [Weapon: " << playerWeaponName << "]\n";
	std::cout << "   " << e.name << "        : " << e.health << " HP   [Weapon: " << enemyWeaponName << "]\n";
	std::cout << "-----------------------------------------------------\n\n";
}

int main()
{
	Init();

	// Changed distribution range to (0, 3) because you have exactly 4 enemy types (indices 0, 1, 2, 3)
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> randEnemy(0, 3);
	int enemyRandType = randEnemy(gen);

	Player player;
	player.setWeapon(0);

	enemy ghoul;
	ghoul.name = "Ghoul";
	ghoul.setWeapon(0);
	ghoul.setType(0);

	enemy goblin;
	goblin.name = "Goblin";
	goblin.setWeapon(1);
	goblin.setType(1);

	enemy skeleton;
	skeleton.name = "Skeleton";
	skeleton.setWeapon(2);
	skeleton.setType(2);

	enemy werewolf;
	werewolf.name = "Werewolf";
	werewolf.setWeapon(3);
	werewolf.setType(3);

	Log::inputnamestr("Enter your name:", player.name);
	PlayIntro(player);
	chooseWeapon(player);
	Log::askifReady(player.name);

	// Dynamically route the randomly selected enemy to the battle function
	if (enemyRandType == 0)
	{
		beginBattle(ghoul, player);
	}
	else if (enemyRandType == 1)
	{
		beginBattle(goblin, player);
	}
	else if (enemyRandType == 2)
	{
		beginBattle(skeleton, player);
	}
	else if (enemyRandType == 3)
	{
		beginBattle(werewolf, player);
	}

	std::cin.get();
}
