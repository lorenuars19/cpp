#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

#define CLASS_MAX 3

class Intern
{
public:
	// ----------------------------- Constructors ------------------------------ //
	Intern();				 // Default Constructor
	Intern(const Intern &c); // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~Intern(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	Intern &operator=(const Intern &a);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //

	// --------------------------------- Methods ------------------------------- //

	Form *makeForm(std::string form_name, std::string form_target);

private:
	Form *makeShrubberyCreationForm(std::string form_target);
	Form *makeRobotomyRequestForm(std::string form_target);
	Form *makePresidentialPardonForm(std::string form_target);
};

#ifndef NO_DEBUG

#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif /* _ARG */

#define _INTERN_ARGS ""
#define _INTERN_AUTO(COLOR_CODE, TEXT)                          \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _INTERN_ARGS            \
			  << "}" << std::endl;
#else

#define _INTERN_AUTO(x, y) ;
#define _INTERN_ARGS ""
#define _ARG ""

#endif /* NO_DEBUG */

#endif /* INTERN_HPP */
