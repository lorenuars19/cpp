#include "HumanA.hpp"

// ----------------------------- Constructors ------------------------------ //
HumanA::HumanA(void)
{
	_type = 0;
	_AUTO(32, "Default Constructor") << std::endl;
}

HumanA::HumanA(const HumanA &copy)
{
	_type = copy.get_type();
	_AUTO(32, "Copy Constructor") << std::endl;
}

HumanA::HumanA(int type) : _type(type)
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
	_type = assign.get_type();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
int HumanA::get_type(void) const
{
	_AUTO(33, "Getter") << std::endl;
	return _type;
}

void HumanA::set_type(int input)
{
	_AUTO(34, "Setter") << " Old " << _type << " New " << input << std::endl;
	_type = input;
}

// --------------------------------- Methods ------------------------------- //
int HumanA::is_equal(const HumanA comp)
{
	if (this->get_type() == comp.get_type())
	{
		return this->get_type();
	}
	return 0;
}
