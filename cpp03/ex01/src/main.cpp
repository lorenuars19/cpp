#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("bob");
	ScavTrap c("ali");

	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(10);

	b.takeDamage(3);
	b.attack(c.get_name());
	b.beRepaired(2);
	b.takeDamage(11);

	c.takeDamage(42);
	c.attack(b.get_name());
	c.beRepaired(20);
	c.takeDamage(10);
	c.guardGate();
	c.takeDamage(110);
	c.guardGate();
}
