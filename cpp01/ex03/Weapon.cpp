#include "Weapon.hpp"

// ----------------------------- Constructors ------------------------------ //
Weapon::Weapon(void)
{
	_type = "";
	_AUTO(32, "Default Constructor") << std::endl;
}

Weapon::Weapon(const Weapon &copy)
{
	_type = copy.getType();
	_AUTO(32, "Copy Constructor") << std::endl;
}

Weapon::Weapon(std::string type) : _type(type)
{
	_AUTO(32, "Fields Constructor") << std::endl;
}

// ------------------------------ Destructor ------------------------------- //
Weapon::~Weapon(void)
{
	_AUTO(31, "Destructor called") << std::endl;
}
// ------------------------------- Operators ------------------------------- //

Weapon &Weapon::operator=(const Weapon &assign)
{
	_type = assign.getType();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
std::string Weapon::getType(void) const
{
	_AUTO(33, "Getter") << std::endl;
	return _type;
}

void Weapon::setType(int input)
{
	_AUTO(34, "Setter") << " Old " << _type << " New " << input << std::endl;
	_type = input;
}

// --------------------------------- Methods ------------------------------- //

