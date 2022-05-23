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
	*this = c;
	_BRAIN_AUTO(32, "Copy Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Brain::~Brain()
{
	_BRAIN_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Brain &Brain::operator=(const t &a)
{
	_BRAIN_AUTO(34, "Copy Assignement Operator called")
	for (int i = 0; i < ARR_SIZ; i++)
	{
		ideas[i] = a.ideas[i];
	}
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

// --------------------------------- Methods ------------------------------- //
