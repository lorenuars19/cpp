#ifndef FORTYTWO_HPP
#define FORTYTWO_HPP

#include <iostream>

class FortyTwo
{
public:
	int flag;

	// ----------------------------- Constructors ------------------------------ //
	FortyTwo();																												  // Default Constructor
	FortyTwo(std::string in_name, std::string in_firstName, std::string in_lastName, std::string in_middleName, int in_flag); // Fields Constructor
	FortyTwo(const FortyTwo &c);																							  // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~FortyTwo(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	FortyTwo &operator=(const FortyTwo &a);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //
	std::string get_name() const;
	std::string set_name(std::string input);

	std::string get_firstName() const;
	std::string set_firstName(std::string input);

	std::string get_lastName() const;
	std::string set_lastName(std::string input);

	std::string get_middleName() const;
	std::string set_middleName(std::string input);

	int get_flag() const;
	int set_flag(int input);

	// --------------------------------- Methods ------------------------------- //
	int is_equal(const FortyTwo comp);

private:
	std::string name;
	std::string firstName;
	std::string lastName;
	std::string middleName;
};

#ifndef NO_DEBUG

#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif /* _ARG */

#define _FORTYTWO_ARGS _ARG(name) << _ARG(firstName) << _ARG(lastName) << _ARG(middleName) << _ARG(flag)
#define _FORTYTWO_AUTO(COLOR_CODE, TEXT)                        \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _FORTYTWO_ARGS          \
			  << "}" << std::endl;
#else

#define _FORTYTWO_AUTO(x, y) ;
#define _FORTYTWO_ARGS ""
#define _ARG ""

#endif /* NO_DEBUG */

#endif /* FORTYTWO_HPP */
