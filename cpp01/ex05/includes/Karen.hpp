#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>

class Karen
{
public:
	typedef Karen t;

	typedef void (Karen::*ptr_func)();

	// ----------------------------- Constructors ------------------------------ //
	Karen(); // Default Constructor
	// Karen( int var );	// Fields Constructor
	Karen(const t &c); // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~Karen(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	Karen &operator=(const t &a);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //

	// --------------------------------- Methods ------------------------------- //
	void complain(std::string level);

private:
	void debug();
	void info();
	void warning();
	void error();
};

#ifndef NO_DEBUG

#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif /* _ARG */

#define _KAREN_ARGS "[ARGS] "
#define _KAREN_AUTO(COLOR_CODE, TEXT) std::cout << "\e[" << COLOR_CODE << ";1m"                        \
												<< "< " << TEXT << " " << __PRETTY_FUNCTION__ << " > " \
												<< "\e[0m" << _KAREN_ARGS << std::endl;
#else

#define _KAREN_AUTO(x, y) ;
#define _KAREN_ARGS ""
#define _ARG ""

#endif /* NO_DEBUG */

#endif /* KAREN_HPP */
