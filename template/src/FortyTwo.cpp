#include "FortyTwo.hpp"

// ----------------------------- Constructors ------------------------------ //
FortyTwo::FortyTwo()
{
	var = 0;
	_FORTYTWO_AUTO(32, "Default Constructor");
}

FortyTwo::FortyTwo(const FortyTwo &c)
{
	_FORTYTWO_AUTO(32, "Copy Constructor");
	name = c.get_name;
	firstName = c.get_firstName;
	lastName = c.get_lastName;
	middleName = c.get_middleName;
	flag = c.get_flag;
}

FortyTwo::FortyTwo(std::string in_name, std::string in_firstName, std::string in_lastName, std::string in_middleName, int in_flag) : name(in_name), firstName(in_firstName), lastName(in_lastName), middleName(in_middleName), flag(in_flag)
{
	_FORTYTWO_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
FortyTwo::~FortyTwo()
{
	_FORTYTWO_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

FortyTwo &FortyTwo::operator=(const FortyTwo &c)
{
	name = c.get_name;
	firstName = c.get_firstName;
	lastName = c.get_lastName;
	middleName = c.get_middleName;
	flag = c.get_flag;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
std::string FortyTwo::get_name() const;
{
	return name;
}
std::string FortyTwo::set_name(std::string input);
{
	name = input;
}
std::string FortyTwo::get_firstName() const;
{
	return firstName;
}
std::string FortyTwo::set_firstName(std::string input);
{
	firstName = input;
}
std::string FortyTwo::get_lastName() const;
{
	return lastName;
}
std::string FortyTwo::set_lastName(std::string input);
{
	lastName = input;
}
std::string FortyTwo::get_middleName() const;
{
	return middleName;
}
std::string FortyTwo::set_middleName(std::string input);
{
	middleName = input;
}
int FortyTwo::get_flag() const;
{
	return flag;
}
int FortyTwo::set_flag(int input);
{
	flag = input;
}

// --------------------------------- Methods ------------------------------- //
