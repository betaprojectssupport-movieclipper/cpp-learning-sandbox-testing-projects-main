#include <iostream>
#include <random>
// btw this was relevant back in 2026
// i have no affiliation if he gets into any drama later
// this is simply just a joke program i made when he was relevant
// and "ballright" was funny and relevant!!!

int main()
{
	// random number bs
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(1, 28);
	int randint = distrib(gen);


	// im sorry..
	const char* name[28] = 
	{	"baz","bazab","badaz","bazalaz","buzz","balz","mmb","z","lav","neth","enderdraga","enderdragon",
		"darthmaul","darthvader","renn","lamelob","victorwembey","jshockbawl","fortnite","bipidybopidyb",
		"blabbadabbab","flavadubba","flabababab","flabadababflabazadalacal","rabatabaflaflabajaj",
		"bazabagatafav","supercalifragilisticexpialadall"
	};

	std::cout << name[randint] << "alright";
}
