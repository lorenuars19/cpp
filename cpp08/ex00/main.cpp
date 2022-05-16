#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vi;

	for (int i = 0; i < 50; i += 2)
	{
		vi.push_back(i);
	}

	int ret;

	try
	{
		ret = easyfind(vi, 41);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	ret = easyfind(vi, 42);
	std::cout << "ret : " << ret << '\n';
}
