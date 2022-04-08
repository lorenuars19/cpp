#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
public:
	// ----------------------------- Constructors ------------------------------ //
	Weapon(void);				// Default Constructor
	Weapon(std::string type);	// Fields Constructor
	Weapon(const Weapon &copy); // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~Weapon(void); // Destructor

	// ------------------------------- Operators ------------------------------- //
	Weapon &operator=(const Weapon &assign);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	std::string getType(void) const;
	void setType(int input);

	// --------------------------------- Methods ------------------------------- //


private:
	std::string _type;
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
