#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:
	// ----------------------------- Constructors ------------------------------ //
	Zombie(void);					// Default Constructor
	Zombie(const std::string name); // Fields Constructor
	Zombie(const Zombie &copy);		// Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~Zombie(void); // Destructor

	// ------------------------------- Operators ------------------------------- //
	Zombie &operator=(const Zombie &assign);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	std::string get_name() const;
	void set_name(std::string name);
	// --------------------------------- Methods ------------------------------- //
	void anounce(void);

private:
	std::string _name;
};

Zombie *zombieHorde(int n, std::string name);

#ifndef NO_DEBUG
#define _ARGS "Args > name : " << _name
#define _AUTO(COLOR_CODE, TEXT) std::cout << "\e[" << COLOR_CODE << ";1m"                        \
										  << "< " << TEXT << " " << __PRETTY_FUNCTION__ << " > " \
										  << "\e[0m" << _ARGS
#else
#define _AUTO(x, y) ;
#endif

#endif
