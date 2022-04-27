#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iomanip>
#include <iostream>

class Fixed
{
public:
	typedef Fixed t;
	// ----------------------------- Constructors ------------------------------ //
	Fixed();				  // Default Constructor
	Fixed(int const value);	  // Fields Constructor integer
	Fixed(float const value); // Fields Constructor floating point
	Fixed(const t &c);		  // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~Fixed(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	Fixed &operator=(const t &a);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	int get_value() const;
	void set_value(int input);
	int get_frac() const;

	// --------------------------------- Methods ------------------------------- //
	int getRawBits() const;
	void seRawBits(int const raw);
	float toFloat() const;
	int toInt() const;

private:
	int _value;
	static const int _frac = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &input);
std::ostream &bin(std::ostream &o, const int input);

#ifndef NO_DEBUG

#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif /* _ARG */

#define _FIXED_ARGS \
	_ARG(_value)    \
	_ARG(_frac)
#define _FIXED_AUTO(COLOR_CODE, TEXT)                           \
	std::cout << "< \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _FIXED_ARGS             \
			  << ">" << std::endl;
#else

#define _FIXED_AUTO(x, y) ;
#define _FIXED_ARGS ""
#define _ARG ""

#endif /* NO_DEBUG */

#endif /* FIXED_HPP */
