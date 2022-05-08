#include "Bureaucrat.hpp"

// ----------------------------- Constructors ------------------------------ //
Bureaucrat::Bureaucrat() : name(""), grade(0)
{
	_BUREAUCRAT_AUTO(32, "Default Constructor");
}

Bureaucrat::Bureaucrat(const Bureaucrat &c)
{
	_BUREAUCRAT_AUTO(32, "Copy Constructor");
	// name = c.get_name();
	grade = c.get_grade();
}

Bureaucrat::Bureaucrat(const std::string in_name, int in_grade) : name(in_name), grade(0)
{
	_BUREAUCRAT_AUTO(32, "Fields Constructor");
	set_grade(in_grade);
}

// ------------------------------ Destructor ------------------------------- //
Bureaucrat::~Bureaucrat()
{
	_BUREAUCRAT_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &c)
{
	// name = c.get_name();
	grade = c.get_grade();
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &inp)
{
	return o << inp.get_name() << ", bureaucrat grade " << inp.get_grade();
}

// --------------------------- Getters && Setters -------------------------- //
const std::string Bureaucrat::get_name() const
{
	return name;
}
// void Bureaucrat::set_name(const std::string input) { name = input; }

int Bureaucrat::get_grade() const { return grade; }

void Bureaucrat::set_grade(int input)
{
	if (input < MIN_GRADE)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (input > MAX_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	grade = input;
}

void Bureaucrat::increment_grade() { set_grade(grade - 1); }
void Bureaucrat::decrement_grade() { set_grade(grade + 1); }

// --------------------------------- Methods ------------------------------- //

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->get_name() << " signed " << form.get_name() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->get_name() << " couldn't sign "
				  << form.get_name() << " because " << e.what()
				  << std::endl;
	}
}

void Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->get_name() << " executed " << form.get_name() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->get_name() << " couldn't execute "
				  << form.get_name() << " because " << e.what()
				  << std::endl;
	}
}
