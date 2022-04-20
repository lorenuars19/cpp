#include "Karen.hpp"

// ----------------------------- Constructors ------------------------------ //
Karen::Karen(void)
{
}

Karen::Karen(const t &c)
{
	// _var = c.get_var();
	(void)c;
}

// Karen::Karen( int var ) : _var(var)
// {
// 	_KAREN_AUTO(32, "Fields Constructor");
// }

// ------------------------------ Destructor ------------------------------- //
Karen::~Karen(void)
{
}
// ------------------------------- Operators ------------------------------- //

Karen &Karen::operator=(const t &a)
{
	// _var = a.get_var();
	(void)a;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

// --------------------------------- Methods ------------------------------- //

void Karen::complain(std::string level)
{
	ptr_func funcs[4] = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error};

	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"};

	for (int i = 0; i <= 4; i++)
	{
		if (i == 4 && level != levels[i])
		{
			std::cerr << "Error: Invalid level" << std::endl;
			break;
		}
		if (level == levels[i])
		{
			(this->*(funcs[i]))();
			break;
		}
	}
}

void Karen::debug(void)
{
	std::cout << "\e[95m[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl
			  << "I really do !"
			  << "\e[0m" << std::endl;
}
void Karen::info(void)
{
	std::cout << "\e[94m[INFO] I cannot believe adding extra bacon costs more money." << std::endl
			  << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << "\e[0m" << std::endl;
}
void Karen::warning(void)
{
	std::cout << "\e[93m[WARNING] I think I deserve to have some extra bacon for free." << std::endl
			  << "I’ve been coming for years whereas you started working here since last month."
			  << "\e[0m" << std::endl;
}
void Karen::error(void)
{
	std::cout << "\e[91m[ERROR] This is unacceptable!" << std::endl
			  << "I want to speak to the manager now."
			  << "\e[0m" << std::endl;
}
