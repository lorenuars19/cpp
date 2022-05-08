#include "Intern.hpp"

// ----------------------------- Constructors ------------------------------ //
Intern::Intern()
{
	_INTERN_AUTO(32, "Default Constructor");
}

Intern::Intern(const Intern &c)
{
	(void)c;
	_INTERN_AUTO(32, "Copy Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Intern::~Intern()
{
	_INTERN_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Intern &Intern::operator=(const Intern &c)
{
	(void)c;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

// --------------------------------- Methods ------------------------------- //

Form *Intern::makeShrubberyCreationForm(std::string form_target) { return new ShrubberyCreationForm(form_target); }
Form *Intern::makeRobotomyRequestForm(std::string form_target) { return new RobotomyRequestForm(form_target); }
Form *Intern::makePresidentialPardonForm(std::string form_target) { return new PresidentialPardonForm(form_target); }

Form *Intern::makeForm(std::string form_name, std::string form_target)
{
	Form *form;

	static t_factory form_factories[CLASS_MAX] = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm};

	const static std::string strs[CLASS_MAX] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"};

	// Check String Array
	// lowercase it so the case does not matter
	form = NULL;
	for (int i = 0; i < CLASS_MAX; i++)
	{
		if (form_name == strs[i])
		{
			form = (this->*(form_factories[i]))(form_target);
		}
	}

	if (form == NULL)
	{
		std::cout << "Intern could not find this form name, make sure it exists in the database" << std::endl;
		return NULL;
	}
	std::cout << "Intern creates " << *form << std::endl;

	return form;
}
