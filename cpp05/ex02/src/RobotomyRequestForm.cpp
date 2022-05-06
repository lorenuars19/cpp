#include "RobotomyRequestForm.hpp"

// ----------------------------- Constructors ------------------------------ //
RobotomyRequestForm::RobotomyRequestForm()
{
	_ROBOTOMYCREATIONFORM_AUTO(32, "Default Constructor");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &c)
{
	_ROBOTOMYCREATIONFORM_AUTO(32, "Copy Constructor");
	target = c.get_target();
}

RobotomyRequestForm::RobotomyRequestForm(std::string in_target)
	: Form(), target(in_target)
{
	_ROBOTOMYCREATIONFORM_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
RobotomyRequestForm::~RobotomyRequestForm()
{
	_ROBOTOMYCREATIONFORM_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &c)
{
	target = c.get_target();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
std::string RobotomyRequestForm::get_target() const { return target; }
void RobotomyRequestForm::set_target(std::string input) { target = input; }

// --------------------------------- Methods ------------------------------- //

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->get_form_signed() == false)
	{
		throw FormNotSignedExeption();
	}
	if (this->get_exec_grade() <= executor.get_grade())
	{
		throw GradeTooLowException();
	}

	std::cout << " * drilling noises * " << '\n';

	if (rand() % 2 == 1)
	{
		std::cout << target << " has been succesfully robotomized " << std::endl;
	}
	else
	{
		std::cout << " robotomy has failed for " << target << std::endl;
	}
}
