#include "Cat.hpp"

// ----------------------------- Constructors ------------------------------ //
Cat::Cat()
{
	set_type("Cat");
	_CAT_AUTO(32, "Default Constructor");
}

Cat::Cat(const t &c) : Animal()
{
	(void)c;
	_CAT_AUTO(32, "Copy Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Cat::~Cat()
{
	_CAT_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Cat &Cat::operator=(const t &a)
{
	(void)a;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

// --------------------------------- Methods ------------------------------- //

void Cat::makeSound() const
{
	std::cout << "Meow\n";
}
