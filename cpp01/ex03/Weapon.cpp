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
	// _AUTO(33, "Getter");
	return _type;
}

void Weapon::setType(std::string input)
{
	_AUTO(34, "Setter") << "| old(" << _type
						<< ") new(" << input << ") "
						<< std::endl;
	_type = input;
}

// --------------------------------- Methods ------------------------------- //
