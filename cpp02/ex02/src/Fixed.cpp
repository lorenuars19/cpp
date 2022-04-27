#include "Fixed.hpp"

// ----------------------------- Constructors ------------------------------ //
Fixed::Fixed()
{
	_value = 0;
	_FIXED_AUTO(32, "Default Constructor");
}

Fixed::Fixed(const t &c)
{
	_value = c.getRawBits();
	_FIXED_AUTO(32, "Copy Constructor");
}

Fixed::Fixed(int const value) : _value(value)
{
	_FIXED_AUTO(32, "Fields Constructor (int)");

	_value = 0; // reset _value

	_value = value << _frac;
}

Fixed::Fixed(float const fl)
	: _value(((int)fl << _frac) + std::roundf((fl - (int)fl) * 256))
{
	_FIXED_AUTO(32, "Fields Constructor (float)");
}

// ------------------------------ Destructor ------------------------------- //
Fixed::~Fixed()
{
	_FIXED_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Fixed &Fixed::operator=(const t &a)
{
	_value = a.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Fixed &input)
{
	return o << input.toFloat();
}

bool Fixed::operator>(const Fixed &rhs) { return getRawBits() > rhs.getRawBits(); }
bool Fixed::operator<(const Fixed &rhs) { return getRawBits() < rhs.getRawBits(); }
bool Fixed::operator>=(const Fixed &rhs) { return getRawBits() >= rhs.getRawBits(); }
bool Fixed::operator<=(const Fixed &rhs) { return getRawBits() <= rhs.getRawBits(); }
bool Fixed::operator==(const Fixed &rhs) { return getRawBits() == rhs.getRawBits(); }
bool Fixed::operator!=(const Fixed &rhs) { return getRawBits() != rhs.getRawBits(); }

Fixed Fixed::operator+(const Fixed &rhs) { return getRawBits() + rhs.getRawBits(); }
Fixed Fixed::operator-(const Fixed &rhs) { return getRawBits() - rhs.getRawBits(); }
Fixed Fixed::operator*(const Fixed &rhs) { return getRawBits() * rhs.getRawBits(); }
Fixed Fixed::operator/(const Fixed &rhs) { return getRawBits() / rhs.getRawBits(); }

Fi

	// --------------------------- Getters && Setters -------------------------- //

	// --------------------------------- Methods ------------------------------- //

	int
	Fixed::getRawBits() const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat() const
{
	return ((_value >> _frac) + ((_value & 0xff) / 256.0f));
}

int Fixed::toInt() const
{
	return (_value >> _frac);
}
