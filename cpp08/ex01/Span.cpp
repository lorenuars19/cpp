#include "Span.hpp"

// ----------------------------- Constructors ------------------------------ //
Span::Span() : size(0)
{
	_SPAN_AUTO(32, "Default Constructor");
}

Span::Span(const Span &c) : size(c.size)
{
	_SPAN_AUTO(32, "Copy Constructor");
	*this = c;
}

Span::Span(unsigned int span_siz) : size(span_siz)
{
	_SPAN_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Span::~Span()
{
	_SPAN_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Span &Span::operator=(const Span &c)
{
	_SPAN_AUTO(32, "Copy Assignement Operator");
	vec = c.vec;
	size = c.size;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

// --------------------------------- Methods ------------------------------- //

void Span::addNumber(int n)
{
	if (vec.size() >= size)
	{
		throw NoSpaceLeftException();
	}
	vec.push_back(n);
}

int Span::shortestSpan()
{
	check_valid_span();
	std::vector<int> tmp_vec(vec);
	std::vector<unsigned> min_span(vec.size());
	std::sort(tmp_vec.begin(), tmp_vec.end());
	std::adjacent_difference(tmp_vec.begin(), tmp_vec.end(), min_span.begin());
	return *(std::min_element(min_span.begin(), min_span.end()));
}

int Span::longestSpan()
{
	check_valid_span();
	std::vector<int>::iterator min;
	std::vector<int>::iterator max;
	min = std::min_element(vec.begin(), vec.end());
	max = std::max_element(vec.begin(), vec.end());
	return (*max - *min);
}

void Span::check_valid_span()
{
	if (vec.size() <= 1)
		throw InvalidSpanException();
}
