#include "FragTrap.hpp"

// ----------------------------- Constructors ------------------------------ //
FragTrap::FragTrap()
{
	set_hp(100);
	set_ep(100);
	set_ap(30);
	_FRAGTRAP_AUTO(32, "Default Constructor");
}

FragTrap::FragTrap(const t &c) : ClapTrap(c.get_name())
{
	(void)c;
	_FRAGTRAP_AUTO(32, "Copy Constructor");
}

FragTrap::FragTrap(std::string input_name)
{
	set_name(input_name);
	set_hp(100);
	set_ep(100);
	set_ap(30);
	_FRAGTRAP_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
FragTrap::~FragTrap()
{
	_FRAGTRAP_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

FragTrap &FragTrap::operator=(const t &a)
{
	(void)a;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
// --------------------------------- Methods ------------------------------- //
void FragTrap::displayStatus()
{
	std::cout << "\e[34;1mFragTrap [" << this
			  << "] name '" << get_name()
			  << "' hp " << get_hp()
			  << ", ep " << get_ep()
			  << ", ap " << get_ap()
			  << " : \e[0m";
}

void FragTrap::highFiveGuys()
{
	displayStatus();
	std::cout << "High five guys" << std::endl;
}
