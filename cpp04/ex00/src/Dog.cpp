#include "Dog.hpp"

// ----------------------------- Constructors ------------------------------ //
Dog::Dog( )
{
	var = 0;
	_DOG_AUTO(32, "Default Constructor");
}

Dog::Dog( const t& c )
{
	var = c.get_var();
	_DOG_AUTO(32, "Copy Constructor");
}

Dog::Dog( int input ) : var(input)
{
	_DOG_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Dog::~Dog( )
{
	_DOG_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Dog & Dog::operator=( const t& a )
{
	var = a.get_var();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
int	Dog::get_var( ) const
{
	_DOG_AUTO(33, "Getter");
	return var;
}

void	Dog::set_var( int input )
{
	_DOG_AUTO(34, "Setter");
#ifndef NO_DEBUG
	std::cout << "\033[1D";
#endif
	std::cout <<" old(" << var << ") new(" << input << ") "<< std::endl;
	var = input;
}

// --------------------------------- Methods ------------------------------- //

