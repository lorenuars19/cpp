#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
	typedef ClapTrap t;
	// ----------------------------- Constructors ------------------------------ //
	ClapTrap();			  // Default Constructor
	ClapTrap(int var);	  // Fields Constructor
	ClapTrap(const t &c); // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~ClapTrap(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	ClapTrap &operator=(const t &a);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	int get_var() const;
	void set_var(int input);

	// --------------------------------- Methods ------------------------------- //
	int is_equal(const ClapTrap comp);

private:
	int _var;
};

#ifndef NO_DEBUG

#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif /* _ARG */

#define _CLAPTRAP_ARGS _ARG(_var)
#define _CLAPTRAP_AUTO(COLOR_CODE, TEXT)                        \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _CLAPTRAP_ARGS          \
			  << "}" << std::endl;
#else

#define _CLAPTRAP_AUTO(x, y) ;
#define _CLAPTRAP_ARGS ""
#define _ARG ""

#endif /* NO_DEBUG */

#endif /* CLAPTRAP_HPP */
