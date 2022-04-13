#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanA
{
public:
	// ----------------------------- Constructors ------------------------------ //
	HumanA(void);							  // Default Constructor
	HumanA(std::string name, Weapon &weapon); // Fields Constructor
	HumanA(const HumanA &copy);				  // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~HumanA(void); // Destructor

	// ------------------------------- Operators ------------------------------- //
	HumanA &operator=(const HumanA &assign);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	std::string get_name(void) const;
	void set_name(int input);

	Weapon &get_weapon(void) const;
	void set_weapon(Weapon &input);
	// --------------------------------- Methods ------------------------------- //
	void attack(void);

private:
	std::string _name;
	Weapon &_weapon;
};

#ifndef NO_DEBUG
#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif
#undef _ARGS
#define _ARGS "Args : " << _ARG(_name) << _ARG(&_weapon)
#undef _AUTO
#define _AUTO(COLOR_CODE, TEXT) std::cout << " \e[" << COLOR_CODE << ";1m"                       \
										  << "< " << TEXT << " " << __PRETTY_FUNCTION__ << " > " \
										  << "\e[0m" << _ARGS
#else
#define _AUTO(x, y) std::cout
#endif

#endif
