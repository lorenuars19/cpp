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
		return "\e[31;1mError: Item not found\e[0m";
	}
};

template <class T>
typename T::iterator easyfind(T &cont, int num)
{
	for (typename T::iterator it = cont.begin();
		 it != cont.end(); ++it)
	{
		if (*it == num)
		{
			return (it);
		}
	}
	throw ItemNotFoundException();
}

#endif
