#include "Zombie.hpp"

int main()
{
	Zombie z("Zmob");

	z.anounce();

	Zombie *ptr;

	ptr = newZombie("Alloc");
	ptr->anounce();
	delete ptr;

	randomChump("Wesh");

	return 0;
}
