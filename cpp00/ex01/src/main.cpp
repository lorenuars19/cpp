#include "FortyTwo.hpp"

int	main()
{
	PhoneBook de;
	PhoneBook ft(42);
	PhoneBook ft_1(ft);

	PhoneBook ft_2 = ft;

	ft.setVar(19);
	de.setVar(10);

	return 0;
}
