#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <iostream>

class Template
{
	public:
// ----------------------------- Constructors ------------------------------ //
		Template( int input );							// Simple Constructor
		Template( const Template &copy);				// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
		~Template( void );								// Destructor

// ------------------------------- Operators ------------------------------- //
		Template & operator=(const Template &assign);
		// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //
		int		getVar( void ) const;
		void	setVar( int input );

// --------------------------------- Methods ------------------------------- //
		int		isEqual( Template t );

private:
	int	_var;

};

#endif // TEMPLATE_HPP
