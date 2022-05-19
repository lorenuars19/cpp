#include "ClapTrap.hpp"

// ----------------------------- Constructors ------------------------------ //
ClapTrap::ClapTrap() : name(""), hp(10), ep(10), ap(0)
{
	_CLAPTRAP_AUTO(32, "Default Constructor");
}

ClapTrap::ClapTrap(const t &c)
{
	name = c.get_name();
	hp = c.get_hp();
	ep = c.get_ep();
	ap = c.get_ap();
	_CLAPTRAP_AUTO(32, "Copy Constructor");
}

ClapTrap::ClapTrap(std::string input_name) : name(input_name), hp(10), ep(10), ap(0)
{
	_CLAPTRAP_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
ClapTrap::~ClapTrap()
{
	_CLAPTRAP_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

ClapTrap &ClapTrap::operator=(const t &a)
{
	name = a.get_name();
	hp = a.get_hp();
	ep = a.get_ep();
	ap = a.get_ap();
	return *this;
}
// --------------------------- Getters && Setters -------------------------- //
std::string ClapTrap::get_name() const { return name; }
void ClapTrap::set_name(std::string input_name) { name = input_name; }
int ClapTrap::get_hp() const { return hp; }
void ClapTrap::set_hp(unsigned int input) { hp = input; }
int ClapTrap::get_ep() const { return ep; }
void ClapTrap::set_ep(unsigned int input) { ep = input; }
int ClapTrap::get_ap() const { return ap; }
void ClapTrap::set_ap(unsigned int input) { ap = input; }

// --------------------------------- Methods ------------------------------- //

void ClapTrap::displayStatus()
{
	std::cout << "\e[34;1mClapTrap [" << this
			  << "] name '" << name
			  << "' hp " << hp
			  << ", ep " << ep
			  << ", ap " << ap
			  << " : \e[0m";
}

int ClapTrap::deadCheck()
{
	if (hp <= 0 || ep <= 0)
	{
		std::cout << "is dead" << std::endl;
		return (1);
	}
	return (0);
}

void ClapTrap::attack(const std::string &target)
{
	displayStatus();
	if (deadCheck())
	{
		return;
	}
	std::cout << " attacks " << target
			  << " causing " << ap
			  << " points of damage";
	std::cout << std::endl;
	ep--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	displayStatus();
	if (deadCheck())
	{
		return;
	}
	if (amount >= hp)
	{
		amount = hp;
	}
	std::cout << " takes " << amount
			  << " points of damage";
	hp -= amount;
	if (hp <= 0)
	{
		std::cout << " and dies";
	}
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	displayStatus();
	if (deadCheck())
	{
		return;
	}
	std::cout << " is repaired of " << amount
			  << " hp";
	std::cout << std::endl;
	hp += amount;
	ep--;
}
