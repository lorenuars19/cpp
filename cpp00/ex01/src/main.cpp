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
	while (1)
	{
		std::cout << std::endl << "\033[2KEnter a command [ 'ADD' | 'SEARCH' | 'EXIT' ] : ";
		std::getline(std::cin, ans);

		if (ans == "ADD" || ans == "A" || ans == "a")
		{
			ph.add_contact();
		}
		else if (ans == "SEARCH" || ans == "S" || ans == "s")
		{
			if (ph.search_contact())
			{
				std::cerr << "Error : Invalid index" << std::endl;
			}
		}
		else if (ans == "EXIT" || ans == "E" || ans == "e")
		{
			std::cout << std::endl << "Exit" << std::endl;
			return 0;
		}
		else if (ans != "")
		{
			std::cout << "\033[2K"; // clear line
			std::cout << "Unrecognized command : please enter a valid command."<< std::endl;
			std::cout << "\033[3A";
		}
		else
		{
			std::cout << "\033[2A";
		}
	}
	return 0;
}
