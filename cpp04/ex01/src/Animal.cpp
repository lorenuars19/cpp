#include "Animal.hpp"

// ----------------------------- Constructors ------------------------------ //
Animal::Animal(const t &c)
{
	type = c.type;
	_ANIMAL_AUTO(32, "Copy Constructor");
}

Animal::Animal() : type("Generic")
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
void Animal::set_type(std::string input) { type = input; }

// --------------------------------- Methods ------------------------------- //

void Animal::makeSound()
{
	std::cout << "Generic animal\n";
}
