#include "Zombie.hpp"

int main(void)
{
	Zombie z("Zmob");

	z.anounce();

	Zombie *ptr;

	ptr = newZombie("Alloc");
	ptr->anounce();
	// delete ptr;

	randomChump("Wesh");

	system("leaks exec.out");

	return 0;
}
