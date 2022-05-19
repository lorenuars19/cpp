#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
public:
	typedef FragTrap t;
	// ----------------------------- Constructors ------------------------------ //
	FragTrap();					// Default Constructor
	FragTrap(std::string name); // Fields Constructor
	FragTrap(const t &c);		// Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~FragTrap(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	FragTrap &operator=(const t &a);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	// --------------------------------- Methods ------------------------------- //
	void displayStatus();

	void highFiveGuys();

private:
};

#ifndef NO_DEBUG

#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif /* _ARG */

#define _FRAGTRAP_ARGS \
	_ARG(get_name())   \
	_ARG(get_hp())     \
	_ARG(get_ep())     \
	_ARG(get_ap())

#define _FRAGTRAP_AUTO(COLOR_CODE, TEXT)                  \
	std::cout                                             \
		<< "{ \e[" << COLOR_CODE << ";1m"                 \
		<< TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
		<< "[\033[34;47m" << this                         \
		<< "\033[0m]\033[0m: " << _FRAGTRAP_ARGS          \
		<< "}" << std::endl;
#else

#define _FRAGTRAP_AUTO(x, y) ;
#define _FRAGTRAP_ARGS ""
#define _ARG ""

#endif /* NO_DEBUG */

#endif /* FRAGTRAP_HPP */
