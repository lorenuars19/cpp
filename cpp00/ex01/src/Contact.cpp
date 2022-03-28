#include "Contact.hpp"

#include <sstream>
// ----------------------------- Constructors ------------------------------ //
Contact::Contact( void )
{
	_AUTO(32, "Default Constructor");
}

Contact::Contact( const Contact& copy ) :
first_name(copy.first_name),
last_name(copy.last_name),
nick_name(copy.nick_name)
{
	_AUTO(32, "Copy Constructor");
}

Contact::Contact(std::string fname, std::string lname, std::string nick,
				std::string phone, std::string secret) :
first_name(fname),
last_name(lname),
nick_name(nick),
phone_number(phone),
darkest_secret(secret)
{
	_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
Contact::~Contact( void )
{
	_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Contact & Contact::operator=( const Contact& assign )
{
	first_name = assign.first_name;
	last_name = assign.last_name;
	nick_name = assign.nick_name;
	phone_number = assign.phone_number;
	darkest_secret = assign.darkest_secret;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
// --------------------------------- Methods ------------------------------- //

std::string	Contact::truncate(std::string str, size_t len) const
{
	if (str.length() > len)
	{
		str.resize(len - 1);
		str.append(".");
	}
	else
	{
		if (str.length() < len)
		{
			for (int a  = len - str.length(); a > 0; a--)
			{
				str.append(" ");
			}
		}
		str.resize(len);
	}
	return str;
}

std::string Contact::get_oneline( void ) const
{
	return ("|" + truncate(first_name, 10) + "|" +
			truncate(last_name, 10) + "|" +
			truncate(nick_name, 10));
}

std::string Contact::get_full( int index ) const
{
	std::stringstream ss;

	ss << "--- Contact " << index << " ---" << std::endl
		<< "First Name     : " << first_name << std::endl
		<< "Last Name      : " << last_name << std::endl
		<< "Nick Name      : " << nick_name << std::endl
		<< "Phone Number   : " << phone_number << std::endl
		<< "Darkest Secret : " << darkest_secret << std::endl;

	return ss.str();
}
