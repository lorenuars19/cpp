#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat foo("bob", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat foo("bob", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat bar("John", 3);

	std::cout << bar << std::endl;

	try
	{
		for (int i = 0; i < 4; i++)
		{
			bar.increment_grade();
			std::cout << bar << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form form("Form", 42, 42);
		Form form2("Form2", 42, 42);
		Bureaucrat bob("Bob", 42);

		std::cout << form << '\n'
				  << bob << '\n';

		bob.signForm(form);
		std::cout << form << '\n'
				  << bob << '\n';
		bob.signForm(form);
		std::cout << form << '\n'
				  << bob << '\n';
		bob.decrement_grade();
		std::cout << form << '\n'
				  << bob << '\n';
		std::cout << form2 << '\n'
				  << bob << '\n';
		bob.signForm(form2);
		std::cout << form2 << '\n'
				  << bob << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
