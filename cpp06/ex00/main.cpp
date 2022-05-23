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

	int i;
	char c;
	float f;
	double d;

	{
		std::stringstream conv(input);
		conv >> c;
	}
	{
		std::stringstream conv(input);
		conv >> i;
	}
	{
		std::stringstream conv(input);
		conv >> f;
	}
	{
		std::stringstream conv(input);
		conv >> d;
	}

	std::cout << ""
			  << " char   : " << c << '\n'
			  << " int    : " << i << '\n'
			  << " float  : " << f << '\n'
			  << " double : " << d << '\n'
			  << "\n";

	return (0);
}
