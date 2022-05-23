#include "WrongCat.hpp"

// ----------------------------- Constructors ------------------------------ //
WrongCat::WrongCat()
{
	_WRONGCAT_AUTO(32, "Default Constructor");
}

WrongCat::WrongCat(const WrongCat &c)
{
	_WRONGCAT_AUTO(32, "Copy Constructor");
	*this = c;
}

// ------------------------------ Destructor ------------------------------- //
WrongCat::~WrongCat()
{
	_WRONGCAT_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

WrongCat &WrongCat::operator=(const WrongCat &c)
{
	_WRONGCAT_AUTO(32, "Copy Assignement Operator");
	(void)c;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

// --------------------------------- Methods ------------------------------- //

void WrongCat::makeSound() const
{
	WrongAnimal::makeSound();
}
