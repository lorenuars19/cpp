#include "ScavTrap.hpp"

// ----------------------------- Constructors ------------------------------ //
ScavTrap::ScavTrap()
{
	set_hp(100);
	set_ep(50);
	set_ap(20);
	_SCAVTRAP_AUTO(32, "Default Constructor");
}

ScavTrap::ScavTrap(const t &c) : ClapTrap(c.get_name())
{
	*this = c;
	_SCAVTRAP_AUTO(32, "Copy Constructor");
}

ScavTrap::ScavTrap(std::string input_name)
{
	set_name(input_name);
	set_hp(100);
	set_ep(50);
	set_ap(20);
	_SCAVTRAP_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
ScavTrap::~ScavTrap()
{
	_SCAVTRAP_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

ScavTrap &ScavTrap::operator=(const t &a)
{
	gate_mode = a.get_gate_mode();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
bool ScavTrap::get_gate_mode() const
{
	return gate_mode;
}

// --------------------------------- Methods ------------------------------- //

void ScavTrap::displayStatus()
{
	std::cout << "\e[34;1mScavTrap [" << this
			  << "] name '" << get_name()
			  << "' hp " << get_hp()
			  << ", ep " << get_ep()
			  << ", ap " << get_ap()
			  << ", gate_mode " << gate_mode
			  << " : \e[0m";
}

void ScavTrap::guardGate()
{
	displayStatus();
	if (ClapTrap::deadCheck())
	{
		return;
	}
	std::cout << " Toggling Guate Garding mode " << std::endl;
	gate_mode = !gate_mode;
	set_ep(get_ep() - 1);
}
