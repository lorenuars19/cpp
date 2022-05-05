#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
public:
	

// ----------------------------- Constructors ------------------------------ //
	Bureaucrat();	// Default Constructor
	Bureaucrat(const std::string in_name, int in_grade);	// Fields Constructor
	Bureaucrat(const Bureaucrat& c);	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
	~Bureaucrat();	// Destructor

// ------------------------------- Operators ------------------------------- //
	Bureaucrat & operator=(const Bureaucrat& a);
	// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //
	const std::string get_name() const;
	void set_name(const std::string input);
	
	int get_grade() const;
	void set_grade(int input);
	

// --------------------------------- Methods ------------------------------- //

private:
	const std::string name;
	int grade;

};

# ifndef NO_DEBUG

#  ifndef _ARG
#   define _ARG(arg) #arg << "(" << arg << ") "
#  endif /* _ARG */

#  define _BUREAUCRAT_ARGS _ARG(name) << _ARG(grade)
#  define _BUREAUCRAT_AUTO(COLOR_CODE, TEXT) \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _BUREAUCRAT_ARGS  \
			  << "}" << std::endl;
# else

#  define _BUREAUCRAT_AUTO(x, y) ;
#  define _BUREAUCRAT_ARGS ""
#  define _ARG ""

# endif /* NO_DEBUG */

#endif /* BUREAUCRAT_HPP */
