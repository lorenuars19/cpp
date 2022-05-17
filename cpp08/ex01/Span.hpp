#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

class Span
{
public:
	class NoSpaceLeftException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "\e[31;1mError: No space left in Span\e[0m";
		}
	};
	class InvalidSpanException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "\e[31;1mError: Span is invalid for finding a span\e[0m";
		}
	};
	// ----------------------------- Constructors ------------------------------ //
	Span();						 // Default Constructor
	Span(unsigned int span_siz); // Fields Constructor
	Span(const Span &c);		 // Copy Constructor

	// ------------------------------ Destructor ------------------------------- //
	~Span(); // Destructor

	// ------------------------------- Operators ------------------------------- //
	Span &operator=(const Span &a);
	// Copy Assignement Operator

	// --------------------------- Getters && Setters -------------------------- //

	// --------------------------------- Methods ------------------------------- //
	void addNumber(int n);
	int shortestSpan();
	int longestSpan();

private:
	size_t size;
	std::vector<int> vec;

	void check_valid_span();
};

#ifndef NO_DEBUG

#ifndef _ARG
#define _ARG(arg) #arg << "(" << arg << ") "
#endif /* _ARG */

#define _SPAN_ARGS ""
#define _SPAN_AUTO(COLOR_CODE, TEXT)                            \
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \
			  << "[\033[34;47m" << this                         \
			  << "\033[0m]\033[0m: " << _SPAN_ARGS              \
			  << "}" << std::endl;
#else

#define _SPAN_AUTO(x, y) ;
#define _SPAN_ARGS ""
#define _ARG ""

#endif /* NO_DEBUG */

#endif /* SPAN_HPP */
