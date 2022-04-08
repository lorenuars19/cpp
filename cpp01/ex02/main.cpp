#include <string>
#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";

	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Address of string               : " << &string << std::endl
			  << "Address of Pointer to string    : " << stringPTR << std::endl
			  << "Address of Reference to string  : " << &stringREF << std::endl
			  << std::endl;

	std::cout << "Value of string               : " << string << std::endl
			  << "Value of Pointer to string    : " << *stringPTR << std::endl
			  << "Value of Reference to string  : " << stringREF << std::endl
			  << std::endl;

	return 0;
}
