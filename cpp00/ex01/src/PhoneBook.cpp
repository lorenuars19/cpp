#include "PhoneBook.hpp"
# include <iomanip>

// ----------------------------- Constructors ------------------------------ //
PhoneBook::PhoneBook( void ): cont_index(0)
{
	_AUTO(32, "Default Constructor");
}

// ------------------------------ Destructor ------------------------------- //
PhoneBook::~PhoneBook( void )
{
	_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

PhoneBook & PhoneBook::operator=( const PhoneBook &assign )
{
	cont_index = assign.cont_index;
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
// --------------------------------- Methods ------------------------------- //
int	PhoneBook::add_contact( void )
{
	std::string fname;
	std::string lname;
	std::string nick;
	std::string	phone;
	std::string secret;

	std::cout << std::endl << "--- ADD CONTACT ---" << std::endl;
	std::cout << "Enter contact's first name      : ";
	std::cin >> fname;
	std::cout << "Enter contact's last name       : ";
	std::cin >> lname;
	std::cout << "Enter contact's nick name       : ";
	std::cin >> nick;
	std::cout << "Enter contact's Phone Number    : ";
	std::cin >> phone;
	std::cout << "Enter contact's Darkest Secret  : ";
	std::cin >> secret;

	contacts[cont_index] = Contact(fname, lname, nick, phone, secret);
	cont_index++;
	if (cont_index >= N_CONTACTS)
	{
		cont_index = 0;
	}
	return 0;
}

void	PhoneBook::show_contacts( void ) const
{
	std::cout << " -------------------------------------------" << std::endl;
	for (int i = 0; i < N_CONTACTS ; i++)
	{
		std::cout << "|" << std::setw(10) << std::left << i + 1 <<
		std::setw(10) << contacts[i].get_oneline() << "|" << std::endl;
	}
	std::cout << " -------------------------------------------" << std::endl;
}

int	PhoneBook::search_contact( void ) const
{
	int			index;

	std::cout << "--- SEARCH CONTACTS ---" << std::endl;
	show_contacts();

	std::cout << "Enter the index of the contact you want to see : " << std::endl;
	std::cin.clear();
	while ( ! (std::cin >> index) || index < 0 || index > N_CONTACTS)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "Error : Invalid input, accepts only number 1-" << N_CONTACTS << std::endl;
		std::cin.clear();
	}
	std::cout << contacts[index].get_full(index) << std::endl;

	return 0;
}
