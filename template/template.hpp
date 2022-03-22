#ifndef _TEMPLATE_HPP_
# define _TEMPLATE_HPP_

# include <iostream>


class Template
{
public:
// -------------------------------- Public --------------------------------- //
	static void	*shared;	// static, means only one shared by all instances
// -------------------------------- Methods -------------------------------- //

	int		getVar( void );
	void	setVar( int input );
	int		isEqual( Template t );

// ---------------------- Constructors && Destructor ----------------------- //
	Template( int input );				// Simple Constructor
	Template( const Template &copy);	// Copy Constructor
	~Template( void );					// Destructor

private:
// -------------------------------- Private -------------------------------- //
	int	var;

protected:
// ------------------------------- Protected ------------------------------- //
};

#endif // _TEMPLATE_HPP_
