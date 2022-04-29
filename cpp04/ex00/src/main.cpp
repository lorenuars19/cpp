#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << i->get_type() << " " << std::endl;
	std::cout << j->get_type() << " " << std::endl;

	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	return 0;
}
