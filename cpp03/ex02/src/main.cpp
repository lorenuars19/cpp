#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("bob");
	ScavTrap c("ali");
	FragTrap d("frag");

	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(10);
	std::cout << std::endl;

	b.takeDamage(3);
	b.attack(c.get_name());
	b.beRepaired(2);
	b.takeDamage(11);
	std::cout << std::endl;

	c.takeDamage(42);
	c.attack(b.get_name());
	c.beRepaired(20);
	c.takeDamage(10);
	c.guardGate();
	c.takeDamage(110);
	c.guardGate();
	std::cout << std::endl;

	d.takeDamage(42);
	d.attack(b.get_name());
	d.beRepaired(20);
	d.takeDamage(10);
	d.highFiveGuys();
	d.takeDamage(110);
	d.highFiveGuys();

	ClapTrap ener("Energy");
	for (int i = 0; i < 11; i++)
	{
		ener.attack("Dummy");
	}
}
