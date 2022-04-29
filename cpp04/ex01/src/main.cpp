#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	{
		const Animal *a = new Cat();
		Cat b;
		// Cat c((Cat &)a);
		Cat d(b);

		std::cout << "A.type " << &(((Cat *)a)->get_brain())
				  << " b.brain " << &(b.get_brain())
				  << " d.brain " << &(d.get_brain())
				  << std::endl;

		delete a;
	}
	{
		const Animal *a = new Dog();
		Dog b;
		// Dog c(a);
		Dog d(b);

		delete a;
	}

	return 0;
}
