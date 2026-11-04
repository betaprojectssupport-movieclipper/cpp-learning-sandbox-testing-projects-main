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


void bannerInit()
{
	std::ifstream file("C:\\dev1\\m.i.l\\m.i.l\\src\\banner.txt"); // IMPORTANT THIS IS ONLY SUTIABLE FOR MY DEVICE YOU NEED TO SET IT UP FOR YOURSELF

	std::string line;
	while (std::getline(file, line)) {
		std::cout << line << '\n';
	}
}

// weapons as namespaces cause im dont know advanced enum stuff, and raw ints are quite bad for this
// we're usng constexpr because its best for optimisation
namespace Weapons {
	constexpr int FISTS = 0;
	constexpr int DAGGER = 1;
	constexpr int SWORD = 2;
	constexpr int GREAT_AXE = 3;
	constexpr int AK47 = 4;
}

class Player
{
protected:
	int weaponDamage[5] = { 11, 21, 43, 79, 97 };

	int health = 100;
	int currentWeapon = Weapons::FISTS;
	int curWpDamage = weaponDamage[currentWeapon];

private:

	void applyDamageEnemy(enemy &cEnemy) { cEnemy.health -=}
	void setWeapon(int WeaponID) { currentWeapon = WeaponID; }

public:
	std::string name;

	Player() : name("Player") {}
	Player(std::string &customName) : name(customName) {}
};

class enemy : public Player
{	

};

int main()
{
	bannerInit();


}