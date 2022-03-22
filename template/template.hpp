#ifndef _TEMPLATE_HPP_
# define _TEMPLATE_HPP_

# include <iostream>


class Template
{
public:
// -------------------------------- Public --------------------------------- //

	int	var;
// -------------------------------- Methods -------------------------------- //

	int		getVar( void );
	void	setVar( int input );

// ---------------------- Constructors && Destructor ----------------------- //
	Template( int input );				// Simple Constructor
	Template( const Template &copy);	// Copy Constructor
	~Template( void );					// Destructor

private:
// -------------------------------- Private -------------------------------- //
protected:
// ------------------------------- Protected ------------------------------- //
};

#endif // _TEMPLATE_HPP_
