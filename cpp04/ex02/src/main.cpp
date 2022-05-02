#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	// Animal a;
	// should not compile
	{
		const Animal *a = new Cat();
		std::cout << "\n";
		Cat b;
		std::cout << "\n";
		Cat c(*dynamic_cast<const Cat *>(a));
		Cat d(b);
		std::cout << "\n";

		std::cout << "A.brain " << &(((Cat *)a)->get_brain())
				  << " b.brain " << &(b.get_brain())
				  << " d.brain " << &(d.get_brain())
				  << std::endl;

		delete a;
	}
	{
		const Animal *a = new Dog();
		std::cout << "\n";
		Dog b;
		std::cout << "\n";
		// Dog c(a);
		Dog d(b);
		std::cout << "\n";

		std::cout << "A.brain " << &(((Dog *)a)->get_brain())
				  << " b.brain " << &(b.get_brain())
				  << " d.brain " << &(d.get_brain())
				  << std::endl;

		delete a;
	}

	return 0;
}
