#include "HumanA.hpp"

Weapon _defaultWeapon = Weapon();

// ----------------------------- Constructors ------------------------------ //
HumanA::HumanA(void) : _name(""), _weapon(_defaultWeapon)
{
	// _weapon = ;
	_AUTO(32, "Default Constructor") << std::endl;
}

HumanA::HumanA(const HumanA &copy) : _name(copy.get_name()),
									 _weapon(copy.get_weapon())
{
	// _weapon = copy.get_weapon();
	_AUTO(32, "Copy Constructor") << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name),
												   _weapon(weapon)
{
	_AUTO(32, "Fields Constructor") << std::endl;
}

// ------------------------------ Destructor ------------------------------- //
HumanA::~HumanA(void)
{
	_AUTO(31, "Destructor called") << std::endl;
}
// ------------------------------- Operators ------------------------------- //

HumanA &HumanA::operator=(const HumanA &assign)
{
	_name = assign.get_name();
	_weapon = assign.get_weapon();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
std::string HumanA::get_name(void) const
{
	_AUTO(33, "Getter") << std::endl;
	return _name;
}

void HumanA::set_name(int input)
{
	_AUTO(34, "Setter") << " Old " << _name << " New " << input << std::endl;
	_name = input;
}

Weapon &HumanA::get_weapon(void) const
{
	_AUTO(33, "Getter") << std::endl;
	return _weapon;
}

void HumanA::set_weapon(Weapon &input)
{
	_AUTO(34, "Setter") << "| old(" << _weapon.getType()
						<< ") new(" << input.getType() << ") "
						<< std::endl;
	_weapon = input;
}

// --------------------------------- Methods ------------------------------- //
void HumanA::attack(void)
{
	std::cout << _name << " attacks with "
			  << _weapon.getType()
			  << std::endl;
}
