#include "Span.hpp"

#include <array>

int main()
{
	Span sp = Span(5);


	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}


	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(42);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	Span spi(100);
	std::array<int, 100> arr;
	arr.fill(42);
	arr[42] = -42;

	spi.addNumber(arr.begin(), arr.end());
	std::cout << spi.shortestSpan() << std::endl;
	std::cout << spi.longestSpan() << std::endl;

}
