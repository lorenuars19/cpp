#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
public:
	typedef Cat t;
	// ----------------------------- Constructors ------------------------------ //
	Cat();			 // Default Constructor
	Cat(int var);	 // Fields Constructor
	Cat(const t &c); // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~Cat(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	Cat &operator=(const t &a);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	int get_var() const;
	void set_var(int input);

	// --------------------------------- Methods ------------------------------- //
	int is_equal(const Cat comp);

private:
	int var;
};

#ifndef NO_DEBUG

#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif /* _ARG */

#define _CAT_ARGS _ARG(var)
#define _CAT_AUTO(COLOR_CODE, TEXT)                             \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _CAT_ARGS               \
			  << "}" << std::endl;
#else

#define _CAT_AUTO(x, y) ;
#define _CAT_ARGS ""
#define _ARG ""

#endif /* NO_DEBUG */

#endif /* CAT_HPP */
