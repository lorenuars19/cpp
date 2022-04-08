#include "HumanA.hpp"

// ----------------------------- Constructors ------------------------------ //
HumanA::HumanA(void)
{
	_name = 0;
	_AUTO(32, "Default Constructor") << std::endl;
}

HumanA::HumanA(const HumanA &copy)
{
	_name = copy.get_name();
	_AUTO(32, "Copy Constructor") << std::endl;
}

HumanA::HumanA(std::string name, Weapon w) : _name(name)
{
	_AUTO(32, "Fields Constructor") << std::endl;
}

// ------------------------------ Destructor ------------------------------- //
HumanA::~HumanA(void)
{
	_AUTO(31, "Destructor called") << std::endl;
}
// ------------------------------- Operators ------------------------------- //

HumanA &HumanA::operator=(const HumanA &assign)
{
	_name = assign.get_name();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
int HumanA::get_name(void) const
{
	_AUTO(33, "Getter") << std::endl;
	return _name;
}

void HumanA::set_name(int input)
{
	_AUTO(34, "Setter") << " Old " << _name << " New " << input << std::endl;
	_name = input;
}

// --------------------------------- Methods ------------------------------- //
int HumanA::is_equal(const HumanA comp)
{
	if (this->get_name() == comp.get_name())
	{
		return this->get_name();
	}
	return 0;
}
