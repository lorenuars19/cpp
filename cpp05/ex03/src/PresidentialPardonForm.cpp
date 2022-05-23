#include "PresidentialPardonForm.hpp"

// ----------------------------- Constructors ------------------------------ //
PresidentialPardonForm::PresidentialPardonForm()
{
	_PRESIDENTIALPARDONFORM_AUTO(32, "Default Constructor");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &c)
	: Form(c.get_name(), c.get_sign_grade(), c.get_exec_grade()), target(c.get_target())
{
	*this = c;
	_PRESIDENTIALPARDONFORM_AUTO(32, "Copy Constructor");
}

PresidentialPardonForm::PresidentialPardonForm(std::string in_target)
	: Form("PresidentialPardonForm", 25, 5), target(in_target)
{
	_PRESIDENTIALPARDONFORM_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
PresidentialPardonForm::~PresidentialPardonForm()
{
	_PRESIDENTIALPARDONFORM_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &c)
{
	target = c.target;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
std::string PresidentialPardonForm::get_target() const { return target; }
void PresidentialPardonForm::set_target(std::string input) { target = input; }

// --------------------------------- Methods ------------------------------- //

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{

	if (this->get_form_signed() == false)
	{
		throw FormNotSignedExeption();
	}

	if (this->get_exec_grade() < executor.get_grade())
	{
		throw GradeTooLowException();
	}
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << '\n';
}
