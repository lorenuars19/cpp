#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>

class HumanB
{
public:
	// ----------------------------- Constructors ------------------------------ //
	HumanB(void);				// Default Constructor
	HumanB(int var);			// Fields Constructor
	HumanB(const HumanB &copy); // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~HumanB(void); // Destructor

	// ------------------------------- Operators ------------------------------- //
	HumanB &operator=(const HumanB &assign);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	int get_var(void) const;
	void set_var(int input);

	// --------------------------------- Methods ------------------------------- //
	int is_equal(const HumanB comp);

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
