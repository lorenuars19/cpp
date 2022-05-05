#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
public:
	// ----------------------------- Constructors ------------------------------ //
	Weapon();					// Default Constructor
	Weapon(std::string type);	// Fields Constructor
	Weapon(const Weapon &copy); // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~Weapon(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	Weapon &operator=(const Weapon &assign);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	const std::string getType() const;
	void setType(std::string input);

	// --------------------------------- Methods ------------------------------- //

private:
	std::string _type;
};

#ifndef NO_DEBUG
#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif
#undef _ARGS
#define _ARGS "Args : " << _ARG(_type)
#undef _AUTO
#define _AUTO(COLOR_CODE, TEXT) std::cout << " \e[" << COLOR_CODE << ";1m"                       \
										  << "< " << TEXT << " " << __PRETTY_FUNCTION__ << " > " \
										  << "\e[0m" << _ARGS
#else
#define _AUTO(x, y) std::cout
#endif

#endif
