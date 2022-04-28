#include "ClapTrap.hpp"

// ----------------------------- Constructors ------------------------------ //
ClapTrap::ClapTrap( )
{
	_var = 0;
	_CLAPTRAP_AUTO(32, "Default Constructor");
}

ClapTrap::ClapTrap( const t& c )
{
	_var = c.get_var();
	_CLAPTRAP_AUTO(32, "Copy Constructor");
}

ClapTrap::ClapTrap( int var ) : _var(var)
{
	_CLAPTRAP_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
ClapTrap::~ClapTrap( )
{
	_CLAPTRAP_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

ClapTrap & ClapTrap::operator=( const t& a )
{
	_var = a.get_var();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
int	ClapTrap::get_var( ) const
{
	_CLAPTRAP_AUTO(33, "Getter");
	return _var;
}

void	ClapTrap::set_var( int input )
{
	_CLAPTRAP_AUTO(34, "Setter");
#ifndef NO_DEBUG
	std::cout << "\033[1D";
#endif
	std::cout <<" old(" << _var << ") new(" << input << ") "<< std::endl;
	_var = input;
}

// --------------------------------- Methods ------------------------------- //

