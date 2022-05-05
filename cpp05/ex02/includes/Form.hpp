#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
public:
	struct GradeTooHighException : public std::exception
	{
		const char *what() const throw()
		{
			return "\e[31;1mError : grade too high\e[0m";
		}
	};
	struct GradeTooLowException : public std::exception
	{
		const char *what() const throw()
		{
			return "\e[31;1mError : grade too low\e[0m";
		}
	};
	// ----------------------------- Constructors ------------------------------ //
	Form();																   // Default Constructor
	Form(const std::string in_name, int in_sign_grade, int in_exec_grade); // Fields Constructor
	Form(const Form &c);												   // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~Form(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	Form &operator=(const Form &a);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	const std::string get_name() const;
	void set_name(const std::string input);

	bool get_form_signed() const;
	void set_form_signed(bool input);

	int get_sign_grade() const;
	void set_sign_grade(const int input);

	int get_exec_grade() const;
	void set_exec_grade(const int input);

	// --------------------------------- Methods ------------------------------- //
	void check_grade(int grade);
	void beSigned(Bureaucrat &inp);

private:
	const std::string name;
	bool form_signed;
	const int sign_grade;
	const int exec_grade;
};

std::ostream &operator<<(std::ostream &o, const Form &input);

#ifndef NO_DEBUG

#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif /* _ARG */

#define _FORM_ARGS _ARG(name) << _ARG(form_signed) << _ARG(sign_grade) << _ARG(exec_grade)
#define _FORM_AUTO(COLOR_CODE, TEXT)                            \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _FORM_ARGS              \
			  << "}" << std::endl;
#else

#define _FORM_AUTO(x, y) ;
#define _FORM_ARGS ""
#define _ARG ""

#endif /* NO_DEBUG */

#endif /* FORM_HPP */
