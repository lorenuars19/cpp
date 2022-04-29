#include "Dog.hpp"

// ----------------------------- Constructors ------------------------------ //
Dog::Dog()
{
	set_type("Dog");
	_DOG_AUTO(32, "Default Constructor");
}

Dog::Dog(const t &c)
{
	(void)c;
	_DOG_AUTO(32, "Copy Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Dog::~Dog()
{
	_DOG_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Dog &Dog::operator=(const t &a)
{
	(void)a;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

// --------------------------------- Methods ------------------------------- //

void Dog::makeSound()
{
	std::cout << "Bark\n";
}
