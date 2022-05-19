#include "Fixed.hpp"

// ----------------------------- Constructors ------------------------------ //
Fixed::Fixed()
{
	_value = 0;
	_FIXED_AUTO(32, "Default Constructor");
}

Fixed::Fixed(const t &c)
{
	*this = c;
	_FIXED_AUTO(32, "Copy Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Fixed::~Fixed()
{
	_FIXED_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Fixed &Fixed::operator=(const t &a)
{
	_FIXED_AUTO(33, "Copy assignment called");
	_value = a._value;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
int Fixed::get_value() const
{
	_FIXED_AUTO(33, "Getter");
	return _value;
}

void Fixed::set_value(int input)
{
	_FIXED_AUTO(34, "Setter");
#ifndef NO_DEBUG
	std::cout << "\033[1D";
#endif
	std::cout << " old(" << _value << ") new(" << input << ") " << std::endl;
	_value = input;
}

// --------------------------------- Methods ------------------------------- //

int Fixed::getRawBits() const
{
	_FIXED_AUTO(34, "getRawBits")
	return (_value);
}

void Fixed::seRawBits(int const raw)
{
	// _FIXED_AUTO(35, "setRawBits")const
	_value = raw;
}
