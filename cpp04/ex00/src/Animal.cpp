#include "Animal.hpp"

// ----------------------------- Constructors ------------------------------ //
Animal::Animal(const t &c)
{
	type = c.type;
	_ANIMAL_AUTO(32, "Copy Constructor");
}

Animal::Animal() : type("")
{
	_ANIMAL_AUTO(32, "Default Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Animal::~Animal()
{
	_ANIMAL_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Animal &Animal::operator=(const t &a)
{
	type = a.get_type();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

std::string Animal::get_type() const { return type; }

// --------------------------------- Methods ------------------------------- //
