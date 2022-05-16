#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <list>
#include <vector>

class ItemNotFoundException : public std::exception
{
public:
	const char *what() const throw()
	{
		return "\e[31;1mError: Item not found\e[0m\n";
	}
};

template <class T>
int &easyfind(const T &cont, int num)
{
	for (std::iterator<std::input_iterator_tag, T> it = cont.begin();
		 it != cont.end();
		 std::advance(it, 1))
	{
		std::cout << "it :" << *it << '\n';
		// if (it == num)
		// {
		// 	return (&num);
		// }
	}
	throw ItemNotFoundException();
}

#endif
