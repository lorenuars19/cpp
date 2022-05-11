#include "convert.hpp"

int charset_in_string(std::string set, std::string str)
{
	for (std::string::iterator it = set.begin(); it != set.end(); ++it)
	{
		if (str.find(*it) != std::string::npos)
		{
			return (1);
		}
	}
	return (0);
}

int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		return (1);
	}

	std::string input = argv[1];

	char typ = TYP_DEFAULT;
	if (charset_in_string(SET_INT, input) && typ == TYP_DEFAULT)
	{
		typ = TYP_INT;
	}
	if ((charset_in_string(".", input) && typ == TYP_INT) ||
		input.find("nan") != std::string::npos ||
		input.find("-inf") != std::string::npos ||
		input.find("+inf") != std::string::npos)
	{
		typ = TYP_DOUBLE;
	}
	if ((charset_in_string("f", input) && typ == TYP_DOUBLE) ||
		input.find("nanf") != std::string::npos ||
		input.find("-inff") != std::string::npos ||
		input.find("+inff") != std::string::npos)
	{
		typ = TYP_FLOAT;
	}

	std::cout << "typ " << typ << std::endl;

	char c;
	int i;
	float f;
	double d;

	d = std::atof(input.c_str());
	f = static_cast<float>(d);
	i = std::atoi(input.c_str());
	c = static_cast<char>(i);
	if (typ == TYP_DEFAULT)
	{
		c = input[0];
		i = static_cast<int>(c);
		d = static_cast<int>(c);
		f = static_cast<int>(c);
	}

	std::cout << "char : ";

	if (
		(typ == TYP_FLOAT && (f == std::numeric_limits<float>::infinity() ||
							  f == -std::numeric_limits<float>::infinity())) ||
		(typ == TYP_DOUBLE && (d == std::numeric_limits<double>::infinity() ||
							   d == -std::numeric_limits<double>::infinity())))
	{
		std::cout << "impossible";
	}
	else if (c < ' ')
	{
		std::cout << "Non displayable";
	}
	else
	{
		std::cout << c;
	}
	std::cout << std::endl;

	std::cout << "int : ";
	if (
		(typ == TYP_FLOAT && (f == std::numeric_limits<float>::infinity() ||
							  f == -std::numeric_limits<float>::infinity())) ||
		(typ == TYP_DOUBLE && (d == std::numeric_limits<double>::infinity() ||
							   d == -std::numeric_limits<double>::infinity())))
	{
		std::cout << "impossible";
	}
	else
	{
		std::cout << i;
	}
	std::cout << std::endl;
	std::cout << "float : " << f << std::endl;
	std::cout << "double : " << d << std::endl;

	return (0);
}
