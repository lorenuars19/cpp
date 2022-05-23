#include "WrongAnimal.hpp"

// ----------------------------- Constructors ------------------------------ //
WrongAnimal::WrongAnimal()
{
	_WRONGANIMAL_AUTO(32, "Default Constructor");
}

WrongAnimal::WrongAnimal(const WrongAnimal &c)
{
	_WRONGANIMAL_AUTO(32, "Copy Constructor");
	*this = c;
}

// ------------------------------ Destructor ------------------------------- //
WrongAnimal::~WrongAnimal()
{
	_WRONGANIMAL_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &c)
{
	_WRONGANIMAL_AUTO(32, "Copy Assignement Operator");
	(void)c;

	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

// --------------------------------- Methods ------------------------------- //

void WrongAnimal::makeSound() const
{
	std::cout << "Generic Wrong animal\n";
}
