#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
public:
	typedef ScavTrap t;
	// ----------------------------- Constructors ------------------------------ //
	ScavTrap();					// Default Constructor
	ScavTrap(std::string name); // Fields Constructor
	ScavTrap(const t &c);		// Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~ScavTrap(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	ScavTrap &operator=(const t &a);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	bool get_gate_mode() const;
	// --------------------------------- Methods ------------------------------- //

	void guardGate();

private:
	bool gate_mode;

	void displayStatus();
};

#ifndef NO_DEBUG

#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif /* _ARG */

#define _SCAVTRAP_ARGS \
	_ARG(get_name())   \
	_ARG(get_hp())     \
	_ARG(get_ep())     \
	_ARG(get_ap())     \
	_ARG(gate_mode)

#define _SCAVTRAP_AUTO(COLOR_CODE, TEXT)                  \
	std::cout                                             \
		<< "{ \e[" << COLOR_CODE << ";1m"                 \
		<< TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
		<< "[\033[34;47m" << this                         \
		<< "\033[0m]\033[0m: " << _SCAVTRAP_ARGS          \
		<< "}" << std::endl;
#else

#define _SCAVTRAP_AUTO(x, y) ;
#define _SCAVTRAP_ARGS ""
#define _ARG ""

#endif /* NO_DEBUG */

#endif /* SCAVTRAP_HPP */
