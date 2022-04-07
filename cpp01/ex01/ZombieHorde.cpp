#include "Zombie.hpp"
#include <string>
#include <sstream>

Zombie *zombieHorde(int n, std::string name)
{
	Zombie *zombs = new Zombie[n];

	for (int i = 0; i < n; i++)
	{
		zombs[i].set_name(name);
	}
	return zombs;
}
