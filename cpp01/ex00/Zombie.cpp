#include "Zombie.hpp"

// ----------------------------- Constructors ------------------------------ //
Zombie::Zombie()
{
	_name = "";
	_AUTO(32, "Default Constructor");
}

Zombie::Zombie(const Zombie &copy)
{
	_name = copy.get_name();
	_AUTO(32, "Copy Constructor");
}

Zombie::Zombie(const std::string name) : _name(name)
{
	_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Zombie::~Zombie()
{
	_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Zombie &Zombie::operator=(const Zombie &assign)
{
	_name = assign.get_name();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

std::string Zombie::get_name() const
{
	return _name;
}

// --------------------------------- Methods ------------------------------- //

void Zombie::anounce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..."
			  << std::endl;
}
