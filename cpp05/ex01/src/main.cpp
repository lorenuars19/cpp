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

		std::cout << "Form: " << form << " Bureaucrat: " << bob << std::endl;

		bob.signForm(form);
		bob.signForm(form);
		std::cout << "Form: " << form << " Bureaucrat: " << bob << std::endl;
		bob.decrement_grade();
		std::cout << "Form: " << form << " Bureaucrat: " << bob << std::endl;
		std::cout << "Form: " << form2 << " Bureaucrat: " << bob << std::endl;
		bob.signForm(form2);
		std::cout << "Form: " << form2 << " Bureaucrat: " << bob << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}

	return (0);
}
