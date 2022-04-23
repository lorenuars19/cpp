#include "Fixed.hpp"

// ----------------------------- Constructors ------------------------------ //
Fixed::Fixed(void)
{
	_value = 0;
	_FIXED_AUTO(32, "Default Constructor");
}

Fixed::Fixed(const t &c)
{
	_value = c.get_value();
	_FIXED_AUTO(32, "Copy Constructor");
}

Fixed::Fixed(int const value) : _value(value)
{
	_FIXED_AUTO(32, "Fields Constructor (int)");

	// 64 bits -> 8 Frac

	_value |= value >> 8;
}

Fixed::Fixed(float const value) : _value(value)
{
	_FIXED_AUTO(32, "Fields Constructor (float)");
}

// ------------------------------ Destructor ------------------------------- //
Fixed::~Fixed(void)
{
	_FIXED_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Fixed &Fixed::operator=(const t &a)
{
	_value = a.get_value();
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Fixed &input)
{
	return o << input.getRawBits();
}

// --------------------------- Getters && Setters -------------------------- //
int Fixed::get_value(void) const
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

int Fixed::getRawBits(void) const
{
	_FIXED_AUTO(34, "getRawBits")
	return (_value);
}

void Fixed::seRawBits(int const raw)
{
	_FIXED_AUTO(35, "setRawBits")
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return (-42.42f);
}

int Fixed::toInt(void) const
{
	return (_value << 8);
}

std::ostream &bin(std::ostream &o, const int input)
{
	return o << "bits : " << std::bitset<64>(input) << std::endl;
}
