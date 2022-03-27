#ifndef FORTYTWO_HPP
# define FORTYTWO_HPP

# include <iostream>

class FortyTwo
{
	public:
// ----------------------------- Constructors ------------------------------ //
		FortyTwo( void );	// Default Constructor
		FortyTwo( int var );	// Fields Constructor
		FortyTwo( const FortyTwo& copy );	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
		~FortyTwo( void );	// Destructor

// ------------------------------- Operators ------------------------------- //
		FortyTwo & operator=( const FortyTwo& assign );
		// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //
		int		get_var( void ) const;
		void	set_var( int input );

// --------------------------------- Methods ------------------------------- //
		int		isEqual( FortyTwo t );

		// virtual void *inheritedMethod( void );
		// Virtual means using the inherited method : Polymorphism

private:
	int	_var;

};

#endif // TEMPLATE_HPP
