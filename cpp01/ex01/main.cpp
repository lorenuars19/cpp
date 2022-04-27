#include "Zombie.hpp"

#define N_ZOMBS 4

int main()
{
	Zombie *zombs = zombieHorde(N_ZOMBS, "zombot");

	for (int i = 0; i < N_ZOMBS; i++)
	{
		zombs[i].anounce();
	}

	delete[] zombs;
	return 0;
}
