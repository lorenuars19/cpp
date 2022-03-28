#include "PhoneBook.hpp"
# include <iomanip>
# include <iostream>



int	main()
{
	PhoneBook	ph;

	std::string	ans = "";

	std::cout << "\ec";
	std::cout << "******************************************************************************" << std::endl;
	std::cout << "*                       Welcome to my Awesome PhoneBook                      *" << std::endl;
	std::cout << "******************************************************************************" << std::endl;
	while (ans.compare("EXIT") != 0 && ans.compare("E") != 0 &&
		ans.compare("exit") != 0 && ans.compare("e") != 0 &&
		ans.compare("Exit") != 0)
	{

		std::cout << "Enter a command (Add | Search | Exit) : ";
		std::cin >> ans;
		if (std::cin.eof())
			break;
		if (ans.compare("ADD") == 0 || ans.compare("A") == 0 ||
			ans.compare("a") == 0 || ans.compare("add") == 0 ||
			ans.compare("Add") == 0)
		{
			ph.add_contact();
		}
		else if (ans.compare("SEARCH") == 0 || ans.compare("S") == 0 ||
				ans.compare("search") == 0 || ans.compare("s") == 0 ||
				ans.compare("Search") == 0)
		{
			if (ph.search_contact())
			{
				std::cerr << "Error : Invalid index" << std::endl;
			}
		}
	}
	std::cout << std::endl << "Exit" << std::endl;
	return 0;
}
