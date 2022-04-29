#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define ARR_SIZ 100

class Brain
{
public:
	typedef Brain t;
	// ----------------------------- Constructors ------------------------------ //
	Brain(); // Default Constructor

	Brain(const t &c); // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~Brain(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	Brain &operator=(const t &a);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //

	// --------------------------------- Methods ------------------------------- //
	int is_equal(const Brain comp);

private:
	std::string ideas[ARR_SIZ];
};

#ifndef NO_DEBUG

#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif /* _ARG */

#define _BRAIN_ARGS ""
#define _BRAIN_AUTO(COLOR_CODE, TEXT)                           \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _BRAIN_ARGS             \
			  << "}" << std::endl;
#else

#define _BRAIN_AUTO(x, y) ;
#define _BRAIN_ARGS ""
#define _ARG ""

#endif /* NO_DEBUG */

#endif /* BRAIN_HPP */
