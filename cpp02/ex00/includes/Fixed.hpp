#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
public:
	typedef Fixed t;
	// ----------------------------- Constructors ------------------------------ //
	Fixed(); // Default Constructor

	Fixed(const t &c); // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~Fixed(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	Fixed &operator=(const t &a);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	int get_value() const;
	void set_value(int input);

	// --------------------------------- Methods ------------------------------- //
	int getRawBits() const;
	void seRawBits(int const raw);

private:
	int _value;
	static const int _frac = 8;
};

#ifndef NO_DEBUG

#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif /* _ARG */

#define _FIXED_ARGS _ARG(_value)
#define _FIXED_AUTO(COLOR_CODE, TEXT)                                \
	std::cout << "\e[" << COLOR_CODE << ";1m"                        \
			  << "< " << TEXT << " " << __PRETTY_FUNCTION__ << " > " \
			  << "\e[0m"                                             \
			  << "[\033[34;47m" << this                              \
			  << "\033[0m] [\033[33;40mARGS\033[0m] " << _FIXED_ARGS \
			  << std::endl;
#else

#define _FIXED_AUTO(x, y) ;
#define _FIXED_ARGS ""
#define _ARG ""

#endif /* NO_DEBUG */

#endif /* FIXED_HPP */
