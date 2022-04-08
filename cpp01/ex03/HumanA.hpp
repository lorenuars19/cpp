#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>

class HumanA
{
public:
	// ----------------------------- Constructors ------------------------------ //
	HumanA(void);				// Default Constructor
	HumanA(int type);			// Fields Constructor
	HumanA(const HumanA &copy); // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~HumanA(void); // Destructor

	// ------------------------------- Operators ------------------------------- //
	HumanA &operator=(const HumanA &assign);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	int get_type(void) const;
	void set_type(int input);

	// --------------------------------- Methods ------------------------------- //
	int is_equal(const HumanA comp);

private:
	int _type;
};

#ifndef NO_DEBUG
#define _ARGS "Args : type " << _type
#define _AUTO(COLOR_CODE, TEXT) std::cout << "\e[" << COLOR_CODE << ";1m"                        \
										  << "< " << TEXT << " " << __PRETTY_FUNCTION__ << " > " \
										  << "\e[0m" << _ARGS
#else
#define _AUTO(x, y) ;
#endif

#endif
