#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	Weapon club = Weapon("Club");

	HumanA bob = HumanA("Bob", club);

	HumanB ali = HumanB("ali");

	ali.attack();
	ali.set_weapon(club);

	bob.attack();
	ali.attack();

	club.setType("clubby");

	bob.attack();
	ali.attack();
}
