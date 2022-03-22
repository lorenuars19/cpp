#include "template.hpp"

// ---------------------- Constructors && Destructor ----------------------- //
# define _ARGS << "Args : var " << var
# define _O_OPEN(COLOR_CODE) "\033[" << COLOR_CODE << "m" << "< "
# define _O_CLOSE "\033[0m" << " " << __PRETTY_FUNCTION__  << " > " _ARGS

Template::Template( int input) : var(input)
{
	std::cout << _O_OPEN(32) << "Simple Constructor" << _O_CLOSE
		<< std::endl;
}

Template::Template( const Template &copy) : var(copy.var)
{
	std::cout << _O_OPEN(32) << "Copy Constructor" << _O_CLOSE
		<< std::endl;
}

Template::~Template( void )
{
	std::cout << _O_OPEN(31) << "Destructor called" << _O_CLOSE
		<< std::endl;
}

// -------------------------------- Methods -------------------------------- //

int	Template::getVar( void )
{
	std::cout << _O_OPEN(33) << "Getter" << _O_CLOSE
		<< std::endl;
	return var;
}

void	Template::setVar( int input )
{
	std::cout << _O_OPEN(34)
		<< "Setter"
		<< _O_CLOSE
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
