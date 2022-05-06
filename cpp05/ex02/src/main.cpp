#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
		ShrubberyCreationForm form("Magratea");
		Bureaucrat bob("Bob", 145);

		std::cout << "Form: " << form << " Bureaucrat: " << bob << std::endl;

		bob.signForm(form);
		bob.signForm(form);
		std::cout << " Bureaucrat: " << bob << std::endl;
		bob.decrement_grade();
		std::cout << " Bureaucrat: " << bob << std::endl;
		bob.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}

	return (0);
}
