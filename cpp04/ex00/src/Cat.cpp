#include "Cat.hpp"

// ----------------------------- Constructors ------------------------------ //
Cat::Cat( )
{
	var = 0;
	_CAT_AUTO(32, "Default Constructor");
}

Cat::Cat( const t& c )
{
	var = c.get_var();
	_CAT_AUTO(32, "Copy Constructor");
}

Cat::Cat( int input ) : var(input)
{
	_CAT_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Cat::~Cat( )
{
	_CAT_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Cat & Cat::operator=( const t& a )
{
	var = a.get_var();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
int	Cat::get_var( ) const
{
	_CAT_AUTO(33, "Getter");
	return var;
}

void	Cat::set_var( int input )
{
	_CAT_AUTO(34, "Setter");
#ifndef NO_DEBUG
	std::cout << "\033[1D";
#endif
	std::cout <<" old(" << var << ") new(" << input << ") "<< std::endl;
	var = input;
}

// --------------------------------- Methods ------------------------------- //

