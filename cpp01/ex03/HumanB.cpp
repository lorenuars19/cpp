#include "HumanB.hpp"

// ----------------------------- Constructors ------------------------------ //
HumanB::HumanB() : _name(""), _weapon(NULL)
{
	_AUTO(32, "Default Constructor") << std::endl;
}

HumanB::HumanB(const HumanB &copy) : _name(copy.get_name()),
									 _weapon(&(copy.get_weapon()))
{
	_AUTO(32, "Copy Constructor") << std::endl;
}

HumanB::HumanB(std::string name) : _name(name),
								   _weapon(NULL)
{
	_AUTO(32, "Fields Constructor") << std::endl;
}

// ------------------------------ Destructor ------------------------------- //
HumanB::~HumanB()
{
	_AUTO(31, "Destructor called") << std::endl;
}
// ------------------------------- Operators ------------------------------- //

HumanB &HumanB::operator=(const HumanB &assign)
{
	_name = assign.get_name();
	_weapon = &(assign.get_weapon());
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
std::string HumanB::get_name() const
{
	_AUTO(33, "Getter") << std::endl;
	return _name;
}

void HumanB::set_name(int input)
{
	_AUTO(34, "Setter") << " Old " << _name << " New " << input << std::endl;
	_name = input;
}

Weapon &HumanB::get_weapon() const
{
	_AUTO(33, "Getter") << std::endl;
	return (Weapon &)*_weapon;
}

void HumanB::set_weapon(Weapon &input)
{
	_AUTO(34, "Setter");
	if (_weapon)
	{
		std::cout << "| old(" << _weapon->getType()
				  << ") new(" << input.getType() << ") "
				  << std::endl;
	}
	std::cout << std::endl;
	_weapon = &input;
}

// --------------------------------- Methods ------------------------------- //
void HumanB::attack()
{
	std::cout << _name << " attacks with ";
	if (_weapon)
	{
		std::cout << _weapon->getType();
	}
	else
	{
		std::cout << "no weapon";
	}
	std::cout << std::endl;
}
