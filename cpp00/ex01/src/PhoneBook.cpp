#include "PhoneBook.hpp"
#include <iomanip>

// ----------------------------- Constructors ------------------------------ //
PhoneBook::PhoneBook() : cont_index(0)
{
	_AUTO(32, "Default Constructor");
}

// ------------------------------ Destructor ------------------------------- //
PhoneBook::~PhoneBook()
{
	_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

PhoneBook &PhoneBook::operator=(const PhoneBook &assign)
{
	cont_index = assign.cont_index;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
// --------------------------------- Methods ------------------------------- //
int PhoneBook::add_contact()
{
	std::string fname;
	std::string lname;
	std::string nick;
	std::string phone;
	std::string secret;

	std::cout << std::endl
			  << "--- ADD CONTACT ---" << std::endl;
	std::cout << "Enter contact's first name      : ";
	std::getline(std::cin, fname);
	std::cout << "Enter contact's last name       : ";
	std::getline(std::cin, lname);
	std::cout << "Enter contact's nick name       : ";
	std::getline(std::cin, nick);
	std::cout << "Enter contact's Phone Number    : ";
	std::getline(std::cin, phone);
	std::cout << "Enter contact's Darkest Secret  : ";
	std::getline(std::cin, secret);

	contacts[cont_index] = Contact(fname, lname, nick, phone, secret);
	cont_index++;
	if (cont_index >= N_CONTACTS)
	{
		cont_index = 0;
	}
	return 0;
}

void PhoneBook::show_contacts() const
{
	std::cout << " -------------------------------------------" << std::endl;
	for (int i = 0; i < N_CONTACTS; i++)
	{
		std::cout << "|" << std::setw(10) << std::left << i + 1 << std::setw(10) << contacts[i].get_oneline() << "|" << std::endl;
	}
	std::cout << " -------------------------------------------" << std::endl;
}

int PhoneBook::search_contact() const
{
	int index;

	std::cout << "--- SEARCH CONTACTS ---" << std::endl;
	show_contacts();

	index = -1;
	while (index < 0 || index > N_CONTACTS)
	{
		std::cout << "\033[2KEnter the index of the contact you want to see : ";
		try
		{
			std::string str;
			std::getline(std::cin, str);
			index = std::stoi(str);
		}
		catch (std::invalid_argument e)
		{
			// nothing
		}
		if (index < 0 || index > N_CONTACTS)
		{
			std::cerr << "\033[2KInvalid input, accepts only number 1-" << N_CONTACTS << std::endl;
		}
		std::cout << "\033[2A";
	}
	std::cout << "\033[4B";
	std::cout << contacts[index - 1].get_full(index) << std::endl;
	return 0;
}
