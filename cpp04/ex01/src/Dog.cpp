#include "Dog.hpp"

// ----------------------------- Constructors ------------------------------ //
Dog::Dog()
{
	set_type("Dog");
	brain = new Brain();
	_DOG_AUTO(32, "Default Constructor");
}

Dog::Dog(const t &c)
{
	(*this) = c;
	_DOG_AUTO(32, "Copy Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Dog::~Dog()
{
	// delete brain;
	_DOG_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Dog &Dog::operator=(const t &a)
{
	_DOG_AUTO(34, "Copy Assignement Operator called");
	if (this != &a)
	{
		type = a.type;
		brain = new Brain(*(a.brain));
	}
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
void Dog::set_brain(Brain &input) { brain = new Brain(input); }
Brain &Dog::get_brain() const { return *brain; }
// --------------------------------- Methods ------------------------------- //

void Dog::makeSound()
{
	std::cout << "Bark\n";
}
