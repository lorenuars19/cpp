#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>	 // rand(), srand()
#include <stddef.h>	 // size_t
#include <stdexcept> // std::out_of_range()

#include <iostream> // std::cout

template <class T>
class Array
{
private:
	T *arr;
	size_t len;

public:
	Array() : len(1)
	{
		std::cout << "Default Constructor called len(" << len << ") [" << this << "] " << __PRETTY_FUNCTION__ << std::endl;

		arr = new T[len];
	};

	Array(unsigned int n) : len(n)
	{
		std::cout << "Field Constructor called len(" << len << ") [" << this << "] " << __PRETTY_FUNCTION__ << std::endl;

		arr = new T[len];
	}

	~Array()
	{
		std::cout << "Destructor called len(" << len << ") [" << this << "] " << __PRETTY_FUNCTION__ << std::endl;

		delete[] arr;
	}

	Array(const Array &c)
	{
		std::cout << "Copy Constructor called len(" << len << ") [" << this << "] " << __PRETTY_FUNCTION__ << std::endl;

		*this = c;
	}

	Array &operator=(const Array &c) const
	{
		Array *new_arr = new Array(c);
		new_arr->arr = new T[len];
		for (size_t i = 0; i < len; i++)
		{
			new_arr->arr[i] = c.arr[i];
		}
		return (new_arr);
	}

	T &operator[](int in_index)
	{
		if (in_index < 0)
		{
			throw std::out_of_range("\e[31;1mError : index can't be negative\e[0m");
		}
		size_t index = (size_t)in_index;
		if (index >= len)
		{
			throw std::out_of_range("\e[31;1mError : index can't be bigger or equal than the array size\e[0m");
		}

		return arr[index];
	}

	size_t size()
	{
		return len;
	}
};

#endif
