#include "HumanB.hpp"

// ----------------------------- Constructors ------------------------------ //
HumanB::HumanB(void)
{
	_type = 0;
	_AUTO(32, "Default Constructor") << std::endl;
}

HumanB::HumanB(const HumanB &copy)
{
	_type = copy.get_type();
	_AUTO(32, "Copy Constructor") << std::endl;
}

HumanB::HumanB(int type) : _type(type)
{
	_AUTO(32, "Fields Constructor") << std::endl;
}

// ------------------------------ Destructor ------------------------------- //
HumanB::~HumanB(void)
{
	_AUTO(31, "Destructor called") << std::endl;
}
// ------------------------------- Operators ------------------------------- //

HumanB &HumanB::operator=(const HumanB &assign)
{
	_type = assign.get_type();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
int HumanB::get_type(void) const
{
	_AUTO(33, "Getter") << std::endl;
	return _type;
}

void HumanB::set_type(int input)
{
	_AUTO(34, "Setter") << " Old " << _type << " New " << input << std::endl;
	_type = input;
}

// --------------------------------- Methods ------------------------------- //
int HumanB::is_equal(const HumanB comp)
{
	if (this->get_type() == comp.get_type())
	{
		return this->get_type();
	}
	return 0;
}
