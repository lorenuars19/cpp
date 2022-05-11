
#include "Base.hpp"

Base *generate()
{
	int choice = rand() % 3;

	switch (choice)
	{
	case 0:
		return new A;
		break;
	case 1:
		return new B;
		break;
	case 2:
		return new C;
		break;
	default:
		return NULL;
		break;
	}
	return NULL;
}

void identify(Base *p)
{
	std::cout << "Type *: ";
	if (dynamic_cast<A *>(p))
	{
		std::cout << "Base::A";
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "Base::B";
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "Base::C";
	}
	else
	{
		std::cout << "Not a derived class from Base";
	}
	std::cout << std::endl;
}

void identify(Base &p)
{
	std::cout << "Type &: ";
	if (dynamic_cast<A *>(&p))
	{
		std::cout << "Base::A";
	}
	else if (dynamic_cast<B *>(&p))
	{
		std::cout << "Base::B";
	}
	else if (dynamic_cast<C *>(&p))
	{
		std::cout << "Base::C";
	}
	else
	{
		std::cout << "Not a derived class from Base";
	}
	std::cout << std::endl;
}

int main()
{
	srand(time(0));

	Base x;

	identify(&x);
	identify(x);
	std::cout << "-------------------------\n";

	for (int i = 0; i < 5; i++)
	{
		Base *test;
		test = generate();
		identify(test);
		delete test;
	}
	std::cout << "-------------------------\n";

	for (int i = 0; i < 5; i++)
	{
		Base *test;
		test = generate();
		identify(*test);
		delete test;
	}
}
