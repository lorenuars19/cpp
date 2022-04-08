#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void)
{
	Weapon club = Weapon("Club");

	HumanA bob = HumanA("Bob", club);

	// HumanB ali = HumanB("ali");

	// ali.set_weapon(club);

	bob.attack();

	// ali.attack();

	club.setType("NONE");

	bob.attack();
	// ali.attack();
}
