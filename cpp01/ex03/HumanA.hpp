#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>

class HumanA
{
public:
	// ----------------------------- Constructors ------------------------------ //
	HumanA(void);						// Default Constructor
	HumanA(std::string name, Weapon w); // Fields Constructor
	HumanA(const HumanA &copy);			// Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~HumanA(void); // Destructor

	// ------------------------------- Operators ------------------------------- //
	HumanA &operator=(const HumanA &assign);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	int get_var(void) const;
	void set_var(int input);

	// --------------------------------- Methods ------------------------------- //
	void attack(void);

private:
	int _var;
};

#ifndef NO_DEBUG
#define _ARGS "Args : var " << _var
#define _AUTO(COLOR_CODE, TEXT) std::cout << "\e[" << COLOR_CODE << ";1m"                        \
										  << "< " << TEXT << " " << __PRETTY_FUNCTION__ << " > " \
										  << "\e[0m" << _ARGS
#else
#define _AUTO(x, y) ;
#endif

#endif
