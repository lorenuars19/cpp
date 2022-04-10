#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanB
{
public:
	// ----------------------------- Constructors ------------------------------ //
	HumanB(void);				// Default Constructor
	HumanB(std::string name);	// Fields Constructor
	HumanB(const HumanB &copy); // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~HumanB(void); // Destructor

	// ------------------------------- Operators ------------------------------- //
	HumanB &operator=(const HumanB &assign);
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
	Weapon *_weapon;
};

#ifndef NO_DEBUG
#undef _ARGS
#define _ARGS "Args : name " << _name << " weapon " << &_weapon << " "
#undef _AUTO
#define _AUTO(COLOR_CODE, TEXT) std::cout << " \e[" << COLOR_CODE << ";1m"                       \
										  << "< " << TEXT << " " << __PRETTY_FUNCTION__ << " > " \
										  << "\e[0m" << _ARGS
#else
#define _AUTO(x, y) std::cout
#endif

#endif
