#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("bob");
	ClapTrap c("ali");

	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(10);

	b.takeDamage(3);
	b.attack(c.get_name());
	b.beRepaired(2);
	b.takeDamage(11);

	ClapTrap ener("Energy");
	for (int i = 0; i < 11; i++)
	{
		ener.attack("Dummy");
	}
}
