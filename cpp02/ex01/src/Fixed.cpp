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

	_value = 0; // reset _value
	// 64 bits -> 8 Frac
	std::cout << "value : " << value << " : " << std::bitset<64>(value) << "\n";

	_value = value * 64;

	std::cout << "_value : " << (_value / 64) << " : " << std::bitset<64>(_value) << "\n";

	std::cout << "_value : & () " << std::bitset<64>(_value & 0b11111111) << "\n";
}

Fixed::Fixed(float const value) : _value(value)
{
	_FIXED_AUTO(32, "Fields Constructor (float)");

	_value = 0;

	_value = ((int)roundf(value)) * 64;

	std::cout << "_value : " << std::bitset<64>(_value) << "\n";
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
	int inum;
	float frac;

	inum = input.getRawBits() & ~0b11111111;
	frac = input.getRawBits() & 0b11111111;

	std::cout << "inum 0b" << std::bitset<64>(inum) << std::endl;
	std::cout << "frac 0b" << std::bitset<64>(frac) << std::endl;

	return o << inum << "." << frac;
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
	return (this->getRawBits() >> 8);
}
