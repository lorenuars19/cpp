#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
	typedef ClapTrap t;
	// ----------------------------- Constructors ------------------------------ //
	ClapTrap();					// Default Constructor
	ClapTrap(std::string name); // Fields Constructor
	ClapTrap(const t &c);		// Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~ClapTrap(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	ClapTrap &operator=(const t &a);
	// Copy Assignement Operator
	// --------------------------- Getters && Setters -------------------------- //
	std::string get_name() const;
	void set_name(std::string name);
	int get_hp() const;
	void set_hp(unsigned int input);
	int get_ep() const;
	void set_ep(unsigned int input);
	int get_ap() const;
	void set_ap(unsigned int input);
	// --------------------------------- Methods ------------------------------- //
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void displayStatus();
	int deadCheck();

private:
	std::string name;
	unsigned int hp;
	unsigned int ep;
	unsigned int ap;
};

#ifndef NO_DEBUG

#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif /* _ARG */

#define _CLAPTRAP_ARGS \
	_ARG(name)         \
	_ARG(hp)           \
	_ARG(ep)           \
	_ARG(ap)

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
