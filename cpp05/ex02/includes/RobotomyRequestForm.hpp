#ifndef ROBOTOMYCREATIONFORM_HPP
#define ROBOTOMYCREATIONFORM_HPP

#include "Form.hpp"
#include <iostream>

class RobotomyRequestForm : public Form
{
public:
	// ----------------------------- Constructors ------------------------------ //
	RobotomyRequestForm();							   // Default Constructor
	RobotomyRequestForm(std::string in_target);		   // Fields Constructor
	RobotomyRequestForm(const RobotomyRequestForm &c); // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~RobotomyRequestForm(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	RobotomyRequestForm &operator=(const RobotomyRequestForm &a);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	std::string get_target() const;
	void set_target(std::string input);

	// --------------------------------- Methods ------------------------------- //

	void execute(Bureaucrat const &executor) const;

private:
	std::string target;
};

#ifndef NO_DEBUG

#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif /* _ARG */

#define _ROBOTOMYCREATIONFORM_ARGS _ARG(target)
#define _ROBOTOMYCREATIONFORM_AUTO(COLOR_CODE, TEXT)               \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                    \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m "    \
			  << "[\033[34;47m" << this                            \
			  << "\033[0m]\033[0m: " << _ROBOTOMYCREATIONFORM_ARGS \
			  << "}" << std::endl;
#else

#define _ROBOTOMYCREATIONFORM_AUTO(x, y) ;
#define _ROBOTOMYCREATIONFORM_ARGS ""
#define _ARG ""

#endif /* NO_DEBUG */

#endif /* ROBOTOMYCREATIONFORM_HPP */
