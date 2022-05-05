#include "Bureaucrat.hpp"

// ----------------------------- Constructors ------------------------------ //
Bureaucrat::Bureaucrat()
{
	_BUREAUCRAT_AUTO(32, "Default Constructor");
}

Bureaucrat::Bureaucrat(const Bureaucrat& c)
{
	_BUREAUCRAT_AUTO(32, "Copy Constructor");
	name = c.get_name();
	grade = c.get_grade();
}

Bureaucrat::Bureaucrat(const std::string in_name, int in_grade) : name(in_name), grade(in_grade)
{
	_BUREAUCRAT_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Bureaucrat::~Bureaucrat()
{
	_BUREAUCRAT_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Bureaucrat & Bureaucrat::operator=(const Bureaucrat& c)
{
	name = c.get_name();
	grade = c.get_grade();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
const std::string Bureaucrat::get_name() const{ return name; }
void Bureaucrat::set_name(const std::string input){ name = input; }

int Bureaucrat::get_grade() const{ return grade; }
void Bureaucrat::set_grade(int input){ grade = input; }



// --------------------------------- Methods ------------------------------- //

