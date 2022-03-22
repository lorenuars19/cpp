#include "template.hpp"

// ---------------------- Constructors && Destructor ----------------------- //
# define _ARGS "Args : var " << var
# define _AUTO(COLOR_CODE, TEXT) "\033[" << COLOR_CODE << ";1m" \
	<< "< " << TEXT << " " << __PRETTY_FUNCTION__ << " > " \
	<< "\033[0m" << _ARGS

Template::Template( int input) : var(input)
{
	std::cout << _AUTO(32, "Simple Constructor")
		<< std::endl;
}

Template::Template( const Template &copy) : var(copy.var)
{
	std::cout << _AUTO(32, "Copy Constructor")
		<< std::endl;
}

Template::~Template( void )
{
	std::cout << _AUTO(31, "Destructor called")
		<< std::endl;
}

// -------------------------------- Methods -------------------------------- //

int	Template::getVar( void )
{
	std::cout << _AUTO(33, "Getter")
		<< std::endl;
	return var;
}

void	Template::setVar( int input )
{
	std::cout << _AUTO(34, "Setter")
		<< " Old " << var << " New " << input
		<< std::endl;
	var = input;
}

int	Template::isEqual( Template t)
{
	if (this->getVar() == t.getVar())
	{
		return this->getVar();
	}
	return 0;
}
