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

	{
		ShrubberyCreationForm form("Magratea");
		Bureaucrat bob("Bob", 145);

		std::cout << "Form: " << form << "\nBureaucrat: " << bob << std::endl;

		bob.signForm(form);
		for (int i = 0; i < 8; i++)
		{
			bob.increment_grade();
		}
		std::cout << "Bureaucrat: " << bob << std::endl;
		bob.executeForm(form);
		bob.decrement_grade();
		bob.executeForm(form);
	}

	{
		RobotomyRequestForm form("Bender");
		Bureaucrat bob("Bob", 72);

		bob.signForm(form);
		for (int i = 0; i < 27; i++)
		{
			bob.increment_grade();
		}
		std::cout << "Bureaucrat: " << bob << std::endl;
		for (int i = 0; i < 5; i++)
		{
			bob.executeForm(form);
		}
		bob.decrement_grade();
		bob.executeForm(form);
	}

	{
		PresidentialPardonForm form("Alice");
		Bureaucrat bob("Bob", 25);

		std::cout << "Form: " << form << "\nBureaucrat: " << bob << std::endl;

		bob.signForm(form);
		for (int i = 0; i < 20; i++)
		{
			bob.increment_grade();
		}
		std::cout << "Bureaucrat: " << bob << std::endl;
		bob.executeForm(form);
		bob.decrement_grade();
		bob.executeForm(form);
	}

	return (0);
}
