#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

class PhoneBook
{
	public:
// ----------------------------- Constructors ------------------------------ //
		PhoneBook( void );	// Default Constructor
		PhoneBook( int var );	// Fields Constructor
		PhoneBook( const PhoneBook &copy );	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
		~PhoneBook( void );	// Destructor

// ------------------------------- Operators ------------------------------- //
		PhoneBook & operator=( const PhoneBook &assign );
		// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //
		int		getVar( void ) const;
		void	setVar( int input );

// --------------------------------- Methods ------------------------------- //
		int		isEqual( PhoneBook t );

		// virtual void *inheritedMethod( void );
		// Virtual means using the inherited method : Polymorphism

private:
	int	_var;

};

#endif // TEMPLATE_HPP
