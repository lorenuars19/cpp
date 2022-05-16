#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
	std::vector<int> vec;
	std::vector<int>::iterator vec_it;

	std::cout << "\nstd::vector<int> :\n";

	for (int i = 0; i < 6; i += 2)
	{
		vec.push_back(i);
		std::cout << " vec.push_back(" << i << ");\n";
	}
	std::cout << "\neasyfind(vec, 5) :\n";
	try
	{
		vec_it = easyfind(vec, 5);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\neasyfind(vec, 4) :\n";

	vec_it = easyfind(vec, 4);
	std::cout << "vec_it : " << *vec_it << '\n';

	std::list<int> lst;
	std::list<int>::iterator lst_it;

	std::cout << "\nstd::list<int> :\n";
	for (int i = 0; i < 6; i += 2)
	{
		lst.push_back(i);
		std::cout << " lst.push_back(" << i << ");\n";
	}
	std::cout << "\neasyfind(lst, 5) :\n";
	try
	{
		lst_it = easyfind(lst, 5);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\neasyfind(lst, 4) :\n";

	lst_it = easyfind(lst, 4);
	std::cout << "lst_it : " << *lst_it << '\n';
}
