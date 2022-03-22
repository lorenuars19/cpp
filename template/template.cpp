#include "template.hpp"

# define _ARGS "Args : var " << _var
# define _AUTO(COLOR_CODE, TEXT) "\e[" << COLOR_CODE << ";1m" \
	<< "< " << TEXT << " " << __PRETTY_FUNCTION__ << " > " \
	<< "\e[0m" << _ARGS

// ----------------------------- Constructors ------------------------------ //
Template::Template( int input)
{
	_var = 0;
	std::cout << _AUTO(32, "Default Constructor")
		<< std::endl;
}

Template::Template( const Template &copy)
{
	_var = copy.getVar();
	std::cout << _AUTO(32, "Copy Constructor")
		<< std::endl;
}

Template::Template( int var)
{
	_var = var;
	std::cout << _AUTO(32, "Fields Constructor")
		<< std::endl;
}

// ------------------------------ Destructor ------------------------------- //
Template::~Template( void )
{
	std::cout << _AUTO(31, "Destructor called")
		<< std::endl;
}
// ------------------------------- Operators ------------------------------- //

Template & Template::operator=(const Template &assign)
{
	_var = assign.getVar();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
int	Template::getVar( void ) const
{
	std::cout << _AUTO(33, "Getter")
		<< std::endl;
	return _var;
}

void	Template::setVar( int input )
{
	std::cout << _AUTO(34, "Setter")
		<< " Old " << _var << " New " << input
		<< std::endl;
	_var = input;
}

// --------------------------------- Methods ------------------------------- //
int	Template::isEqual( Template t)
{
	if (this->getVar() == t.getVar())
	{
		return this->getVar();
	}
	return 0;
}
