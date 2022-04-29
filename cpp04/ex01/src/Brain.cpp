#include "Brain.hpp"

// ----------------------------- Constructors ------------------------------ //
Brain::Brain()
{
	_BRAIN_AUTO(32, "Default Constructor");
	for (int i = 0; i < ARR_SIZ; i++)
	{
		ideas[i] = "";
	}
}

Brain::Brain(const t &c)
{
	_BRAIN_AUTO(32, "Copy Constructor");
}

Brain::Brain(int input) : var(input)
{
	_BRAIN_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Brain::~Brain()
{
	_BRAIN_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Brain &Brain::operator=(const t &a)
{
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

// --------------------------------- Methods ------------------------------- //
