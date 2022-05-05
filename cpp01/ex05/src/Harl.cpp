#include "Harl.hpp"

// ----------------------------- Constructors ------------------------------ //
Harl::Harl()
{
}

Harl::Harl(const t &c) { (void)c; }

// ------------------------------ Destructor ------------------------------- //
Harl::~Harl() {}
// ------------------------------- Operators ------------------------------- //

Harl &Harl::operator=(const t &a)
{
	(void)a;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //

// --------------------------------- Methods ------------------------------- //

void Harl::complain(std::string level)
{
	ptr_func funcs[4] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};

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

void Harl::debug()
{
	std::cout << "\e[95m[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl
			  << "I really do !"
			  << "\e[0m" << std::endl;
}
void Harl::info()
{
	std::cout << "\e[94m[INFO] I cannot believe adding extra bacon costs more money." << std::endl
			  << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << "\e[0m" << std::endl;
}
void Harl::warning()
{
	std::cout << "\e[93m[WARNING] I think I deserve to have some extra bacon for free." << std::endl
			  << "I’ve been coming for years whereas you started working here since last month."
			  << "\e[0m" << std::endl;
}
void Harl::error()
{
	std::cout << "\e[91m[ERROR] This is unacceptable!" << std::endl
			  << "I want to speak to the manager now."
			  << "\e[0m" << std::endl;
}
