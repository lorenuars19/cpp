#include "Cat.hpp"

// ----------------------------- Constructors ------------------------------ //
Cat::Cat()
{
	set_type("Cat");
	brain = new Brain();
	_CAT_AUTO(32, "Default Constructor");
}

Cat::Cat(const t &c)
{
	(*this) = c;
	_CAT_AUTO(32, "Copy Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Cat::~Cat()
{
	// delete brain;
	_CAT_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Cat &Cat::operator=(const t &a)
{
	_CAT_AUTO(34, "Copy Assignement Operator called");
	if (this != &a)
	{
		type = a.type;
		brain = new Brain(*(a.brain));
	}
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

void Cat::set_brain(Brain &input) { brain = new Brain(input); }
Brain &Cat::get_brain() const { return *brain; }

// --------------------------------- Methods ------------------------------- //

void Cat::makeSound()const
{
	std::cout << "Meow\n";
}
